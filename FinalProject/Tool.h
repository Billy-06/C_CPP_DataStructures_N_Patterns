#pragma once
#include "Item.h"
#include <string>
/**
 * @file Tool.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the Tool class which extends
 * from the Item class.
 *
 * Properties:
 * -----------
 * > _miningSpeed: int - This is the mining speed of the tool.
 * > _durability: int - This is the durability of the tool.
 * > _electricSpeed: int - This is the electric speed of the tool.
 *
 * Methods:
 * > Tool() - This is the default constructor.
 * > Tool(string name, int miningSpeed, int durability) - This is the overloaded constructor.
 * > Tool(const Tool& tool) - This is the copy constructor.
 * > ~Tool() - This is the destructor.
 * > Getters and setters for the properties.
 * > ApplyElectricSpeed() - This method applies the electric speed to the tool.
 * > Print() - This method prints the tool.
 *
 */
class Tool : public Item
{
private:
	int _miningSpeed;
	int _durability;
	int _electricSpeed;

public: 
	Tool();
	Tool(std::string& name, int miningSpeed, int durability);
	Tool(std::string& name, int strength, int range, int miningSpeed, int durability, int electricSpeed);
	Tool(const Tool& tool);
	~Tool() override;

	int GetMiningSpeed() const;
	void SetMiningSpeed(int miningSpeed);

	int GetDurability() const;
	void SetDurability(int durability);

	int GetElectricSpeed() const;
	void SetElectricSpeed(int electricSpeed);

	void ApplyElectricSpeed();

	void Print() const override;
};