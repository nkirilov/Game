#include"Being.h"
#include<iostream>
Being::Being() :Health(0), maxAttack(0), minAttack(0), MaxHealth(0)
{
}


Being::Being(int Health, int MaxA, int MinA)
{
	setMaxHealth(Health);
	setHealth(Health);
	setMaxAttack(MaxA);
	setMinAttack(MinA);
}
void Being::setHealth(int Health)
{
	this->Health = Health;
}
int Being::getHealth()
{
	return Health;
}
void Being::setMaxAttack(int Max)
{
	this->maxAttack = Max;
}
int Being::getMaxAttack()
{
	return maxAttack;
}
void Being::setMinAttack(int Min)
{
	this->minAttack = Min;
}
int Being::getMinAttack()
{
	return minAttack;
}
///
///Prints health of a being and attack
///
void Being::Print()const
{
	std::cout << "Health: " << Health << std::endl
		<< "Attack : " << minAttack << "-" << maxAttack << std::endl;
		
	PrintStats();

}
///
///Prints health of a being With graphics
///
void Being::PrintHealth()const
{
	std::cout << "[";
	for (int i = 1; i <= Health+1; i++)
	{
		std::cout << (char)177;
	}
	for (size_t i = 1; i < MaxHealth+1-Health; i++)
	{
		std::cout << " ";
	}
	std::cout << "] : " << Health<<std::endl;
}
