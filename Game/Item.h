#pragma once
#include<iostream>

class Item
{
public:
	Item();
	Item(char* ,int,bool);
	virtual ~Item();
	Item& operator=(const Item&);
	void setName(char*);
	void setID(int);
	char* getName() const;
	int getID()const;
	void Print()const;
	virtual Item* Clone() const = 0;
	void setEquipped(bool);
	bool getEquipped();

protected:
	virtual void PrintHar()const = 0;
	

private:
	char* Name;
	int ID;
	bool Equipped;
};


