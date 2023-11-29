#pragma once
#include "Character.h"
#include "Environ.h"
#include "TileSpace.h"
/**
 * @file Map.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the description of the Map class
 *
 * Properties:
 * -----------
 * > tileSpace: TileSpace - The tile space of the map
 * > environs: Environ - The environment of the map
 * > characters: Character - The characters in the map
 *
 * Methods:
 * > Map() - Default constructor
 * > Map(TileSpace, Environ, Character) - Constructor
 * > GetCharacters() - Returns the characters in the map
 * > GetEnviron() - Returns the environment of the map
 * > TakeCommands() - Takes commands from the user
 *
 */
class Map
{
public:
	TileSpace<Tile*>* tileSpace;
	std::vector<Environ*> environs;
	std::vector <Character*> characters;

	Map();
	Map(TileSpace<Tile*>* tSpace, std::vector<Environ*>& env, std::vector<Character*>& chrcters);
	~Map();
	std::vector<Character*> GetCharacters() const;
	std::vector<Environ*> GetEnviron() const;

	void DemoUnidirectional() const;
	void DemoTrees() const;
	void DemoBidirectional() const;
	void DemoStack() const;
	void DemoIterators() const;
	void ClearConsole() const;
	void ShowEnviron() const;
	void ShowCharacters() const;
	void Fight();

	static void TakeCommands();
	static void Begin();
};