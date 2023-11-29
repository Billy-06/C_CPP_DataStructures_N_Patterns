#pragma once
#include "Item.h"

/**
 * @file Weapon.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the header file for the Weapon class that extends from
 * the Item class
 *
 * Properties:
 * -----------
 * > _attackSpeed: int
 * > _lethalPotion: int
 *
 * Methods:
 * --------
 * > Weapon() - default constructor
 * > Weapon(string name, int attackSpeed, int lethalPotion) - overloaded constructor
 * > ~Weapon() - destructor
 * > Getters and Setter for the properties
 * > ApplyLethalPotion() - applies the lethal potion to the weapon
 * > Print() - prints the weapon's properties
 *
 */
class Weapon : public Item
{
private:
	int _attackSpeed;
	int _lethalPotion;

public:
	/**
	 * @brief This is the default constructor
	*/
	Weapon();

	/**
	 * @brief This is the overloaded constructor
	 * @param name - the name of the weapon
	 * @param attackSpeed - the attack speed of the weapon
	 * @param lethalPotion - the lethal potion of the weapon
	*/
	Weapon(std::string& name, int attackSpeed, int lethalPotion);

	/**
	 * @brief This is another overloaded constructor
	 * @param name - the name of the weapon
	 * @param strength - the strength of the weapon
	 * @param range - the range of the weapon
	 * @param attackSpeed - teh attack speed of the weapon
	 * @param lethalPotion - teh lethal potion of the weapon
	*/
	Weapon(std::string& name, int strength, int range, int attackSpeed, int lethalPotion);

	/**
	 * @brief This is the copy constructor
	*/
	~Weapon() override;

	/**
	 * @brief Getter for the attack speed
	 * @return an int representing the attack speed
	*/
	int GetAttackSpeed() const;

	/**
	 * @brief Setter for the attack speed
	 * @param attackSpeed - the desired attack speed
	*/
	void SetAttackSpeed(int attackSpeed);

	/**
	 * @brief Getter for the lethal potion
	 * @return an int representing the lethal potion
	*/
	int GetLethalPotion() const;

	/**
	 * @brief Setter for the lethal potion
	 * @param lethalPotion - the desired lethal potion
	*/
	void SetLethalPotion(int lethalPotion);

	/**
	 * @brief This method applies the lethal potion to the weapon
	*/
	void ApplyLethalPotion();

	/**
	 * @brief This method prints the weapon's properties
	*/
	void Print() const override;
};
