#pragma once
#include"Item.h"

class Weapon:public Item
{
public:
	Weapon();
	Weapon(char*, int, bool , int);
	Weapon& operator=(const Weapon&);
	void setAttack(int);
	int getAttack()const;
	virtual Item* Clone() const
	{
		return new Weapon(*this);
	}
protected:
	virtual void PrintHar()const;
	
private:
	int Attack;
};



