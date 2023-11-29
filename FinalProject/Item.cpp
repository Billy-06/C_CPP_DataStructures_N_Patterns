#include "Item.h"
#include <iostream>

using namespace std;

Item::Item()
{
	_name = "New Item";
	_strength = 10;
	_range = 14;
}

Item::Item(string& name, int strength, int range)
{
	_name = name;
	_strength = strength;
	_range = range;
}

Item::Item(const Item& item)
{
	_name = item._name;
	_strength = item._strength;
	_range = item._range;
}

Item::~Item() = default;

string Item::GetName() const
{
	return _name;
}

int Item::GetStrength() const
{
	return _strength;
}

int Item::GetRange() const
{
	return _range;
}

void Item::SetName(string& name)
{
	_name = name;
}

void Item::SetStrength(int strength)
{
	_strength = strength;
}

void Item::SetRange(int range)
{
	_range = range;
}

void Item::PowerUp(int strength, int range)
{
	_strength += strength;
	_range += range;

	cout << "Powered up!" << endl;
	cout << "Strength: " << _strength << endl;
	cout << "Range: " << _range << endl;
}

const Item& Item::operator*()
{
	return *this;
}

void Item::Print() const
{
	cout << "\tName: " << _name << endl;
	cout << "\tStrength: " << _strength << endl;
	cout << "\tRange: " << _range << endl;
	cout << "\t------------------" << endl;
}