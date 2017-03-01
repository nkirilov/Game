#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"Point.h"
#include"Being.h"
#include"Player.h"
#include"Monster.h"
#include"Item.h"
#include"Weapon.h"
#include"Armor.h"
#include"Map.h"
#include"Point.h"
static int Lvl = 0;


class Gameplay
{
public:
	Gameplay(std::ifstream& in);
	~Gameplay();
	void Play();
	void FindPlayer();
	void MobEncounter(Point);
	void moveIt(Point next);

private:
	Map Field;
	Player Gamer;
	Monster Mob;

};

