#pragma once
#include "motion.h"
#include "graphics.h"

//Data used for projectiles
//Setup:
//const Motion* motion, float radius, char damage, char num, float spread, char type
struct ProjectileData
{
	const Motion* motion; //Motion of this projectile
	float radius = 0.f; //Radius of any circular motion
	char baseDamage = 0; //Base damage of the projectile
	char num = 0; //Number of projectiles in this attack
	float spread = 0.f; //How far apart the extra projectiles are spread, from the initial angle, in degrees
	char type = 0; //What type of projectile is spawned (0 is the weapon, 1 is fire skull, 2 is fire ball)
};

//Projectile
struct Projectile
{
	//Setup stats
	Motion motion{};

	//Setup bools
	bool followingFacing = true; //If the projectile is actively following the entity facing

	//Operational bools
	bool active = false; //If the projectile is currently active
	bool playerProjectile = false; //If it is a player or enemy projectile

	//Operational stats
	char enemyID = -1;

	//Positioning
	Dim2Df origin = { 0.f, 0.f };
	float angle = 0.f;

	//Structs
	ProjectileData data{};
	Animation anim{};

	//Functional variables
	sf::Sprite sprite{};

	//Updates the projectile
	void Update(const GameData& game);

	//Renders the projectile
	void Render(sf::RenderWindow& window);

	//Returns a vector of movement for this frame
	Dim2Df GetFrameMovementVector(const GameData& game);
};

//Attack
struct Attack //Setup: {motion0, motion1}, ProjectileData*, AnimationData*, int soundID, int range, various bools
{
	//Setup stats
	Motion motions[GC::MAX_MOTIONS]; //Attack motions
	const ProjectileData* projectileData = nullptr; //Data of this attack's projectile
	const AnimationData* animData{}; //Data of this attack's animation
	int soundID = -1; //ID of the sound to be played on a damaging motion
	int range = 0; //Attack range, in pixels (0 means default weapon range, -1 means unlimited)

	//Setup bools
	bool summonProjectile = false; //If this attack summons a projectile after the motion has finished
	bool movingWithEntity = false; //If this motion is moving with the entity
	bool followingFacing = false; //If the weapon attack is actively following the entity's facing (not projectiles)
	bool hasTwoMotions = false; //If this is the first of two motions
	bool arcCentredOnInitialAngle = false; //If this attack is centred on the initial angle
	bool alternatingSwingDirection = false; //If this attack's inital position and direction changes on each swing
	bool hasSound = false; //If this attack plays a sound on the damaging motion
	bool uniqueAnimation = false; //If the attack has a unique animation to play
	bool animOnMotion0 = false; //If the animation occurs on first motion
	bool animOnMotion1 = false; //If the animation occurs on second motion

	//Operational bools
	bool active = false; //If attack is active
	bool attackRelease = false; //If second motion should begin
	bool motionFinished = false; //If all motions for this attack are finished
	bool entityIsWeapon = false; //If the entity sprite is the attacking object
	bool animStarted = false; //Has the animation been initiated
	bool projectileShotByPlayer = false; //If the spawned projectile is being shot from the player or an enemy

	//Metrics
	char enemyID = -1;

	//Positioning
	Dim2Df origin{};
	float initialAngle = 0.f;
	char swingDirection = 1;
	float arcCentredAngleOffset = 0.f;

	//Pointers
	sf::Sprite* sprite = nullptr;
	sf::Sprite* entitySprite = nullptr;
	Dim2Df* originRectOffset = nullptr;
	DirectionalAngle* facing = nullptr;
	float* radius = nullptr;
	float* attackSpeed = nullptr;
	Animation* anim = nullptr;
	sf::Sound* noise = nullptr;

	//Initiates attack
	void Init(const GameData& game, sf::Sprite& motionSprite, sf::Sprite* eSprite, DirectionalAngle& entityFacing, float& entityAttackSpeed, float& holdDistance, const bool& eIsWep, Animation* animation);

	//Updates attack
	void UpdateAttack(const GameData& game, std::vector<Projectile>& projList);

	//Update loop for attack
	void UpdateAttackMotion(const GameData& game, Motion& motion);

	//Adds projectiles to the list
	void SpawnProjectiles(const GameData& game, std::vector<Projectile>& projList);

	//Immediately stops the attack and resets values
	void Stop();
};

//Weapon
struct Weapon //Setup: attack0, attack1, sf::IntRect* textureRect, Dim2Df* origin
{
	//Attacks
	Attack attack0{}; //Normal attack
	Attack attack1{}; //Heavy attack

	//Setup stats
	char ID = -1; //Weapon ID
	const sf::IntRect* textureRect = nullptr; //Weapon rect on spritesheet
	const Dim2Df* origin = nullptr; //Weapon origin

	//Setup bools
	bool hasTwoAttacks = false; //Weapon has a second attack or not
	bool entityIsWeapon = false; //If entity is the weapon

	//Operational stats
	short attack0Range = 0; //Normal attack range
	short attack1Range = 0; //Heavy attack range

	//Operational bools
	bool visible = false; //Holding a weapon or not

	//SFML
	sf::Sprite sprite{}; //Weapon sprite

	//Operating bools
	bool attacking = false; //In attack animation
	bool active = false; //Is weapon currently being held

	//Position
	float holdDistance = GC::WEAPON_HOVER * GC::TILE_SIZE; //How far away the weapon is held

	//Initializes the weapon from a template
	void Init(const GameData& game, const bool& isPlayer, Animation& entityAnim, sf::Sound& weaponNoise);

	//Updates the position of the weapon
	void UpdateHoldPosition(const DirectionalAngle& facing, const Dim2Df holdOrigin);

	//Updates the rotation of the weapon
	void UpdateHoldRotation(const DirectionalAngle& facing);

	//Checks if this motion can damage opponents
	bool CheckIfMotionCanDamage();

	//Stops all attack motions and sets attacking bools to false
	void StopAttackIfTrue(const bool& boolean);
};

//Updates the rotation of the sprite
void UpdateRotation(const Motion& motion, sf::Sprite& sprite, const float& initialAngle);

//Game constants
namespace GC
{
	//Enums
	enum PROJECTILE_TYPES{ WEAPON_PROJECTILE, FIRE_SKULL_PROJECTILE, FIRE_BALL_PROJECTILE, FROST_BALL_PROJECTILE }; //Projectile type

	//Weapon: Sword
	const sf::IntRect SWORD_RECT = { 323, 26, 10, 21 }; //Where the sword is on the spritesheet
	const Dim2Df SWORD_ORIGIN = { 5.f, 18.f }; //The point at which the weapon is held
	//Weapon: Rusted Sword
	const sf::IntRect R_SWORD_RECT = { 307, 26, 10, 21 }; //Where the rusted sword is on the spritesheet
	const Dim2Df R_SWORD_ORIGIN = { 5.f, 18.f }; //The point at which the weapon is held

	//Projectile data
	const ProjectileData PROJECTILE_DATA_STRAIGHT_THROW = { &STRAIGHT_THROW_SLOW, 0.f, 1, 1, 0.f };
	const ProjectileData PROJECTILE_DATA_SPINNING_THROW = { &SPINNING_THROW_SLOW, 0.f, 1, 1, 0.f };
	const ProjectileData FIRE_BALL = { &STRAIGHT_THROW_SLOW, 0.f, 1, 1, 5.f, FIRE_BALL_PROJECTILE };
	const ProjectileData FIRE_SPIT = { &STRAIGHT_THROW_SLOW_LONG, 0.f, 1, 3, 5.f, FIRE_BALL_PROJECTILE };
	const ProjectileData FIRE_BALL_WAVE = { &STRAIGHT_THROW_SLOW_LONG, 0.f, 1, 15, 12.f, FIRE_BALL_PROJECTILE };
	const ProjectileData FIRE_BALL_VORTEX = { &CIRCLE_OF_DOOM, 8.f, 1, 12, 30.f, FIRE_BALL_PROJECTILE };
	const ProjectileData PLAYER_FROST_BALL1 = { &STRAIGHT_THROW_SLOW_SHORT, 0.f, 1, 1, 15.f, FROST_BALL_PROJECTILE };
	const ProjectileData PLAYER_FROST_BALL2 = { &STRAIGHT_THROW_SLOW_SHORT, 0.f, 1, 2, 15.f, FROST_BALL_PROJECTILE };
	const ProjectileData PLAYER_FROST_BALL3 = { &STRAIGHT_THROW_SLOW_SHORT, 0.f, 1, 3, 15.f, FROST_BALL_PROJECTILE };
	const ProjectileData PLAYER_FROST_BALL4 = { &STRAIGHT_THROW_SLOW_SHORT, 0.f, 1, 4, 15.f, FROST_BALL_PROJECTILE };
	const ProjectileData PLAYER_FROST_BALL5 = { &STRAIGHT_THROW_SLOW_SHORT, 0.f, 1, 9, 10.f, FROST_BALL_PROJECTILE };

	//Attacks										 (bools: summonProjectile, movingWithEntity, followingFacing, hasTwoMotions, arcCentredOnInitialAngle, hasRandomSwingDirection, hasSound, uniqueAnimation -> if true -> animOnMotion0, animOnMotion1)
	//Swing
	const Attack NORMAL_SWING_ATTACK = { {NORMAL_SWING_RELEASE}, {}, {}, SOUND_ATTACK0, 0,									false, true, false, false, true, true, true, false }; //Normal swing attack
	const Attack HEAVY_SWING_ATTACK = { {HEAVY_SWING_WINDUP, HEAVY_SWING_RELEASE}, {}, {}, SOUND_ATTACK0, 12,				false, true, true, true, false, false, true, false }; //Heavy swing attack
	const Attack HEAVY_F_SWING_ATTACK = { {HEAVY_SWING_WINDUP, HEAVY_F_SWING_RELEASE}, {}, {}, SOUND_ATTACK0, 16,			false, true, true, true, false, false, true, false }; //Heavy fancy swing attack, to give the player a slight edge
	//Thrust
	const Attack NORMAL_THRUST_ATTACK = { {NORMAL_THRUST_RELEASE}, {}, {}, SOUND_ATTACK1, 16,								false, true, true, false, false, false, true, false }; //Normal thrust attack
	const Attack HEAVY_THRUST_ATTACK = { {HEAVY_THRUST_WINDUP, HEAVY_THRUST_RELEASE}, {}, {}, SOUND_ATTACK2, 24,			false, true, true, true, false, false, true, false }; //Heavy thrust attack
	//Throw
	const Attack NORMAL_STRAIGHT_THROW_ATTACK = { {THROW_PROJECTILE_FAST}, &PROJECTILE_DATA_STRAIGHT_THROW, {}, {}, -1,		true, true, true, false, false, false, false, false }; //Normal throw attack
	const Attack NORMAL_SPINNING_THROW_ATTACK = { {THROW_PROJECTILE_FAST}, &PROJECTILE_DATA_SPINNING_THROW, {}, {}, -1,		true, true, true, false, false, false, false, false }; //Normal spinning throw attack
	//Special
	const Attack CIRCLE_OF_DOOM_ATTACK = { {CIRCLE_OF_DOOM}, {}, {}, {}, 240,												false, false, true, false, false, false, false, false }; //Sword of doom attack
	//Enemy attacks
	const Attack HORN_STAB = { {HORN_STAB_JUMP}, {}, {}, {}, 64,															false, false, false, false, false, false, false, false }; //Horn stab jump attack
	const Attack CHARGE = { {CHARGE_WINDUP, CHARGE_RELEASE}, {}, &ENEMY_ANIM_MOVE, {}, 160,									false, false, false, true, false, false, false, true, false, true }; //Horn charge attack
	const Attack FIREBALL = { {BITE_WINDUP}, &FIRE_BALL, &ENEMY_ANIM_BITE, {}, 96,												true, false, true, false, false, false, false, true, true, false }; //Bite attack
	const Attack FLAME_WAVE = { {BITE_WINDUP}, &FIRE_BALL_WAVE, &ENEMY_ANIM_BITE, {}, 160,								true, false, true, false, false, false, false, true, true, false }; //Bite barrage attack
	const Attack FLAME_VORTEX = { {BITE_WINDUP}, &FIRE_BALL_VORTEX, &ENEMY_ANIM_BITE, {}, 160,									true, false, true, false, false, false, false, true, true, false }; //Bite wave attack
	const Attack FIREBALL_SPIT = { {FIRE_BALL_SPIT_WINDUP, FIRE_BALL_SPIT_RELEASE}, &FIRE_SPIT, {}, {}, 160,				true, false, true, true, false, false, false, false, false, false }; //Fire spit attack
	//Weapons																									(bools: hasTwoAttacks, entityIsWeapon)
	const Weapon SWORD = { NORMAL_SWING_ATTACK, HEAVY_SWING_ATTACK, ID_SWORD, &SWORD_RECT, &SWORD_ORIGIN,						true, false }; //Normal sword, starting weapon for the knight?
	const Weapon FANCY_SWORD = { NORMAL_SWING_ATTACK, HEAVY_F_SWING_ATTACK, ID_FANCY_SWORD, &F_SWORD_RECT, &F_SWORD_ORIGIN,		true, false }; //Big fancy sword, used by the knight?
	const Weapon SPEAR = { NORMAL_THRUST_ATTACK, HEAVY_THRUST_ATTACK, ID_SPEAR, &SPEAR_RECT, &SPEAR_ORIGIN,						true, false }; //Tribal spear, used by the lizard?
	const Weapon IMP_WEAPON = { HORN_STAB, CHARGE, ID_IMP_WEAPON, {}, {},														true, true }; //Imp attacks
	const Weapon LESSER_DEMON_WEAPON = { FIREBALL, FIREBALL_SPIT, ID_LESSER_DEMON_WEAPON, {}, {},								true, true }; //Lesser Demon attacks
	const Weapon RUSTED_SWORD = { NORMAL_SWING_ATTACK, HEAVY_SWING_ATTACK, ID_RUSTED_SWORD, &R_SWORD_RECT, &R_SWORD_ORIGIN,		true, false }; //Rusted sword, used by Abberants
	const Weapon GREATER_DEMON_WEAPON = { FLAME_WAVE, FLAME_VORTEX, ID_GREATER_DEMON_WEAPON, {}, {},								true, true }; //Greater Demon attacks
}