#include "Tool.h"
#include <iostream>

using namespace std;

Tool::Tool()
{
	_name = "Tool";
	_strength = 10;
	_range = 14;
	_miningSpeed = 2;
	_durability = 80;
	_electricSpeed = 5;
}

Tool::Tool(string& name, int miningSpeed, int durability)
{
	_name = name;
	_miningSpeed = miningSpeed;
	_durability = durability;
	_electricSpeed = 5;
}

Tool::Tool(string& name, int strength, int range, int miningSpeed, int durability, int electricSpeed)
	: Item(name, strength, range)
{
	_miningSpeed = miningSpeed;
	_durability = durability;
	_electricSpeed = electricSpeed;
}

Tool::Tool(const Tool& tool)
	: Item(tool)
{
	_miningSpeed = tool._miningSpeed;
	_durability = tool._durability;
	_electricSpeed = tool._electricSpeed;
}

Tool::~Tool() = default;

int Tool::GetMiningSpeed() const
{
	return _miningSpeed;
}

int Tool::GetDurability() const
{
	return _durability;
}

int Tool::GetElectricSpeed() const
{
	return _electricSpeed;
}

void Tool::SetMiningSpeed(int miningSpeed)
{
	_miningSpeed = miningSpeed;
}

void Tool::SetDurability(int durability)
{
	_durability = durability;
}

void Tool::SetElectricSpeed(int electricSpeed)
{
	_electricSpeed = electricSpeed;
}

void Tool::ApplyElectricSpeed()
{
	_miningSpeed *= _electricSpeed;
}

void Tool::Print() const
{
	cout << "Name: " << _name << endl;
	cout << "Strength: " << _strength << endl;
	cout << "Range: " << _range << endl;
	cout << "Mining speed: " << _miningSpeed << endl;
	cout << "Durability: " << _durability << endl;
	cout << "Electric speed: " << _electricSpeed << endl;
}
