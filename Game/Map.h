#pragma once
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"Point.h"
#include"Being.h"
#include"Player.h"
#include"Monster.h"
#include"Item.h"
#include"Weapon.h"
#include"Armor.h"


class Map
{
public:
	Map(std::ifstream& in);
	~Map();
	void setField(std::ifstream& in);
	void freeField();
	void Print();
	Point FindPlayer();
	void PrintCommands();
	void PrintEnd();
	void PrintGoBack();
	void PrintAdd(char* dir);
	void PrintStartScreen();
	void setIOM(std::istream& in);
	void PrintIOM();
	char** Field;
	Item* getItem(int);

private:
	Item** ItemsOnMap;
	
	

};

