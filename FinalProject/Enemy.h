#pragma once
#include "Character.h"
/**
 * @file Enemy.h
 * @author Billy Ndegwah Micah
 *
 * Description: Enemy class header file with the declaration of the class Enemy
 * that inherits from the Character class.
 *
 * Properties:
 * -----------
 * > Extends from the Character class
 *
 * Methods:
 * --------
 * > Enemy() - Constructor
 * > Enemy(string name, int health, int ammo) - Overloaded constructor
 * > Enemy(const Enemy& enemy) - Copy constructor
 * > ~Enemy() - Destructor
 * > Slay(character: Character*) - Method to attack a character
 *
 */
class Enemy : public Character
{

public:
	/**
	 * @brief This is the default constructor
	*/
	Enemy();

	/**
	 * @brief This is the overloaded constructor
	 * @param name - the name of the enemy
	 * @param health - the health of the enemy
	 * @param ammo - the ammo of the enemy
	*/
	Enemy(std::string name, int health, int ammo);

	/**
	 * @brief This is the copy constructor that takes an enemy type
	 * @param enemy - the enemy to copy
	*/
	Enemy(const Enemy& enemy);

	/**
	 * @brief This is the copy constructor that takes a character type
	 * @param enemy - the character to copy
	*/
	Enemy(const Character& enemy);

	/**
	 * @brief This is the destructor
	*/
	~Enemy() override;

	/**
	 * @brief This is the method to attack a character
	 * @param character - the target character
	*/
	void Slay(Character* character);
};