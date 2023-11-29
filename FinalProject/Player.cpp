#include "Player.h"

using namespace std;
Player::Player()
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
		new ActionTree()
	};
	_maxPower = 200;
	_score = 0;
}

Player::Player(string name, int health, int ammo)
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
	_score = 0;
}

Player::Player(const Player& player)
	: Character(player)
{
	_backpack = player._backpack;
	_inHand = player._inHand;
	_loc = player._loc;
	_attackMoves = player._attackMoves;
	_maxPower = player._maxPower;
	_score = player._score;
}

Player::Player(const Character& player)
	: Character(player)
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
	_score = 0;
}

Player::~Player()
{
	delete _backpack;
	delete _loc;
	for (auto& move : _attackMoves)
	{
		delete move;
	}
}

void Player::Move(Location* loc)
{
	SetLocation(loc);
}

void Player::ShowStats()
{
	cout << "Name: " << GetName() << endl;
	cout << "Health: " << GetHealth() << endl;
	cout << "Ammo: " << GetAmmo() << endl;
	cout << "Location: " << GetLocation()->x << ", " << GetLocation()->y << endl;
	cout << "In Hand: " << GetInHand()->GetName() << endl;
	cout << "Backpack: " << endl;
	GetBackpack()->Display();
	cout << "Attack Moves: " << endl;
	for (int i = 0; i < static_cast<int>(_attackMoves.size()); i++)
	{
		cout << i << ": " << _attackMoves[i]->GetCurrent()->GetAction() << endl;
	}
	cout << endl;
	cout << "Player Score: " << _score << endl;
	cout << endl;
}