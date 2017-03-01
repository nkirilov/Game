#include"Weapon.h"
#include<iostream>

Weapon::Weapon() :Item(NULL, 7,false), Attack(0)
{

}
Weapon::Weapon(char* Name, int Id, bool eq, int attack) : Item(Name, Id, eq)
{
	
	setAttack(attack);
}
void Weapon::setAttack(int attack)
{
	this->Attack = attack;
}
int Weapon::getAttack()const
{
	return Attack;
}
///
///Prints his Stats
///
void Weapon::PrintHar()const
{
	std::cout << "Attack : " << Attack << std::endl;
}
Weapon & Weapon::operator=(const Weapon& o)
{
	if (this != &o)
	{
		Item::operator=(o);
		setAttack(o.Attack);
	}
	return *this;
}
