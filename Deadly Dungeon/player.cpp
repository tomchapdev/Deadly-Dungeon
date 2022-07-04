#include "player.h"
#include "maths.h"

//Assigns projectileData of player upgrades
void AssignProjectileData(Weapon& weapon, const unsigned char& bulletNum)
{
	weapon.attack0.summonProjectile = true;
	weapon.attack1.summonProjectile = true;

	switch (bulletNum)
	{
	case 4:
		weapon.attack0.projectileData = &GC::PLAYER_FIRE_BALL4;
		weapon.attack1.projectileData = &GC::PLAYER_FIRE_BALL4;
		break;

	case 3:
		weapon.attack0.projectileData = &GC::PLAYER_FIRE_BALL3;
		weapon.attack1.projectileData = &GC::PLAYER_FIRE_BALL3;
		break;

	case 2:
		weapon.attack0.projectileData = &GC::PLAYER_FIRE_BALL2;
		weapon.attack1.projectileData = &GC::PLAYER_FIRE_BALL2;
		break;

	case 1:
		weapon.attack0.projectileData = &GC::PLAYER_FIRE_BALL1;
		weapon.attack1.projectileData = &GC::PLAYER_FIRE_BALL1;
		break;

	default:
		printf("No melee bullet upgrades have been purchased, or purchases are not being recorded correctly\n");
	}
}

void Player::Init(GameData& game, const Dim2Df& spawnPosition, std::vector<Room>& rooms)
{
	//Stats
	maxHealth = GC::PLAYER_HEALTH;
	speed = GC::MEDIUM_MOVEMENT_SPEED;
	coins = 20000;

	//Entity stats
	entity.isPlayer = true;
	entity.health = GC::PLAYER_HEALTH;
	entity.collisionRect = GC::KNIGHT_BODY_RECT;
	entity.anim.Init(&GC::PLAYER_ANIM_IDLE);

	//SFML
	entity.texture = &game.textures[GC::KNIGHT_TEXTURE];
	entity.sprite.setTexture(*entity.texture);
	entity.sprite.setTextureRect({ 0, 0, GC::KNIGHT_DIMENSIONS.x, GC::KNIGHT_DIMENSIONS.y });
	entity.sprite.setOrigin(Dim2Df(GC::KNIGHT_BODY_CENTRE));

	//Position
	entity.sprite.setPosition(spawnPosition);
	entity.FindCurrentRoom(rooms);

	//Weapon
	entity.weapon = GC::SWORD;
	entity.weapon.Init(game, entity.isPlayer, entity.anim);
}

void Player::InputHandling(sf::RenderWindow& window, GameData& game, std::vector<Room>& rooms)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		//Exit application
		if ((event.type == sf::Event::Closed) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//Play inputs
		if (game.input == GC::GAMEPAD)
		{
			GamepadControls(event);
		}
		else
		{
			KeyboardControls(event, game, rooms);
		}
	}
}

void Player::KeyboardControls(const sf::Event& event, GameData& game, std::vector<Room>& rooms)
{
	//Movement
	KeyboardMovement(event);

	//Entity facing
	GetMouseAngle(game);

	//Attacks
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (entity.canAttack && !entity.weapon.attacking)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				entity.InitAttack(game, GC::FIRST_ATTACK);
				entity.weapon.attack0.attackRelease = false;
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				entity.InitAttack(game, GC::SECOND_ATTACK);
				entity.weapon.attack1.attackRelease = false;
			}
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			entity.weapon.attack0.attackRelease = true;
		}
		if (event.mouseButton.button == sf::Mouse::Right)
		{
			entity.weapon.attack1.attackRelease = true;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::E)
		{
			BuyItemFromShop(game, rooms[entity.roomID].shops);
		}
	}
}

void Player::KeyboardMovement(const sf::Event& event)
{
	//Movement booleans
	bool movingLeft = false; //Player is moving left
	bool movingRight = false; //Player is moving right
	bool movingUp = false; //Player is moving up
	bool movingDown = false; //Player is moving down

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movingLeft = true;
	}
	else
	{
		movingLeft = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movingRight = true;
	}
	else
	{
		movingRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movingUp = true;
	}
	else
	{
		movingUp = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movingDown = true;
	}
	else
	{
		movingDown = false;
	}

	//Opposite directions cancel each other out
	if (movingLeft && movingRight)
	{
		movingLeft = false;
		movingRight = false;
	}
	if (movingUp && movingDown)
	{
		movingUp = false;
		movingDown = false;
	}

	//Update movement bool and animation
	if (movingUp || movingDown || movingLeft || movingRight)
	{
		if (!entity.moving)
		{
			entity.moving = true;
			entity.anim.Init(&GC::PLAYER_ANIM_MOVE);
		}
	}
	else
	{
		if (entity.moving)
		{
			entity.moving = false;
			entity.anim.Init(&GC::PLAYER_ANIM_IDLE);
		}
	}

	//entity.moving = true;
	if (entity.moving)
	{
		//Find movement vector
		DirectionalAngle dirAngle;

		if (movingRight && movingUp) //North directional angle
		{
			dirAngle.angle = GC::RADS_45DEGREES;
			dirAngle.direction = GC::NORTH;
			entity.movementVector = CalculateVectorOfMagnitude(dirAngle, speed);
		}
		else if (movingRight && movingDown) //East directional angle
		{
			dirAngle.angle = GC::RADS_45DEGREES;
			dirAngle.direction = GC::EAST;
			entity.movementVector = CalculateVectorOfMagnitude(dirAngle, speed);
		}
		else if (movingLeft && movingDown) //South directional angle
		{
			dirAngle.angle = GC::RADS_45DEGREES;
			dirAngle.direction = GC::SOUTH;
			entity.movementVector = CalculateVectorOfMagnitude(dirAngle, speed);
		}
		else if (movingLeft && movingUp) //West directional angle
		{
			dirAngle.angle = GC::RADS_45DEGREES;
			dirAngle.direction = GC::WEST;
			entity.movementVector = CalculateVectorOfMagnitude(dirAngle, speed);
		}
		else if (movingUp) //North
		{
			entity.movementVector = { 0.f, -speed };
		}
		else if (movingRight) //East
		{
			entity.movementVector = { speed, 0.f };
		}
		else if (movingDown) //South
		{
			entity.movementVector = { 0.f, speed };
		}
		else //West
		{
			entity.movementVector = { -speed, 0.f };
		}
	}
}

void Player::GetMouseAngle(const GameData& game)
{
	//Find origin and target points
	Dim2Df centre = { (float)(game.screenResolution.x / 2), (float)(game.screenResolution.y / 2) };
	Dim2Df mousePosition = { (float)mouse.getPosition().x, (float)mouse.getPosition().y };

	//Get vector between points, then calculate directional angle using vector
	entity.facing = CalculateDirectionalAngleFromVector(CalculateVectorBetweenPoints(centre, mousePosition));
}

void Player::GamepadControls(const sf::Event& event)
{

}

void Player::CheckAttackCollision(GameData& game, std::vector<Enemy>& enemies)
{
	if (entity.weapon.attacking && entity.weapon.CheckIfMotionCanDamage())
	{
		for (unsigned int index = 0; index < enemies.size(); index++)
		{
			if (enemies[index].active && !enemies[index].entity.invulnerable)
			{
				//Calculate distance to enemy
				Dim2Df position = enemies[index].entity.sprite.getPosition();
				float distanceToEnemy = CalculateMagnitudeOfVector(entity.weapon.sprite.getPosition() - position);

				//If in range, check collision
				if (distanceToEnemy <= GC::CHECK_ATTACK_COLLISION_RANGE)
				{
					if (entity.weapon.sprite.getGlobalBounds().intersects(enemies[index].entity.sprite.getGlobalBounds()))
					{
						//Calculate damage
						float damage = entity.power * GC::DEFAULT_DAMAGE;

						if (entity.weapon.attack1.active) //Heavy attack
						{
							damage *= heavyAttackMultiplier;
						}

						//Hit enemy
						unsigned char actualDamage = (unsigned char)round(damage);
						enemies[index].entity.TakeDamage(actualDamage, entity.facing, knockbackPower);

						if (enemies[index].entity.isAlive)
						{
							//Interrupt enemy attacks
							if (enemies[index].entity.weapon.attacking)
							{
								enemies[index].entity.StopAttackIfTrue(true);
							}
						}
						else
						{
							//Update metrics
							game.metrics.UpdateKills(entity.weapon.ID, enemies[index].ID);
							EarnCoins(enemies[index].ID);
						}
					}
				}
			}
		}
	}
}

void Player::Update(sf::RenderWindow& window, GameData& game, std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies, std::vector<Room>& rooms)
{
	//Invulnerability
	UpdateInvulnerability(game);

	//Input
	InputHandling(window, game, rooms);

	//Movement
	if (entity.moving && !dodging)
	{
		entity.Move(game);
	}
	entity.FindCurrentRoom(rooms);

	//Weapon
	entity.UpdateWeapon(game, projectiles);
	CheckAttackCollision(game, enemies);
}

void Player::UpdateInvulnerability(GameData& game)
{
	//Invulnerability
	if (hit)
	{
		if (entity.health <= 0)
		{
			Dead(game);
		}

		entity.invulnerable = true;
		entity.invulnerabilityTimer = GC::PLAYER_HIT_INVULNERABILITY;
		entity.sprite.setColor(GC::PLAYER_HIT_COLOUR);
		entity.weapon.sprite.setColor(GC::PLAYER_HIT_COLOUR);
		hit = false;
	}
	else if (entity.invulnerable)
	{
		if (entity.invulnerabilityTimer < 0.f)
		{
			entity.invulnerable = false;
			entity.sprite.setColor(sf::Color::White);
			entity.weapon.sprite.setColor(sf::Color::White);
		}
		else
		{
			entity.invulnerabilityTimer -= game.elapsed;
		}
	}
}

void Player::Dead(GameData& game)
{
	printf("Player Died\n");
	game.playerDead = true;
}

void Player::EarnCoins(const char& enemyID)
{
	switch (enemyID)
	{
	case GC::ID_IMP:
		coins += GC::IMP_COINS;
		break;

	case GC::ID_LESSER_DEMON:
		coins += GC::LESSER_DEMON_COINS;
		break;

	case GC::ID_ABERRANT:
		coins += GC::ABERRANT_COINS;
		break;

	case GC::ID_GREATER_DEMON:
		coins += GC::GREATER_DEMON_COINS;
		break;

	default:
		printf("Enemy ID not recognised, imp coins were given\n");
		coins += GC::IMP_COINS;
		break;
	}
}

void Player::BuyItemFromShop(GameData& game, std::vector<Shop>& shops)
{
	bool found = false;
	unsigned char index = 0;

	while (!found && (index < shops.size()))
	{
		if (!shops[index].sold)
		{
			float distanceToShop = CalculateMagnitudeOfVector(entity.sprite.getPosition() - shops[index].position);

			//If in range, check collision
			if (distanceToShop <= GC::BUY_ITEM_RANGE)
			{
				found = true;
				char itemID = shops[index].Buy(game, coins);
				if (itemID != -1)
				{
					ApplyItemEffects(game, itemID);
				}
			}
		}

		index++;
	}
}

void Player::ApplyItemEffects(const GameData& game, const char& itemID)
{
	bool newWeapon = false;
	Dim2Df scale;

	switch (itemID)
	{
	case GC::WS_HEALTH:
		entity.health = GC::BOOSTED_HEALTH;
		maxHealth = GC::BOOSTED_HEALTH;
		break;

	case GC::WS_SPEED:
		speed = GC::BOOSTED_SPEED;
		break;

	case GC::WS_POWER:
		entity.power = GC::BOOSTED_POWER;
		break;

	case GC::WS_ATTACK_SPEED:
		entity.attackSpeed = GC::BOOSTED_ATTACK_SPEED;
		break;

	case GC::WS_KNOCKBACK:
		knockbackPower = GC::BOOSTED_KNOCKBACK_POWER;
		break;

	case GC::WS_FULL_HEAL:
		entity.health = maxHealth;
		break;

	case GC::LS_FANCY_SWORD:
		newWeapon = true;
		entity.weapon = GC::FANCY_SWORD;
		entity.weapon.Init(game, true, entity.anim);
		break;

	case GC::LS_SPEAR:
		newWeapon = true;
		entity.weapon = GC::SPEAR;
		entity.weapon.Init(game, true, entity.anim);
		break;

	case GC::LS_BIG_WEAPONS:
		entity.weaponScale = GC::BIG_WEAPONS_SCALE;
		scale = entity.weapon.sprite.getScale();
		entity.weapon.sprite.setScale(scale.x * entity.weaponScale.x, scale.y * entity.weaponScale.y);
		break;

	case GC::LS_MELEE_PROJECTILE:
		AssignProjectileData(entity.weapon, game.metrics.meleeBulletUpgrades);
		break;

	default:
		printf("Item ID not recognised, player was not updated\n");
	}

	if (newWeapon)
	{
		if (game.metrics.purchasedBigWeapons)
		{
			entity.weaponScale = GC::BIG_WEAPONS_SCALE;
			Dim2Df scale = entity.weapon.sprite.getScale();
			entity.weapon.sprite.setScale(scale.x * entity.weaponScale.x, scale.y * entity.weaponScale.y);
		}
		if (game.metrics.purchasedMeleeBullets)
		{
			AssignProjectileData(entity.weapon, game.metrics.meleeBulletUpgrades);
		}
	}
}