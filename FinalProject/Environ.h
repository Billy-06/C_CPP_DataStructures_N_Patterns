#pragma once
#include <string>
/**
 * @file Environ.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Environ class
 * which represents elements of the environment in the player's world.
 *
 * Properties:
 * -----------
 * > _name: string - This field represents the name of the environment element.
 * > _description: string - This field represents the description of the environment element.
 * > _hazard: bool - This field represents whether the environment element is a hazard or not.
 * > _damage: int - This field represents the damage the environment element can cause.
 * > _healing: int - This field represents the healing the environment element can cause.
 *
 * Methods:
 * --------
 * > Environ() - This is the default constructor.
 * > Environ(string name, string description, bool hazard, int damage, int healing) - This is the constructor.
 * > Environ(const Environ& env) - This is the copy constructor.
 * > ~Environ() - This is the destructor.
 * > Getters and Setters - These are the getters and setters for the fields.
 * > ToggleHazard: void - This method toggles the hazard status of the environment element.
 * > Print(): void - This method prints the environment element.
 *
 */
class Environ
{
private:
	std::string _name;
	std::string _description;
	bool _hazard;
	int _damage;
	int _healing;

public:
	/**
	 * @brief This is the default constructor.
	*/
	Environ();

	/**
	 * @brief Overloaded constructor.
	 * @param name - This is the name of the environment element.
	 * @param description - This is the description of the environment element.
	 * @param hazard - This is whether the environment element is a hazard or not.
	 * @param damage - This is the damage the environment element can cause the character.
	 * @param healing - This is the healing the environment element can cause the character.
	*/
	Environ(std::string& name, std::string& description, bool hazard, int damage, int healing);

	/**
	 * @brief This is the copy constructor.
	 * @param env - This is the environment element to be copied.
	*/
	Environ(const Environ& env);

	/**
	 * @brief This is the destructor.
	*/
	~Environ();

	/**
	 * @brief Getter for the name of the environment element.
	 * @return a string representing the name of the environment element.
	*/
	std::string GetName() const;

	/**
	 * @brief Getter for the description of the environment element.
	 * @return a string representing the description of the environment element.
	*/
	std::string GetDescription() const;

	/**
	 * @brief Getter for whether the environment element is a hazard or not.
	 * @return a boolen representing whether the environment element is a hazard or not.
	*/
	bool GetHazard() const;

	/**
	 * @brief Getter for the damage the environment element can cause the character.
	 * @return an integer representing the damage the environment element can cause the character.
	*/
	int GetDamage() const;

	/**
	 * @brief Getter for the healing the environment element can cause the character.
	 * @return an integer representing the healing the environment element can cause the character.
	*/
	int GetHealing() const;

	/**
	 * @brief Setter for the name of the environment element.
	 * @param name - This is the desired name of the environment element.
	*/
	void SetName(std::string& name);

	/**
	 * @brief Setter for the description of the environment element.
	 * @param description - This is the desired description of the environment element.
	*/
	void SetDescription(std::string& description);

	/**
	 * @brief This method toggles the hazard status of the environment element.
	*/
	void ToggleHazard();

	/**
	 * @brief Setter for the damage the environment element can cause the character.
	 * @param damage - This is the desired damage the environment element can cause the character.
	*/
	void SetDamage(int damage);

	/**
	 * @brief Setter for the healing the environment element can cause the character.
	 * @param healing - This is the desired healing the environment element can cause the character.
	*/
	void SetHealing(int healing);

	/**
	 * @brief This method prints the environment element.
	*/
	void Print() const;
};