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


protected:
	int _monsterType;
};

class Slime : public Monster
{
	Slime() : Monster(SLIME)
	{
		_hp = 50;
		_damage = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
	Orc() : Monster(ORC)
	{
		_hp = 80;
		_damage = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster
{
	Skeleton() : Monster(SKELETON)
	{
		_hp = 100;
		_damage = 15;
		_defence = 4;
	}
};