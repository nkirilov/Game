#pragma once 
#include<iostream>
#include"Being.h"

class Monster :public Being
{
public:
	Monster();
	Monster(int,int,int,char*);
	~Monster();
	void setName(char* Name);
	char* getName()const;
protected:
	virtual void PrintStats()const;
private:
	char* Name;

};
