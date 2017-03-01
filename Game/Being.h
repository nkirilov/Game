#pragma once

class Being
{
public:
	Being(int,int,int);
	Being();
	virtual ~Being(){}
	void setHealth(int);
	int getHealth();
	void setMaxAttack(int);
	int getMaxAttack();
	void setMinAttack(int);
	int getMinAttack();
	void Print()const;
	void PrintHealth()const;
	int getMaxHealth()
	{
		return MaxHealth;
	}
	void setMaxHealth(int hp)
	{
		this->MaxHealth = hp;
	}
protected:
	virtual void PrintStats()const = 0;
private:
	int Health;
	int MaxHealth;
	int maxAttack;
	int minAttack;

};

