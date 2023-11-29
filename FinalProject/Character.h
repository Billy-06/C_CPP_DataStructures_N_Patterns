#pragma once
#include "Tile.h"
#include "Backpack.h"
#include "ActionTree.h"
#include "Environ.h"
#include <string>
#include <vector>
#include "BidirectionalList.h"

class Message;
/**
 * @file Character.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the definition of the Character class from which both the
 * Player and Enemy extend.
 *
 * Properties
 * ----------
 * > _name: string - This is the name of the character
 * > _health: int - This is the health of the character
 * > _ammo: int - This is the ammo of the character
 * > _backpack: Backpack* - This is the backpack of the character
 * > _inHand: Item* - This is the item in the hand of the character
 * > _loc: Location* - This is the location of the character
 * > _attackMoves: vector<ActionTree> - This is the list of attack moves of the character
 * > _maxPower: int - This is the maximum power of the character
 * > _messages: BidirectionalList<Message> - This is the list of messages of the character
 *
 * Methods
 * -------
 * > Character() - This is the default constructor
 * > Character(string name, int health, int ammo) - This is the constructor with parameters
 * > Character(const Character& character) - This is the copy constructor for the class
 * > ~Character() - This is the destructor
 * > Getters and Setter for the properties
 * > Attack() - This is the method for attacking
 * > Interact(env: Environ*) - This is the method for interacting with the environment
 * > ShowStats() - This is the method for showing the stats of the character
 *
 */
class Character
{
public:
	typedef Character* CharacterPtr;
	static CharacterPtr NULL_CHARACTER;

protected:
	std::string _name;
	int _health;
	int _ammo;
	Backpack* _backpack;
	Item* _inHand;
	Location* _loc;
	std::vector<ActionTree*> _attackMoves;
	int _maxPower;
	Message* _messages;

public:
	/**
	 * @brief This is the default constructor
	*/
	Character();

	/**
	 * @brief This is the constructor with parameters
	 * @param name - the name of the character
	 * @param health - the health of the character
	 * @param ammo - the ammo of the character
	*/
	Character(std::string& name, int health, int ammo);

	/**
	 * @brief This is the copy constructor for the class
	 * @param character - the character to be copied
	*/
	Character(const Character& character);

	/**
	 * @brief This is the destructor
	*/
	virtual ~Character();

	/**
	 * @brief Getter for the name of the character
	 * @return a string representing the name of the character
	*/
	std::string GetName() const;

	/**
	 * @brief Getter for the health of the character
	 * @return an integer representing the health of the character
	*/
	int GetHealth() const;

	/**
	 * @brief Getter for the messages of the character
	 * @return a bidirectional list of messages of the character
	*/
	Message GetMessages() const;

	/**
	 * @brief Getter for the ammo of the character
	 * @return an integer representing the ammo of the character
	*/
	int GetAmmo() const;

	/**
	 * @brief Getter for the backpack of the character
	 * @return a pointer to the backpack of the character
	*/
	Backpack* GetBackpack() const;

	/**
	 * @brief Getter for the item in the hand of the character
	 * @return a pointer to the item in the hand of the character
	*/
	Item* GetInHand() const;

	/**
	 * @brief Getter for the location of the character
	 * @return a pointer to the location of the character
	*/
	Location* GetLocation() const;

	/**
	 * @brief Getter for the attack moves of the character
	 * @return a pointer to the attack moves of the character
	*/
	std::vector<ActionTree*> GetAttackMoves() const;

	/**
	 * @brief Getter for the maximum power of the character
	 * @return an integer representing the maximum power of the character
	*/
	int GetMaxPower() const;

	/**
	 * @brief Setter for the name of the character
	 * @param name - the desired name of the character
	*/
	void SetName(std::string& name);

	/**
	 * @brief Setter for the messages of the character
	 * @param messages - The desired messages of the character
	*/
	void SetMessages(Message& messages);

	/**
	 * @brief Setter for the health of the character
	 * @param health - the desired health of the character
	*/
	void SetHealth(int health);

	/**
	 * @brief Setter for the ammo of the character
	 * @param ammo - the desired ammo of the character
	*/
	void SetAmmo(int ammo);

	/**
	 * @brief Setter for the backpack of the character
	 * @param backpack - the desired backpack of the character
	*/
	void SetBackpack(Backpack* backpack);

	/**
	 * @brief Setter for the item in the hand of the character
	 * @param inHand - the desired item in the hand of the character
	*/
	void SetInHand(Item* inHand);

	/**
	 * @brief Setter for the location of the character
	 * @param loc - the desired location of the character
	*/
	void SetLocation(Location* loc);

	/**
	 * @brief Setter for the attack moves of the character
	 * @param attackMoves - the desired attack moves of the character
	*/
	void SetAttackMoves(std::vector<ActionTree*>& attackMoves);

	/**
	 * @brief Setter for the maximum power of the character
	 * @param maxPower - the desired maximum power of the character
	*/
	void SetMaxPower(int maxPower);

	const Character& operator*() const;

	/**
	 * @brief This is the method for attacking
	 * @param target - pointer to the character to attack
	 * @param moveIndex - the index of the attack move to use in attacking
	*/
	virtual void Attack(Character* target, int moveIndex);

	/**
	 * @brief This is the method for interacting with the environment
	 * @param env - pointer to the environment to interact with
	*/
	virtual void Interact(Environ* env);

	/**
	 * @brief This is the method for sending a message to another character
	*/
	void SendMessage(Character* target, std::string& message);

	/**
	 * @brief This is the method for showing the stats of the character
	*/
	virtual void ShowStats();

	void ShowMessages() const;
};

/**
 * @file Character.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the Message class definition
 * which the characters in the game will use to communicate with
 * each other.
 *
 * Properties:
 * -----------
 * > sender: Character* - The character who sent the message
 * > receiver: Character* - The character who received the message
 * > message: std::string - The message sent
 * > date: std::string - The date the message was sent
 * > previous: Message* - The previous message in the conversation
 * > response: Message* - The response to the message
 *
 * Methods:
 * --------
 * > Message() - Default constructor
 * > Message(Character* sender, Character* receiver, std::string message, std::string date) - Overloaded constructor
 * > Message(const Message& message) - Copy constructor
 * > ~Message() - Destructor
 * > Getters and setters for all properties
 * > void Display() - Displays the message
 *
 */
class Message
{
public:
	typedef Message* MessagePtr;
	static MessagePtr NULL_MESSAGE;
private:
	Character* _sender;
	Character* _receiver;
	std::string _message;
	std::string _date;
	Message* _previous;
	Message* _response;
public:
	/**
	 * @brief This is the default constructor
	*/
	Message();

	/**
	 * @brief This is the overloaded constructor
	 * @param sender - the character who sent the message
	 * @param receiver - the character who received the message
	 * @param message - the message sent
	 * @param date - the date the message was sent
	*/
	Message(Character* sender, Character* receiver, std::string& message, std::string& date);

	/**
	 * @brief This is the copy constructor
	 * @param other - the message to copy
	*/
	Message(const Message& other);

	/**
	 * @brief This is the destructor
	*/
	~Message();

	/**
	 * @brief Getter for the sender
	 * @return a pointer to the sender
	*/
	Character* GetSender() const;

	/**
	 * @brief Getter for the receiver
	 * @return pointer to the receiver
	*/
	Character* GetReceiver() const;

	/**
	 * @brief Getter for the message
	 * @return string representing the message
	*/
	std::string GetMessage() const;

	/**
	 * @brief Getter for the date
	 * @return string representing the date
	*/
	std::string GetDate() const;

	/**
	 * @brief Getter for the previous message
	 * @return pointer to the previous message
	*/
	Message* GetPrevious() const;

	/**
	 * @brief Getter for the response
	 * @return pointer to the response
	*/
	Message* GetResponse() const;

	/**
	 * @brief Setter for the sender
	 * @param sender - the desired sender
	*/
	void SetSender(Character* sender);

	/**
	 * @brief Setter for the receiver
	 * @param receiver - the desired receiver
	*/
	void SetReceiver(Character* receiver);

	/**
	 * @brief Setter for the message
	 * @param message - the desired message
	*/
	void SetMessage(std::string& message);

	/**
	 * @brief Setter for the date
	 * @param date - the desired date
	*/
	void SetDate(std::string& date);

	/**
	 * @brief Setter for the previous message
	 * @param previous - the desired previous message
	*/
	void SetPrevious(Message* previous);

	/**
	 * @brief Setter for the response
	 * @param response - the desired response
	*/
	void SetResponse(Message* response);

	/**
	 * @brief This is the overloaded dereference operator
	 * @return a reference to the message object
	*/
	const Message& operator*() const;

	// void Display() const;
	void Append(Message* message);

};

