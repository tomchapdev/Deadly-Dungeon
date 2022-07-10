#pragma once
#include "data.h"
#include "graphics.h"

//Data used for room generation
struct RoomData
{
	char type = 0;
	std::vector<std::vector<int>> tilemap = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
};

//Shops that sell upgrades to the player
struct Shop
{
	//Bools
	bool water = false; //If this shop is a water or lava shop
	bool sold = false; //If this shop has sold it's item
	bool unlimitedItems = false; //If this shop has unlimited stock

	//Main stats
	char itemID = 0; //What item the shop sells
	short price = 0; //How much it costs

	//Position
	Dim2Df position{}; //Shop global location

	//SFML
	sf::Text name; //Shop name
	std::string itemName; //Item name
	std::string itemValue; //Item value
	sf::Sprite sprite; //Shop sprite

	//Assigns shop values based on the item given
	void SetupShop(const GameData& game, const char& ID);

	//Renders the shop
	void Render(sf::RenderWindow& window);

	//Buys the item from the shop
	char Buy(GameData& game, short& coins);

	//Increases price and changes the name of the shop
	void IncreasePrice();
};

//An interactive game room
struct Room
{
	//Data
	const RoomData* data{}; //Room data

	//Main stats
	char ID = 0; //Which
	sf::IntRect rect = { 0, 0, 0, 0 }; //Where the room is on the global map, in tiles

	//Bools
	bool hasAnimatedTiles = false; //If the room has animations or not

	//Vectors
	std::vector<AnimatedTiles> animatedTiles; //Vector of the animated tiles in this room
	std::vector<Dim2Df> spawners; //Vector of enemy spawners in this room
	std::vector<Shop> shops; //Vector of shops in this room

	//Counters
	char spawnerCounter = 0; //How many spawners are in this room
	char shopCounter = 0; //How mant shops are in this room

	//Initializes the room
	void Init(GameData& game, const int& roomNumber, const Dim2Di& position);

	//Changes variables to dimensions of the room
	void GetTypeDimensions(int& width, int& height);

	//Draws the tile onto the game map
	void TileDrawing(GameData& game, const int& x, const int& y, char& tileID, const char& tileAboveID);

	//Gets booleans for current tile
	void TileDrawingBools(const Tile& tile, bool& requiresFloor, bool& wallside, bool& walltop, bool& corner, bool& right, bool& smallWallTop);

	//Draws a random floor at a specific locations
	void DrawRandomFloor(GameData& game, const int& x, const int& y);

	//Alters the collision map based on the tile
	void AlterCollisionMap(GameData& game, const int& x, const int& y, const char& tileID);

	//Checks for animated tiles
	void CheckForAnimatedTiles(GameData& game, const int& x, const int& y, const char& tileID);

	//Updates animated tiles
	void UpdateAnimatedTiles(const GameData& game, sf::RenderWindow& window);

	//Finds enemy spawn locations
	void CheckForSpawner(const int& x, const int& y, const char& tileID);

	//Finds shop locations
	void CheckForShop(const int& x, const int& y, const char& tileID);

	//Render shops
	void RenderShops(sf::RenderWindow& window);
};

//Game constants
namespace GC
{
	//Shop: General
	const short ITEM_NAME_LENGTH = 16; //Length of item names
	const sf::IntRect POTION_RECT_R1 = { 288, 225, 16, 16 };
	const sf::IntRect POTION_RECT_R2 = { 288, 241, 16, 16 };
	const sf::IntRect POTION_RECT_B1 = { 304, 225, 16, 16 };
	const sf::IntRect POTION_RECT_B2 = { 304, 241, 16, 16 };
	const sf::IntRect POTION_RECT_G1 = { 320, 225, 16, 16 };
	const sf::IntRect POTION_RECT_G2 = { 320, 241, 16, 16 };
	const sf::IntRect POTION_RECT_Y1 = { 336, 225, 16, 16 };
	const sf::IntRect POTION_RECT_Y2 = { 336, 241, 16, 16 };
	const Dim2Df POTION_ORIGIN = { 8, 12 };
	const char UNLIMITED_ITEM_PRICE_INCREASE = 15;

	//Room: General
	const char ROOM_NUM = 4; //Number of rooms
	const char ROOM_MAX_SIZE = 32; //Max size of a room, in tiles
	const char MAX_SPAWNERS = 12; //Maximum number of spawners in a room
	const char MAX_SHOPS = 4; //Maximum number of shops in a room
	//Room: Types
	const Dim2Di ROOM_TYPE_0 = { 32, 32 };
	const Dim2Di ROOM_TYPE_1 = { 16, 16 };
	const Dim2Di ROOM_TYPE_2 = { 32, 16 };
	const Dim2Di ROOM_TYPE_3 = { 16, 32 };
	//Room: Tilemaps
	const std::vector<RoomData> ROOM_LIST = {
		{0, {{54, 52, 23, 52, 23, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 55, 00, 00, 00, 00},
			{14, 02, 19, 02, 19, 05, 02, 02, 02, 02, 02, 02, 02, 02, 04, 02, 02, 02, 04, 02, 02, 02, 02, 02, 02, 02, 05, 11, 00, 00, 00, 00},
			{49, 32, 27, 34, 27, 38, 39, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 36, 32, 37, 35, 32, 32, 47, 00, 00, 00, 00},
			{49, 32, 32, 62, 32, 32, 32, 32, 36, 32, 32, 32, 33, 32, 32, 32, 32, 36, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 52, 55, 00, 00},
			{49, 32, 35, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 32, 36, 48, 02, 11, 00, 00},
			{49, 32, 32, 32, 32, 33, 32, 32, 38, 32, 32, 32, 32, 39, 32, 32, 38, 32, 32, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 00, 00},
			{49, 32, 32, 36, 32, 32, 40, 32, 32, 32, 37, 45, 52, 46, 32, 32, 32, 32, 34, 32, 32, 54, 31, 52, 31, 55, 32, 32, 32, 47, 00, 00},
			{49, 32, 32, 32, 32, 32, 37, 32, 32, 32, 45, 61, 02, 58, 46, 32, 32, 40, 32, 32, 32, 14, 18, 02, 18, 15, 32, 32, 32, 47, 00, 00},
			{49, 34, 32, 32, 32, 32, 32, 32, 40, 45, 60, 13, 00, 12, 58, 46, 32, 32, 32, 32, 32, 49, 26, 36, 26, 47, 33, 32, 32, 47, 55, 00},
			{49, 32, 32, 38, 32, 40, 32, 32, 32, 47, 13, 00, 00, 00, 12, 49, 32, 32, 32, 37, 35, 58, 46, 63, 45, 60, 32, 32, 36, 48, 11, 00},
			{49, 32, 32, 32, 37, 35, 32, 32, 32, 47, 00, 00, 00, 00, 00, 49, 32, 32, 33, 38, 39, 12, 50, 32, 48, 13, 32, 32, 32, 32, 47, 00},
			{49, 32, 32, 32, 38, 39, 32, 32, 32, 47, 52, 23, 52, 23, 52, 49, 32, 32, 32, 32, 32, 36, 32, 32, 32, 32, 34, 32, 32, 32, 47, 00},
			{49, 32, 37, 32, 32, 32, 32, 33, 32, 48, 02, 19, 04, 19, 02, 50, 32, 32, 32, 32, 32, 32, 32, 32, 35, 32, 32, 32, 38, 39, 47, 00},
			{49, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 27, 34, 27, 32, 32, 32, 34, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 60, 52},
			{49, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 62, 32, 32, 32, 32, 32, 32, 37, 32, 32, 32, 32, 32, 32, 40, 36, 32, 48, 02, 02},
			{58, 46, 32, 32, 32, 32, 32, 32, 32, 34, 32, 32, 32, 32, 32, 36, 32, 32, 32, 32, 32, 32, 32, 34, 32, 32, 32, 32, 32, 33, 32, 32},
			{12, 58, 52, 46, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 40, 32, 32, 32, 32, 32, 32, 32, 40, 32, 32, 32, 32, 32, 32, 32, 37},
			{00, 01, 02, 58, 52, 52, 46, 37, 35, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 32, 36, 38},
			{00, 00, 00, 12, 02, 05, 49, 32, 32, 32, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 34, 32, 32, 32, 32, 36, 32, 32, 32, 32, 32, 45},
			{00, 00, 00, 00, 00, 00, 49, 32, 32, 32, 32, 32, 32, 32, 45, 52, 52, 52, 53, 52, 46, 32, 37, 35, 45, 52, 52, 52, 52, 52, 52, 60},
			{00, 00, 00, 00, 00, 00, 58, 52, 52, 46, 32, 32, 32, 32, 47, 02, 02, 02, 04, 02, 49, 41, 41, 41, 47, 02, 04, 02, 02, 05, 02, 03},
			{00, 00, 00, 00, 00, 00, 01, 02, 02, 49, 34, 32, 45, 52, 60, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 47, 05, 13, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 54, 52, 49, 32, 32, 47, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 10, 02, 50, 32, 36, 47, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{54, 52, 23, 52, 23, 52, 52, 49, 32, 32, 38, 39, 47, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{14, 02, 18, 02, 18, 02, 05, 50, 32, 32, 32, 32, 47, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{49, 32, 26, 37, 26, 32, 32, 32, 32, 32, 45, 52, 60, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{49, 32, 32, 63, 32, 32, 45, 52, 52, 52, 60, 02, 03, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{49, 32, 34, 32, 32, 36, 47, 02, 04, 02, 13, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{58, 52, 52, 52, 52, 52, 61, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00},
			{12, 02, 04, 02, 02, 02, 02, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 41, 41, 41, 47, 00, 00, 00, 00, 00, 00, 00}}},
		{0, {{00, 00, 00, 00, 56, 52, 52, 52, 52, 52, 52, 52, 52, 22, 52, 52, 52, 52, 52, 52, 52, 22, 52, 52, 22, 52, 52, 52, 52, 57, 00, 00},
		{00, 00, 56, 52, 14, 05, 02, 02, 02, 02, 02, 02, 02, 16, 04, 02, 02, 02, 04, 02, 02, 16, 02, 02, 16, 02, 05, 02, 02, 15, 00, 00},
		{00, 00, 14, 04, 50, 38, 39, 32, 32, 32, 34, 32, 32, 24, 35, 32, 32, 32, 34, 32, 32, 24, 32, 36, 24, 32, 32, 38, 39, 47, 57, 00},
		{00, 00, 49, 34, 32, 32, 32, 33, 32, 32, 40, 36, 32, 32, 32, 32, 32, 32, 32, 32, 37, 32, 32, 32, 32, 40, 32, 32, 33, 48, 15, 00},
		{00, 00, 49, 32, 45, 31, 52, 31, 46, 32, 32, 32, 32, 34, 32, 32, 32, 40, 32, 32, 38, 32, 34, 32, 32, 32, 32, 32, 36, 32, 47, 00},
		{00, 00, 49, 32, 48, 18, 02, 18, 50, 32, 32, 45, 52, 30, 52, 46, 36, 32, 32, 45, 52, 30, 52, 52, 30, 52, 46, 32, 32, 32, 47, 00},
		{00, 00, 49, 37, 35, 26, 36, 26, 32, 36, 45, 61, 02, 16, 02, 49, 32, 32, 33, 47, 02, 16, 02, 02, 16, 02, 49, 32, 32, 34, 47, 00},
		{00, 00, 59, 46, 32, 32, 63, 32, 32, 45, 61, 13, 00, 25, 00, 49, 32, 40, 32, 47, 00, 25, 00, 00, 25, 00, 49, 37, 35, 32, 47, 00},
		{00, 00, 01, 49, 33, 32, 32, 34, 32, 47, 03, 00, 00, 00, 00, 49, 34, 32, 32, 47, 00, 00, 00, 00, 00, 00, 49, 38, 39, 32, 47, 00},
		{00, 00, 00, 58, 52, 52, 52, 52, 52, 60, 00, 00, 00, 00, 00, 49, 32, 32, 39, 47, 00, 00, 56, 23, 52, 23, 49, 36, 32, 32, 47, 00},
		{00, 00, 00, 12, 02, 02, 02, 05, 02, 13, 00, 00, 00, 00, 00, 49, 32, 32, 32, 47, 00, 00, 14, 19, 02, 19, 50, 32, 32, 36, 47, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 54, 52, 52, 49, 32, 32, 36, 47, 00, 00, 49, 27, 32, 27, 32, 32, 32, 32, 47, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 10, 02, 13, 50, 32, 32, 32, 47, 00, 00, 49, 32, 62, 32, 32, 32, 32, 45, 61, 00},
		{22, 52, 52, 22, 52, 52, 22, 52, 52, 22, 52, 52, 49, 32, 33, 32, 32, 34, 40, 47, 00, 00, 59, 52, 52, 52, 52, 52, 52, 61, 13, 00},
		{16, 02, 02, 16, 02, 05, 16, 02, 02, 16, 04, 02, 50, 32, 32, 32, 32, 32, 32, 47, 00, 00, 01, 02, 02, 05, 02, 02, 02, 13, 00, 00},
		{24, 36, 32, 24, 32, 32, 24, 36, 32, 24, 32, 32, 34, 32, 32, 36, 37, 35, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{35, 32, 32, 34, 32, 32, 32, 32, 32, 32, 32, 40, 32, 32, 32, 32, 38, 39, 32, 47, 52, 52, 52, 52, 52, 52, 52, 52, 57, 00, 00, 00},
		{39, 32, 32, 32, 32, 32, 32, 37, 35, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 48, 02, 02, 04, 02, 02, 04, 02, 02, 15, 00, 00, 00},
		{30, 52, 52, 30, 52, 52, 30, 52, 52, 30, 52, 52, 46, 32, 32, 32, 32, 32, 32, 32, 34, 32, 32, 32, 32, 36, 38, 39, 47, 00, 00, 00},
		{16, 05, 02, 16, 04, 02, 16, 02, 02, 16, 02, 02, 49, 34, 32, 32, 32, 36, 32, 32, 32, 32, 37, 35, 34, 32, 32, 32, 47, 52, 57, 00},
		{25, 00, 00, 25, 00, 00, 25, 00, 00, 25, 00, 00, 49, 32, 32, 32, 45, 52, 52, 52, 46, 32, 32, 40, 32, 32, 32, 36, 48, 02, 15, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 32, 47, 02, 02, 02, 49, 33, 32, 32, 32, 32, 32, 32, 32, 32, 47, 00},
		{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 34, 47, 00, 00, 00, 49, 32, 32, 45, 31, 52, 31, 46, 32, 32, 47, 00},
		{00, 00, 56, 52, 52, 23, 52, 23, 52, 52, 52, 52, 49, 32, 40, 32, 47, 00, 00, 00, 49, 32, 32, 48, 18, 02, 18, 50, 32, 32, 47, 00},
		{00, 00, 14, 04, 02, 19, 02, 19, 02, 02, 05, 02, 50, 36, 32, 32, 47, 00, 00, 00, 49, 36, 32, 32, 26, 36, 26, 32, 34, 32, 47, 00},
		{00, 56, 49, 32, 34, 27, 32, 27, 34, 32, 38, 39, 32, 32, 32, 33, 47, 00, 00, 00, 49, 35, 32, 32, 32, 63, 33, 32, 32, 37, 47, 00},
		{00, 14, 50, 32, 32, 32, 62, 32, 32, 32, 32, 32, 32, 32, 45, 52, 61, 00, 00, 00, 49, 39, 32, 34, 32, 32, 32, 32, 32, 38, 47, 00},
		{00, 49, 39, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 02, 03, 00, 00, 00, 59, 52, 52, 52, 52, 52, 52, 52, 52, 52, 61, 00},
		{00, 49, 32, 32, 33, 32, 32, 32, 32, 36, 32, 32, 32, 34, 47, 00, 00, 00, 00, 00, 12, 02, 02, 02, 04, 02, 02, 02, 05, 02, 13, 00},
		{00, 49, 34, 40, 32, 36, 45, 52, 52, 52, 52, 52, 52, 52, 61, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 49, 32, 32, 32, 38, 47, 02, 02, 02, 02, 02, 05, 02, 13, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
		{00, 49, 32, 37, 35, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00}}},
		{0, {{00, 49, 32, 38, 39, 32, 47, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 23, 52, 23, 52, 55, 00},
			{00, 49, 32, 32, 32, 32, 48, 02, 02, 04, 02, 02, 02, 02, 02, 02, 02, 02, 05, 02, 02, 02, 02, 02, 02, 02, 19, 04, 19, 02, 11, 00},
			{00, 49, 32, 32, 32, 32, 34, 32, 39, 36, 32, 32, 37, 35, 32, 32, 35, 34, 32, 33, 32, 39, 36, 32, 32, 32, 27, 36, 27, 32, 47, 00},
			{00, 49, 36, 32, 37, 35, 32, 32, 32, 32, 32, 33, 32, 32, 32, 32, 36, 32, 32, 32, 32, 32, 32, 34, 32, 32, 33, 62, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 32, 32, 40, 32, 36, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 40, 32, 32, 32, 32, 32, 32, 34, 47, 00},
			{00, 49, 33, 32, 36, 32, 32, 32, 34, 32, 32, 32, 32, 32, 32, 32, 40, 32, 32, 32, 34, 32, 32, 32, 32, 32, 32, 37, 35, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 36, 32, 32, 32, 37, 32, 32, 32, 34, 32, 32, 38, 32, 36, 32, 32, 33, 37, 32, 32, 36, 38, 39, 32, 47, 00},
			{00, 49, 38, 40, 32, 32, 45, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 46, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 34, 32, 32, 32, 47, 02, 02, 02, 02, 05, 02, 02, 02, 02, 04, 02, 02, 02, 05, 02, 02, 02, 49, 32, 34, 32, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 40, 36, 32, 47, 00},
			{00, 49, 32, 32, 33, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 35, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 39, 32, 32, 32, 33, 47, 00},
			{00, 49, 32, 32, 32, 36, 47, 52, 52, 23, 52, 23, 52, 52, 52, 52, 52, 52, 52, 23, 52, 23, 52, 52, 49, 36, 32, 32, 32, 34, 47, 00},
			{00, 49, 34, 32, 32, 32, 48, 04, 02, 18, 02, 18, 02, 04, 02, 02, 02, 02, 02, 18, 04, 18, 02, 02, 50, 32, 32, 36, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 38, 39, 26, 33, 26, 32, 32, 32, 34, 32, 38, 39, 26, 32, 26, 36, 32, 33, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 37, 36, 32, 32, 34, 32, 32, 32, 63, 32, 32, 32, 36, 32, 32, 32, 34, 32, 63, 32, 32, 32, 32, 32, 32, 34, 32, 37, 47, 00},
			{00, 49, 32, 32, 40, 32, 32, 36, 32, 32, 32, 32, 32, 32, 32, 40, 36, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 40, 32, 38, 47, 00},
			{00, 49, 34, 33, 32, 36, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 32, 36, 32, 34, 37, 35, 32, 34, 32, 32, 36, 32, 47, 00},
			{00, 58, 52, 46, 32, 32, 32, 45, 52, 46, 34, 32, 36, 32, 45, 52, 52, 52, 52, 52, 52, 52, 52, 52, 46, 32, 32, 32, 32, 32, 47, 00},
			{00, 01, 04, 49, 32, 32, 32, 47, 05, 49, 32, 32, 32, 37, 47, 02, 02, 02, 02, 04, 02, 02, 02, 05, 49, 35, 32, 32, 32, 32, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 32, 36, 32, 38, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 33, 32, 36, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 32, 37, 35, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 32, 32, 32, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 36, 38, 39, 34, 47, 00, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 32, 34, 32, 32, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 35, 32, 32, 32, 47, 52, 52, 52, 23, 52, 23, 52, 52, 52, 49, 36, 32, 32, 32, 38, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 39, 32, 33, 36, 48, 05, 02, 02, 18, 04, 18, 02, 02, 02, 50, 32, 32, 40, 33, 32, 47, 00},
			{00, 00, 00, 49, 41, 41, 41, 47, 00, 49, 32, 32, 32, 32, 32, 39, 36, 38, 26, 33, 26, 32, 32, 34, 39, 32, 32, 32, 36, 32, 47, 00},
			{52, 52, 52, 49, 41, 41, 41, 47, 00, 49, 32, 36, 40, 32, 34, 32, 32, 32, 36, 63, 32, 32, 32, 32, 33, 32, 32, 32, 32, 34, 47, 00},
			{02, 02, 02, 50, 41, 41, 41, 47, 00, 49, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 37, 35, 32, 32, 36, 32, 32, 32, 32, 47, 00},
			{32, 32, 32, 35, 32, 32, 32, 47, 00, 49, 34, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 37, 35, 32, 47, 00},
			{32, 34, 32, 33, 32, 32, 32, 47, 00, 49, 32, 32, 32, 36, 39, 32, 34, 33, 37, 32, 32, 36, 34, 32, 32, 32, 33, 38, 39, 32, 47, 00},
			{52, 52, 52, 52, 52, 52, 52, 61, 00, 59, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 60, 00},
			{02, 05, 02, 02, 02, 04, 02, 02, 00, 01, 02, 02, 04, 02, 02, 02, 02, 05, 02, 02, 02, 05, 02, 02, 02, 02, 02, 02, 04, 02, 03, 00}}},
		{0, {{00, 56, 52, 52, 23, 52, 23, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 49, 41, 41, 41, 47, 52, 52, 52, 52, 52, 55, 00},
			{00, 14, 02, 04, 19, 05, 19, 02, 02, 04, 02, 02, 02, 02, 02, 02, 02, 02, 05, 02, 50, 41, 41, 41, 48, 02, 02, 04, 02, 02, 11, 00},
			{00, 49, 38, 32, 27, 36, 27, 32, 32, 33, 32, 39, 32, 34, 32, 32, 32, 32, 38, 32, 39, 32, 34, 36, 38, 39, 34, 32, 36, 32, 47, 00},
			{00, 49, 32, 33, 34, 62, 35, 32, 32, 32, 40, 32, 33, 32, 32, 32, 32, 34, 32, 32, 40, 32, 32, 32, 32, 32, 32, 33, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 32, 34, 32, 32, 36, 32, 32, 32, 36, 32, 32, 32, 34, 32, 36, 32, 34, 32, 32, 37, 35, 36, 32, 47, 00},
			{00, 49, 36, 32, 32, 33, 32, 36, 32, 32, 32, 45, 52, 52, 52, 52, 52, 52, 52, 52, 46, 32, 32, 33, 32, 34, 38, 39, 32, 37, 47, 00},
			{00, 49, 32, 32, 40, 32, 32, 32, 32, 33, 34, 47, 02, 04, 02, 02, 05, 02, 02, 02, 49, 32, 32, 32, 32, 40, 36, 32, 34, 38, 47, 00},
			{00, 49, 32, 32, 38, 39, 32, 36, 32, 32, 32, 47, 00, 00, 00, 00, 00, 00, 00, 00, 49, 32, 35, 34, 32, 32, 34, 32, 33, 32, 47, 00},
			{00, 49, 32, 34, 32, 32, 32, 32, 37, 35, 32, 47, 52, 52, 52, 52, 52, 52, 52, 52, 49, 32, 39, 32, 32, 33, 32, 32, 36, 32, 47, 00},
			{00, 49, 32, 32, 32, 34, 32, 33, 38, 39, 34, 48, 02, 02, 02, 02, 02, 02, 02, 02, 50, 32, 32, 36, 32, 32, 32, 32, 34, 32, 47, 00},
			{00, 49, 37, 40, 32, 32, 34, 32, 32, 32, 32, 38, 39, 32, 32, 34, 32, 32, 32, 38, 39, 34, 32, 32, 37, 35, 32, 40, 32, 32, 47, 00},
			{00, 49, 33, 32, 36, 32, 32, 45, 52, 52, 46, 32, 33, 37, 35, 32, 32, 36, 32, 33, 32, 45, 52, 52, 46, 39, 32, 33, 36, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 47, 05, 02, 49, 36, 32, 38, 39, 32, 33, 32, 34, 32, 36, 47, 02, 04, 49, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 47, 00, 00, 49, 32, 32, 32, 32, 34, 32, 32, 39, 32, 32, 47, 00, 00, 49, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 32, 36, 32, 33, 32, 47, 00, 00, 49, 38, 32, 36, 32, 32, 32, 32, 32, 36, 32, 47, 00, 00, 49, 36, 32, 38, 39, 32, 47, 00},
			{00, 49, 34, 32, 32, 32, 32, 47, 00, 00, 49, 33, 32, 32, 32, 38, 34, 36, 32, 33, 32, 47, 00, 00, 49, 32, 32, 32, 34, 32, 47, 00},
			{00, 49, 37, 32, 32, 32, 36, 47, 00, 00, 49, 32, 32, 34, 33, 32, 37, 35, 32, 32, 34, 47, 00, 00, 49, 36, 32, 33, 32, 32, 47, 00},
			{00, 49, 32, 33, 32, 34, 32, 47, 00, 00, 49, 35, 32, 39, 32, 36, 38, 39, 32, 32, 32, 47, 00, 00, 49, 35, 32, 36, 37, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 47, 52, 52, 49, 39, 32, 32, 32, 32, 32, 32, 36, 32, 32, 47, 52, 52, 49, 39, 32, 32, 32, 32, 47, 00},
			{00, 49, 36, 40, 35, 32, 32, 48, 02, 02, 50, 36, 32, 34, 32, 36, 32, 32, 33, 32, 32, 48, 02, 02, 50, 32, 32, 40, 34, 32, 47, 00},
			{00, 49, 32, 34, 32, 36, 32, 38, 34, 32, 39, 32, 33, 32, 35, 32, 32, 34, 37, 32, 32, 38, 32, 33, 39, 36, 33, 37, 35, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 32, 32, 36, 32, 45, 52, 52, 52, 52, 52, 52, 52, 52, 46, 32, 32, 32, 32, 32, 32, 38, 39, 36, 47, 00},
			{00, 49, 33, 32, 32, 32, 34, 32, 33, 32, 32, 47, 02, 02, 05, 02, 04, 02, 04, 02, 49, 32, 32, 32, 32, 34, 32, 32, 33, 37, 47, 00},
			{00, 49, 32, 37, 35, 36, 32, 32, 38, 32, 36, 47, 00, 00, 00, 00, 00, 00, 00, 00, 49, 39, 33, 32, 32, 37, 35, 32, 32, 38, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 36, 32, 34, 32, 47, 52, 52, 52, 52, 52, 52, 52, 52, 49, 34, 32, 32, 32, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 32, 32, 32, 32, 32, 32, 32, 32, 32, 48, 02, 02, 02, 02, 02, 02, 02, 02, 50, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 00},
			{00, 49, 36, 38, 39, 32, 34, 33, 37, 32, 35, 38, 32, 34, 32, 36, 32, 32, 34, 32, 39, 32, 38, 32, 36, 35, 32, 34, 39, 36, 47, 52},
			{00, 49, 32, 33, 34, 32, 32, 32, 32, 32, 32, 32, 33, 32, 32, 32, 34, 32, 36, 32, 32, 32, 32, 32, 32, 39, 32, 33, 32, 32, 48, 02},
			{00, 49, 32, 32, 40, 32, 32, 36, 32, 32, 40, 32, 32, 37, 35, 32, 32, 32, 32, 32, 32, 40, 32, 34, 32, 36, 40, 37, 35, 32, 32, 33},
			{00, 49, 34, 32, 36, 33, 32, 32, 32, 32, 32, 34, 32, 36, 32, 32, 33, 32, 34, 32, 32, 32, 36, 32, 33, 32, 34, 38, 39, 32, 36, 32},
			{00, 59, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 53, 53},
			{00, 12, 02, 02, 02, 04, 02, 02, 02, 02, 02, 02, 04, 02, 02, 02, 02, 05, 02, 02, 02, 02, 05, 02, 02, 02, 02, 02, 04, 02, 02, 02}}} };

	//Tile: Tile list ranges
	const unsigned char DOOR_START_NUM = TILE_NUM - 3; //Where the doors start on the tile list
	const Dim2Di WALL_RANGE = { 1, 20 }; //Where the wall tiles are in the list
	const Dim2Di FLOOR_RANGE = { 32, 39 }; //Where the floor tiles are in the list
	const Dim2Di WALL_SIDE_RANGE = { 45, 50 }; //Where the wall sides are in the list
	const Dim2Di WALL_TOP_RANGE = { 51, 57 }; //Where the wall tops are in the list
	const Dim2Di WALL_CORNER_RANGE = { 58, 61 }; //Where the wall corners are in the list

	//Enums
	enum TILES { //Tile IDs
		T_DARKNESS, T_WALL_LEFT, T_WALL_MID, T_WALL_RIGHT, T_WALL_HOLE_1, T_WALL_HOLE_2, T_WALL_BANNER_BLUE, T_WALL_BANNER_GREEN,
		T_WALL_BANNER_YELLOW, T_WALL_BANNER_RED, T_WALL_CORNER_LEFT, T_WALL_CORNER_RIGHT, T_WALL_CORNER_FRONT_LEFT, T_WALL_CORNER_FRONT_RIGHT,
		T_WALL_IN_CORNER_MID_LEFT, T_WALL_IN_CORNER_MID_RIGHT, T_WALL_COLUMN_MID, T_COLUMN_MID, T_LAVA_FOUNTAIN_MID, T_WATER_FOUNTAIN_MID, T_WALL_GOO,
		T_COLUMN_TOP, T_WALL_COLUMN_TOP, T_FOUNTAIN_TOP, T_WALL_COLUMN_BASE, T_COLUMN_BASE, T_LAVA_FOUNTAIN_BASIN, T_WATER_FOUNTAIN_BASIN, T_WALL_GOO_FLOOR,
		T_EDGE, T_WALL_COLUMN_TOP_FLOOR, T_FOUNTAIN_TOP_FLOOR, T_FLOOR_1, T_FLOOR_2, T_FLOOR_3, T_FLOOR_4, T_FLOOR_5, T_FLOOR_6, T_FLOOR_7, T_FLOOR_8,
		T_ENEMY_SPAWNER, T_FLOOR_SPIKES, T_FLOOR_LADDER, T_HOLE, T_STAIRS, T_WALL_SIDE_TOP_RIGHT, T_WALL_SIDE_TOP_LEFT, T_WALL_SIDE_MID_RIGHT,
		T_WALL_SIDE_FRONT_RIGHT, T_WALL_SIDE_MID_LEFT, T_WALL_SIDE_FRONT_LEFT, T_WALL_TOP_LEFT, T_WALL_TOP_MID, T_WALL_TOP_RIGHT, T_WALL_CORNER_TOP_LEFT,
		T_WALL_CORNER_TOP_RIGHT, T_WALL_IN_CORNER_T_TOP_LEFT, T_WALL_IN_CORNER_T_TOP_RIGHT, T_WALL_CORNER_BOTTOM_LEFT, T_WALL_IN_CORNER_L_TOP_LEFT,
		T_WALL_CORNER_BOTTOM_RIGHT, T_WALL_IN_CORNER_L_TOP_RIGHT, T_WATER_SHOP, T_LAVA_SHOP, T_DOOR_UP, T_DOOR_DOWN
	};
}