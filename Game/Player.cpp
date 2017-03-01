#include"Player.h"
#include<iostream>
#include<fstream>
#include"Weapon.h"
#include"Armor.h"
#include"Item.h"

void Player::setDefence(int def)
{
	this->Defence = def;
}
int Player::getDefence()
{
	return Defence;
}
Player::Player(int HP, int Max, int Min, int Def,Point Pos) :Being(HP, Max, Min)
{
	setDefence(Def);
	Cap = 1;
	Used = 0;
	Inventory = new Item*[Cap];
	InitEquip();
	setPosition(Pos);
}
Player::Player() : Being(0, 0, 0), Defence(0), Cap(1), Used(0)
{
	Inventory = new Item*[Cap];
	InitEquip();
	Position.setX(-1);
	Position.setY(-1);
}
///
///Prints his stats
///
void Player::PrintStats()const
{
	std::cout << "Defence : " << Defence << std::endl;

}
///
///Heals the palyer
///
void Player::Heal()
{
	setHealth(getMaxHealth());
}
///
///prints the inventory
///
void Player::PrintInventory()
{
	int count=1;
	for (size_t i = 0; i < Used; i++)
	{

		if (strlen(Inventory[i]->getName())>2)
		{
			std::cout << count << ". ";
			count++;
			Inventory[i]->Print();
		}
		
	}
}
///
///Prints equipped
///
void Player::PrintEquipped()
{
	for (size_t i = 7; i < Used; i++)
	{

		if (Inventory[i]->getEquipped()==true && strlen(Inventory[i]->getName())>2)
		{
			Inventory[i]->Print();
		}
		
	}
}
Player::~Player()
{

	delete[]Inventory;
}
///
///Adds an item to inventory
///
void Player::Add(const Item& o)
{
	if (Used == Cap)
	{
		Cap *= 2;
		resize(Cap);
	}
	Inventory[Used] = o.Clone();
	Used++;

}
///
///resizes Inventory
///
void Player::resize(int newCap)
{
	Item** temp = new Item*[newCap];
	for (size_t i = 0; i < Used; i++)
	{
		temp[i] = Inventory[i];
	}
	delete[] Inventory;
	Inventory = temp;
}
///
///Removes an Item from Inventory
///
void Player::RemoveItem(int pos)
{
	delete[] Inventory[pos];
	for (size_t j = pos; j < Used - 1; j++)
	{
		Inventory[j] = Inventory[j + 1];
	}
	Used--;
}

int Player::getUsed()
{
	return Used;
}
void Player::PutOn(int pos)
{
	int id = Inventory[pos]->getID();
	for (size_t i = 0; i < Used; i++)
	{
		if (Inventory[i]->getID() == id && Inventory[i]->getEquipped() == true)
		{
			Inventory[i]->setEquipped(false);
			Inventory[pos]->setEquipped(true);
		}
	}
}
///
///Initializes the Equipment
///
void Player::InitEquip()
{
	std::ifstream in("InitEquip.txt", std::ios::binary);
	for (size_t i = 0; i < 6; i++)
	{
		int id;
		in >> id;
		if (id == 0)
		{
			int at;
			in >> at;
			int eq;
			in >> eq;
			bool a;
			if (eq == 0)
			{
				a = false;
			}
			else
			{
				a = true;
			}
			int len;

			in >> len;

			char* name = new char[len];
			memset(name, 0, len);
			//name[0] = '\0';
			in.get(name, len);
			Weapon temp(name, id, a, at);
			Add(temp);
			delete[] name;
			
		}
		if (id >= 1 && id <= 6)
		{
			int def;
			in >> def;
			int eq;
			in >> eq;
			bool a;
			if (eq == 0)
			{
				a = false;
			}
			else
			{
				a = true;
			}
			int len;

			in >> len;

			char* name = new char[len];
			//memset(name, 0, len);
			name[0] = '\0';
			in.get(name, len);
			Armor temp(name, id, a, def);
			Add(temp);
			delete[] name;
			
		}
		
	}
	in.close();
}
void Player::setPosition(Point o)
{
	this->Position.setX(o.getX());
	this->Position.setY(o.getY());
}
Point Player::getPosition()
{
	return Position;
}