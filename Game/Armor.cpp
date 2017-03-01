#include"Armor.h"
#include<iostream>
Armor::Armor() :Item(NULL,7,false),Defence(0)
{
}
Armor::Armor(char* name, int id,bool eq, int Def) : Item(name,id,eq)
{
	setDefence(Def);
}
///
///Sets the defence of armor
///
void Armor::setDefence(int Def)
{
	Defence = Def;
}
///
///Returns the defence of armor
///
int Armor::getDefence()
{
	return Defence;
}
///
///prints defence
///
void Armor::PrintHar()const
{
	std::cout << "Def : " << Defence << std::endl;
}
Armor& Armor::operator=(const Armor& o)
{
	if (this!=&o)
	{
		Item::operator=(o);
		setDefence(o.Defence);
	}
	return *this;
}