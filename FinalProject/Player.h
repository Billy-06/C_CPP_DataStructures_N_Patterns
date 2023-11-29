#pragma once
#include "Character.h"
#include <string>

/**
 * @file Player.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file is the header file for the Player class which extends
 * the Character class. It contains the declaration of the Player class and its
 * unique methods.
 *
 * Properties:
 * -----------
 * > _score: int - This is the score of the player
 *
 * Methods:
 * --------
 * > Player(): Constructor
 * > Player(name: string, health: int, ammo: int): Constructor
 * > ~Player(): Destructor
 * > Move(Location* loc): Moves the player to the specified location
 * > ShowStats(): Displays the player's stats
 *
 */
class Player : public Character
{
private:
	int _score;

public:
	/**
	 * @brief This is the default constructor
	*/
	Player();

	/**
	 * @brief This is the overloaded constructor
	 * @param name - the name of the player
	 * @param health - the health of the player
	 * @param ammo - the ammo of the player
	*/
	Player(std::string name, int health, int ammo);

	/**
	 * @brief This is the copy constructor that takes a player type
	 * @param player - the player to copy
	*/
	Player(const Player& player);

	/**
	 * @brief This is the copy constructor that takes a character type
	 * @param player - the character to copy
	*/
	Player(const Character& player);

	/**
	 * @brief This is the destructor
	*/
	~Player() override;

	/**
	 * @brief This method moves the player to the specified location
	 * @param loc - the location to move the player to
	*/
	void Move(Location* loc);

	/**
	 * @brief This method displays the player's stats
	*/
	void ShowStats() override;
};