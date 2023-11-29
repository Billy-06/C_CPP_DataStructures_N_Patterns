#include "Environ.h"
#include <iostream>

using namespace std;

Environ::Environ()
{
	_name = "New Environ";
	_description = "New Environ Description, healing power enabled";
	_hazard = false;
	_damage = 0;
	_healing = 5;
}

Environ::Environ(string& name, string& description, bool hazard, int damage, int healing)
{
	_name = name;
	_description = description;
	_hazard = hazard;
	_damage = damage;
	_healing = healing;
}

Environ::Environ(const Environ& other)
{
	_name = other._name;
	_description = other._description;
	_hazard = other._hazard;
	_damage = other._damage;
	_healing = other._healing;
}

Environ::~Environ() = default;

string Environ::GetName() const
{
	return _name;
}

string Environ::GetDescription() const
{
	return _description;
}

bool Environ::GetHazard() const
{
	return _hazard;
}

int Environ::GetDamage() const
{
	return _damage;
}

int Environ::GetHealing() const
{
	return _healing;
}

void Environ::SetName(string& name)
{
	_name = name;
}

void Environ::SetDescription(string& description)
{
	_description = description;
}

void Environ::ToggleHazard()
{
	_hazard = !_hazard;
}

void Environ::SetDamage(int damage)
{
	_damage = damage;
}

void Environ::SetHealing(int healing)
{
	_healing = healing;
}

void Environ::Print() const
{
	cout << "Name: " << _name << endl;
	cout << "Description: " << _description << endl;
	cout << "Hazard: " << ( (_hazard) ? "True" : "False" ) << endl;
	cout << "Damage: " << _damage << endl;
	cout << "Healing: " << _healing << endl;
	cout << endl;
}
