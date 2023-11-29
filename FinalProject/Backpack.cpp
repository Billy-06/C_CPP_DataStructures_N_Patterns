#include "Backpack.h"
#include <vector>
#include <string>
#include <iostream>

Backpack::Backpack()
{
	std::vector<std::string> itemNames = { "Binoculars", "Hoe", "Hammer", "Boomerang" };
	std::vector<std::string> weaponNames = {
		"Bow & Arrow", "Spear", "Thor Rod", "Pistol",
		"Sword", "Machine Gun", "Whip", "Boomerang"
	};

	Item items[4];

	for (int i = 0; i < 4; ++i)
	{
		Item item = Item(itemNames[i], 1, 1);
		items[i] = item;
	}
	_itemBag = Iterator1D<Item>(items, 8);

	Weapon weapons[8];

	for (int j = 0; j < 8; ++j)
	{
		Weapon weapon = Weapon(weaponNames[j], 12, 14);
		weapons[j] = weapon;
	}
	_weaponBag = Iterator1D<Weapon>(weapons, 8);
	_capacity = _itemBag.GetSize() + _weaponBag.GetSize();

}

Backpack::Backpack(const Backpack& backpack)
{
	_itemBag = backpack._itemBag;
	_weaponBag = backpack._weaponBag;
	_capacity = backpack._capacity;
}

Backpack::~Backpack() = default;

Iterator1D<Item> Backpack::GetItemBag() const
{
	return _itemBag;
}

Iterator1D<Weapon> Backpack::GetWeaponBag() const
{
	return _weaponBag;
}

int Backpack::GetCapacity() const
{
	return _capacity;
}

void Backpack::SetItemBag(Iterator1D<Item>& itemBag)
{
	_itemBag = itemBag;
}

void Backpack::SetWeaponBag(Iterator1D<Weapon>& weaponBag)
{
	_weaponBag = weaponBag;
}

void Backpack::AddItem(Item* item)
{
	const int new_size = _itemBag.GetSize() + 1;
	Item* items = new Item[new_size];

	for (int i = 0; i < _itemBag.GetSize(); ++i)
	{
		items[i] = *_itemBag.GetArray()[i];
	}
	items[_itemBag.GetSize()] = *item;

	_itemBag.SetArray(items);
}

void Backpack::RemoveItem(Item* item)
{
	const int new_size = _itemBag.GetSize() - 1;
	Item* items = new Item[new_size];

	int j = 0;
	for (int i = 0; i < _itemBag.GetSize(); ++i)
	{
		if (&_itemBag.GetArray()[i] != item)
		{
			items[j] = *_itemBag.GetArray()[i];
			++j;
		}
	}

	_itemBag.SetArray(items);
}

bool Backpack::SearchItem(Item* item) const
{
	for (int i = 0; i < _itemBag.GetSize(); ++i)
	{
		if (&_itemBag.GetArray()[i] == item)
		{
			std::cout << "Item found!" << std::endl;
			return true;
		}
	}
	std::cout << "Item not found!" << std::endl;
	return false;
}

bool Backpack::SearchWeapon(Weapon* weapon) const
{
	for (int i = 0; i < _weaponBag.GetSize(); ++i)
	{
		if (&_weaponBag.GetArray()[i] == weapon)
		{
			std::cout << "Weapon found!" << std::endl;
			return true;
		}
	}
	std::cout << "Weapon not found!" << std::endl;
	return false;
}

void Backpack::DisplayItems() const
{
	std::cout << "Items in the Backpack:" << std::endl;
	for (int i = 0; i < _itemBag.GetSize(); ++i)
	{
		std::cout << _itemBag[i].GetName() << std::endl;
	}
}

void Backpack::DisplayWeapons() const
{
	std::cout << "Weapons in the Backpack:" << std::endl;
	for (int i = 0; i < _weaponBag.GetSize(); ++i)
	{
		std::cout << _weaponBag.GetArray()[i].GetName() << std::endl;
	}
}

void Backpack::Display() const
{
	DisplayItems();
	DisplayWeapons();
}