#pragma once
#include"Item.h"

class Armor :public Item
{
public:
	Armor();
	Armor(char*, int, bool eq, int);
	Armor& operator=(const Armor& o);
	void setDefence(int);
	int getDefence();
	virtual Item* Clone() const
	{
		return new Armor(*this);
	}
protected:
	virtual void PrintHar()const;
	
private:
	int Defence;

};


