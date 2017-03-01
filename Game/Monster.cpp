#include"Monster.h"


Monster::Monster(int hp, int max, int min, char*name) :Being(0, 0, 0), Name(NULL)
{
	setName(name);
}
Monster::Monster() :Being(0, 0, 0), Name(NULL)
{

}

Monster::~Monster()
{
	delete[]Name;
}
void Monster::setName(char* Name)
{
	delete[]this->Name;
	this->Name = new char[strlen(Name) + 1];
	strcpy(this->Name, Name);
}
char* Monster::getName()const
{
	return Name;
}
///
///Prints his own stats
///
void Monster::PrintStats()const
{
	std::cout << "Monster : " << Name << std::endl;

}