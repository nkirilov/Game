#include"Item.h"
#include<iostream>

Item::Item() :Name(NULL), ID(7), Equipped(false)
{
	
}
Item::Item(char* Name, int ID,bool eq) : Name(NULL)
{
	setName(Name);
	setID(ID);
	setEquipped(eq);
}
Item::~Item()
{
	delete[]Name;
}
void Item::setName(char* Name)
{
	delete[]this->Name;
		this->Name = new char[strlen(Name) + 1];
		memset(this->Name, 0, strlen(Name)+1);
		strcpy(this->Name, Name);
	
}
void Item::setID(int ID)
{
	this->ID = ID;
}
char* Item::getName() const
{
	return Name;
}
int Item::getID()const
{
	return ID;
}
///
///Prints the Base Stats
///
void Item::Print()const
{
	if (ID >= 0 && ID <= 6)
	{
		std::cout << Name << std::endl;
		switch (ID)
		{
		case 0:
		{
				  std::cout << "Weapon" << std::endl;
				  break;
		}
		case 1:
		{
				  std::cout << "Head" << std::endl;
				  break;
		}
		case 2:
		{
				  std::cout << "Chest" << std::endl;
				  break;
		}
		case 3:
		{
				  std::cout << "Legs" << std::endl;
				  break;
		}
		case 4:
		{
				  std::cout << "Feet" << std::endl;
				  break;
		}
		case 5:
		{
				  std::cout << "Hands" << std::endl;
				  break;
		}
		case 6:
		{
				  std::cout << "Shield" << std::endl;
				  break;
		}
		}
		PrintHar();
		std::cout << std::endl;
	}
}
Item& Item::operator=(const Item& o)
{
	if (this != &o)
	{
		setName(o.Name);
		setID(o.ID);
	}
	return *this;
}
void Item::setEquipped(bool Eq)
{
	this->Equipped = Eq;
}
bool Item::getEquipped()
{
	return Equipped;
}