#pragma once
#include <string>
/**
 * @file Item.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the definition of the Item class from which the Weapon
 * and Tool extend
 *
 * Properties:
 * -----------
 * > _name: string - This is the name of the item
 * > _strength: int - This is the strength of the item
 * > _range: int - This is the range of the item
 *
 * Methods:
 * --------
 * > Item() - This is the default constructor for the Item class
 * > Item(string name, int strength, int range) - This is the constructor for the Item class
 * > ~Item() - This is the destructor for the Item class
 * > Getters and Setters for the properties
 * > PowerUp(int strength, int range) - This is the method that powers up the item
 * > virtual Print() - This is the method that prints the item
 */
class Item
{
protected:
	std::string _name;
	int _strength;
	int _range;

public:
	/**
	 * @brief This is the default constructor for the Item class
	*/
	Item();

	/**
	 * @brief This is the constructor for the Item class
	 * @param name - the name of the item
	 * @param strength - the strength of the item
	 * @param range - the range of the item
	*/
	Item(std::string& name, int strength, int range);

	/**
	 * @brief This is the copy constructor for the Item class
	 * @param item - the item to copy
	*/
	Item(const Item& item);

	/**
	 * @brief This is the destructor for the Item class
	*/
	virtual ~Item();

	/**
	 * @brief Getter for the name of the item
	 * @return a string representing the name of the item
	*/
	std::string GetName() const;

	/**
	 * @brief Getter for the strength of the item
	 * @return an integer representing the strength of the item
	*/
	int GetStrength() const;

	/**
	 * @brief Getter for the range of the item
	 * @return an integer representing the range of the item
	*/
	int GetRange() const;

	/**
	 * @brief Setter for the name of the item
	 * @param name - the name of the item
	*/
	void SetName(std::string& name);

	/**
	 * @brief Setter for the strength of the item
	 * @param strength - the strength of the item
	*/
	void SetStrength(int strength);

	/**
	 * @brief Setter for the range of the item
	 * @param range - the range of the item
	*/
	void SetRange(int range);

	/**
	 * @brief This is the method that powers up the item
	 * @param strength - the strength to power up the item with
	 * @param range - the range to power up the item with
	*/
	void PowerUp(int strength, int range);

	/**
	 * @brief This is the dereference operator overload for the Item class
	 * @return a reference to the item
	*/
	const Item& operator*();

	/**
	 * @brief This is the method that prints the item
	*/
	virtual void Print() const;
};