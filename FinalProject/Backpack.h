#pragma once
#include "Iterator1D.h"
#include "Item.h"
#include "Weapon.h"

/**
 * @file Backpack.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the header file for the Backpack class.
 *
 * Properties:
 * -----------
 * > _itemBag: Iterator1D<Item> - A 1D iterator of Items.
 * > _weaponBag: Iterator2D<Weapon> - A 2D iterator of Weapons.
 * > _capacity: int - The maximum number of items that can be stored in the backpack.
 *
 * Methods:
 * --------
 * > Backpack() - Default constructor.
 * > Backpack(const Backpack& backpack) - Copy constructor.
 * > ~Backpack() - Destructor.
 * > Getter and setter methods for the properties.
 * > AddItem(item: Item*) - Adds an item to the backpack.
 * > RemoveItem(item: Item*) - Removes an item from the backpack.
 * > SearchItem(item: Item*) - Searches for an item in the backpack.
 * > SearchWeapon(weapon: Weapon*) - Searches for a weapon in the backpack.
 * > DisplayItems() - Displays all the items in the backpack.
 * > DisplayWeapons() - Displays all the weapons in the backpack.
 * > Display() - Displays all the items and weapons in the backpack.
 *
 */
class Backpack
{
private:
	Iterator1D<Item> _itemBag;
	Iterator1D<Weapon> _weaponBag;
	int _capacity;

public:
	/**
	 * @brief This is the default constructor
	*/
	Backpack();

	/**
	 * @brief This is the copy constructor
	 * @param backpack - the backpack to copy
	*/
	Backpack(const Backpack& backpack);

	/**
	 * @brief This is the destructor
	*/
	~Backpack();

	/**
	 * @brief Getter for the item bag
	 * @return an iterator of items
	*/
	Iterator1D<Item> GetItemBag() const;

	/**
	 * @brief Getter for the weapon bag
	 * @return an iterator of weapons
	*/
	Iterator1D<Weapon> GetWeaponBag() const;

	/**
	 * @brief Getter for the capacity
	 * @return an integer representing the capacity
	*/
	int GetCapacity() const;

	/**
	 * @brief Setter for the item bag
	 * @param itemBag - the item bag to set
	*/
	void SetItemBag(Iterator1D<Item>& itemBag);

	/**
	 * @brief Setter for the weapon bag
	 * @param weaponBag - the weapon bag to set
	*/
	void SetWeaponBag(Iterator1D<Weapon>& weaponBag);

	/**
	 * @brief This method adds an item to the backpack
	 * @param item - the item to add
	*/
	void AddItem(Item* item);

	/**
	 * @brief This method removes an item from the backpack
	 * @param item - the item to remove
	*/
	void RemoveItem(Item* item);

	/**
	 * @brief This method searches for an item in the backpack
	 * @param item - the item to search for
	 * @return a boolean representing whether the item was found or not
	*/
	bool SearchItem(Item* item) const;

	/**
	 * @brief This method searches for a weapon in the backpack
	 * @param weapon - the weapon to search for
	 * @return a boolean representing whether the weapon was found or not
	*/
	bool SearchWeapon(Weapon* weapon) const;

	/**
	 * @brief This method displays all the items in the backpack
	*/
	void DisplayItems() const;

	/**
	 * @brief This method displays all the weapons in the backpack
	*/
	void DisplayWeapons() const;

	/**
	 * @brief This method displays all the items and weapons in the backpack
	*/
	void Display() const;
};