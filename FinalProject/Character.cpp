#include "Character.h"
#include <iostream>
Character::Character()
{
	_name = "Default Character";
	_health = 100;
	_ammo = 80;
	_backpack = new Backpack();
	_inHand = &_backpack->GetItemBag().GetCurrentItem();
	_loc = new Location(0,0);
	_attackMoves = {
		new ActionTree(),
		new ActionTree(),
		new ActionTree(),
	};
	_maxPower = 200;
	_messages = new Message();
}

Character::Character(std::string& name, int health, int ammo)
{
	_name = name;
	_health = health;
	_ammo = ammo;
	_backpack = new Backpack();
	_inHand = &_backpack->GetItemBag().GetCurrentItem();
	_loc = new Location(0, 0);
	_attackMoves = {
		new ActionTree(),
		new ActionTree(),
		new ActionTree(),
	};
	_maxPower = 200;
	_messages = new Message();
}

Character::Character(const Character& character)
{
	_name = character._name;
	_health = character._health;
	_ammo = character._ammo;
	_backpack = character._backpack;
	_inHand = character._inHand;
	_loc = character._loc;
	_attackMoves = character._attackMoves;
	_maxPower = character._maxPower;
}

Character::~Character()
{
	delete _backpack;
	delete _loc;
	for (auto& move : _attackMoves)
	{
		delete move;
	}
}

std::string Character::GetName() const
{
	return _name;
}

int Character::GetHealth() const
{
	return _health;
}

Message Character::GetMessages() const
{
	return *_messages;
}

int Character::GetAmmo() const
{
	return _ammo;
}

Backpack* Character::GetBackpack() const
{
	return _backpack;
}

Item* Character::GetInHand() const
{
	return _inHand;
}

Location* Character::GetLocation() const
{
	return _loc;
}

std::vector<ActionTree*> Character::GetAttackMoves() const
{
	return _attackMoves;
}

int Character::GetMaxPower() const
{
	return _maxPower;
}

void Character::SetName(std::string& name)
{
	_name = name;
}

void Character::SetMessages(Message& messages)
{
	_messages = &messages;
}

void Character::SetHealth(int health)
{
	_health = health;
}

void Character::SetAmmo(int ammo)
{
	_ammo = ammo;
}

void Character::SetBackpack(Backpack* backpack)
{
	_backpack = backpack;
}

void Character::SetInHand(Item* inHand)
{
	_inHand = inHand;
}

void Character::SetLocation(Location* loc)
{
	_loc = loc;
}

void Character::SetAttackMoves(std::vector<ActionTree*>& attackMoves)
{
	_attackMoves = attackMoves;
}

void Character::SetMaxPower(int maxPower)
{
	_maxPower = maxPower;
}

const Character& Character::operator*() const
{
	return *this;
}

void Character::Attack(Character* target, int moveIndex)
{
	_attackMoves[moveIndex]->InOrderTraverse();
	if (target->GetHealth() - _attackMoves[moveIndex]->GetDamage() < 0)
	{
		target->SetHealth(0);
		std::cout << target->GetName() << " is slain" << std::endl;
	}
	else
	{
		target->SetHealth(target->GetHealth() - _attackMoves[moveIndex]->GetDamage());
	}
}

void Character::Interact(Environ* env)
{
	if (env->GetHazard())
	{
		std::cout << "You have been hurt by the " << env->GetName() << std::endl;
		SetHealth(GetHealth() - env->GetDamage());
		std::cout << "Your health is now " << GetHealth() << std::endl;
	}
	else
	{
		std::cout << "You've attained a health boost from " << env->GetName() << std::endl;
		SetHealth(GetHealth() + env->GetDamage());
		std::cout << "Your health is now " << GetHealth() << std::endl;
	}
}

void Character::SendMessage(Character* target, std::string& message)
{
	std::string date = "12/Jun/2023";
	Message msg(this, target,message , date);
	_messages->Append(&msg);

	target->GetMessages().Append(&msg);

}

void Character::ShowStats()
{
	std::cout << "Name: " << GetName() << std::endl;
	std::cout << "Health: " << GetHealth() << std::endl;
	std::cout << "Ammo: " << GetAmmo() << std::endl;
	std::cout << "Location: " << GetLocation()->x << ", " << GetLocation()->y << std::endl;
	std::cout << "In Hand: " << GetInHand()->GetName() << std::endl;
	std::cout << "Backpack: " << "Empty - Yet to collect items" << std::endl;
	GetBackpack()->Display();
	std::cout << "Attack Moves: " << std::endl;
	for (int i = 0; i < static_cast<int>(_attackMoves.size()); i++)
	{
		std::cout << i << ": " << std::endl;
		_attackMoves[i]->InOrderTraverse();
	}
}

void Character::ShowMessages() const
{
	Message& current = *_messages;
	while (current.GetResponse() != Message::NULL_MESSAGE)
	{
		Message msg = *current;
		std::cout << "Previous Message" << (
			(msg.GetPrevious() == Message::NULL_MESSAGE)
			? "None"
			: "You had a Previous message to this"
		) << std::endl;
		std::cout << "From: " << msg.GetSender()->GetName() << std::endl;
		std::cout << "To: " << msg.GetReceiver()->GetName() << std::endl;
		std::cout << "Message: " << msg.GetMessage() << std::endl;
		std::cout << "Date: " << msg.GetDate() << std::endl;
		std::cout << "Reply To Message" << (
			(msg.GetResponse() == Message::NULL_MESSAGE) 
			? "You haven't replied to this message"
			: "You've replied to this Message"
		) << std::endl;
		std::cout << std::endl;

		current = *current.GetResponse();
	}
}


Message::Message()
{
	_sender = Character::NULL_CHARACTER;
	_receiver = Character::NULL_CHARACTER;
	_message = "";
	_date = "";
	_previous = NULL_MESSAGE;
	_response = NULL_MESSAGE;
}

Message::Message(Character* sender, Character* receiver, std::string& message, std::string& date)
{
	_sender = sender;
	_receiver = receiver;
	_message = message;
	_date = date;
	_previous = NULL_MESSAGE;
	_response = NULL_MESSAGE;

}

Message::Message(const Message& other)
{
	_sender = other._sender;
	_receiver = other._receiver;
	_message = other._message;
	_date = other._date;
	_previous = other._previous;
	_response = other._response;

}

Message::~Message()
{
	_sender = Character::NULL_CHARACTER;
	_receiver = Character::NULL_CHARACTER;
	_message = "";
	_date = "";
	_previous = NULL_MESSAGE;
	_response = NULL_MESSAGE;
}


Character* Message::GetSender() const
{
	return _sender;
}

Character* Message::GetReceiver() const
{
	return _receiver;
}

std::string Message::GetMessage() const
{
	return _message;
}

std::string Message::GetDate() const
{
	return _date;
}

Message* Message::GetPrevious() const
{
	return _previous;
}

Message* Message::GetResponse() const
{
	return _response;
}

void Message::SetSender(Character* sender)
{
	_sender = sender;
}

void Message::SetReceiver(Character* receiver)
{
	_receiver = receiver;
}

void Message::SetMessage(std::string& message)
{
	_message = message;
}

void Message::SetDate(std::string& date)
{
	_date = date;
}

void Message::SetPrevious(Message* previous)
{
	_previous = previous;
}

void Message::SetResponse(Message* response)
{
	_response = response;
}

const Message& Message::operator*() const
{
	return *this;
}

void Message::Append(Message* msg)
{
	if (_response == NULL_MESSAGE)
	{
		_response = msg;
	}
	else
	{
		_response->Append(msg);
	}
}

Message::MessagePtr Message::NULL_MESSAGE;
Character::CharacterPtr Character::NULL_CHARACTER;

