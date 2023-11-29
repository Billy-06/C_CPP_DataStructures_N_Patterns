#include "Weapon.h"
#include <iostream>

Weapon::Weapon()
{
	_name = "Default Weapon";
	_strength = 10;
	_range = 14;
	_attackSpeed = 2;
	_lethalPotion = 5;
}

Weapon::Weapon(std::string& name, int attackSpeed, int lethalPotion)
{
	_name = name;
	_strength = 10;
	_range = 14;
	_attackSpeed = attackSpeed;
	_lethalPotion = lethalPotion;
}

Weapon::Weapon(std::string& name, int strength, int range, int attackSpeed, int lethalPotion)
	: Item(name, strength, range)
{
	_attackSpeed = attackSpeed;
	_lethalPotion = lethalPotion;
}

Weapon::~Weapon() = default;

int Weapon::GetAttackSpeed() const
{
	return _attackSpeed;
}

void Weapon::SetAttackSpeed(int attackSpeed)
{
	_attackSpeed = attackSpeed;
}

int Weapon::GetLethalPotion() const
{
	return _lethalPotion;
}

void Weapon::SetLethalPotion(int lethalPotion)
{
	_lethalPotion = lethalPotion;
}

void Weapon::ApplyLethalPotion()
{
	_strength *= _lethalPotion;
}

void Weapon::Print() const
{
	std::cout << "Weapon: " << _name << std::endl;
	std::cout << "Strength: " << _strength << std::endl;
	std::cout << "Range: " << _range << std::endl;
	std::cout << "Attack Speed: " << _attackSpeed << std::endl;
	std::cout << "Lethal Potion: " << _lethalPotion << std::endl;
}