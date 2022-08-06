#pragma once
#include "Creature.h"


enum MonsterType
{
	SLIME = 1,
	ORC,
	SKELETON,
};

class Monster : public Creature
{
public:
	Monster(int type) : Creature(MONSTER), _monsterType(type)
	{
		
	}

	virtual void PrintInfo() override;
protected:
	int _monsterType;
};

class Slime : public Monster
{
public:
	Slime() : Monster(SLIME)
	{
		_hp = 50;
		_damage = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(ORC)
	{
		_hp = 80;
		_damage = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(SKELETON)
	{
		_hp = 100;
		_damage = 15;
		_defence = 4;
	}
};