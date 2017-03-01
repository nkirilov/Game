#pragma once
#include"Being.h"
#include<iostream>
#include"Item.h"
#include"Point.h"


class Player:public Being
{
public:
	Player();
	~Player();
	Player(int ,int ,int ,int ,Point );
	void setDefence(int);
	int getDefence();
	void Heal();
	void PrintInventory();
	void PrintEquipped();
	void Add(const Item& o);
	void resize(int newCap);
	void RemoveItem(int);
	int getUsed();
	void PutOn(int pos);
	void InitEquip();
	void setPosition(Point);
	Point getPosition();

protected:
	virtual void PrintStats()const;
private:
	int Defence;
	Item** Inventory;
	int Cap;
	int Used;
	Point Position;
};


