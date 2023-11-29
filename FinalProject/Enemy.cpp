#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy()
{
	_name = "Default Character";
	_health = 100;
	_ammo = 80;
	 _backpack = new Backpack();
	 _inHand = &_backpack->GetItemBag().GetCurrentItem();
	_loc = new Location(0, 0);
	_attackMoves = {
		new ActionTree(),
		new ActionTree(),
		new ActionTree(),
	};
	_maxPower = 200;
}

Enemy::Enemy(string name, int health, int ammo)
	: Character(name, health, ammo)
{
	 _backpack = new Backpack();
	 _inHand = &_backpack->GetItemBag().GetCurrentItem();
	_loc = new Location(0, 0);
	_attackMoves = {
		new ActionTree(),
		new ActionTree(),
		new ActionTree(),
	};
	_maxPower = 200;
}

Enemy::Enemy(const Enemy& enemy) : Character(enemy)
{
	_name = enemy._name;
	_health = enemy._health;
	_ammo = enemy._ammo;
	 _backpack = enemy._backpack;
	 _inHand = enemy._inHand;
	_loc = enemy._loc;
	_attackMoves = enemy._attackMoves;
	_maxPower = enemy._maxPower;
}

Enemy::Enemy(const Character& enemy) : Character(enemy)
{
	 _backpack = new Backpack();
	 _inHand = &_backpack->GetItemBag().GetCurrentItem();
	_loc = new Location(0, 0);
	_attackMoves = {
				new ActionTree(),
				new ActionTree(),
				new ActionTree(),
			};
	_maxPower = 200;
}

Enemy::~Enemy()
{
	delete _backpack;
	delete _loc;
	for (auto& move : _attackMoves)
	{
		delete move;
	}
}

void Enemy::Slay(Character* character)
{
	cout << _name << " slays " << character->GetName() << endl;
	_attackMoves[0]->PreOrderTraverse();

	character->SetHealth(character->GetHealth() - _attackMoves[0]->GetDamage());
}