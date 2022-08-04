#pragma once

enum CreatureType
{
	PLAYER,
	MONSTER,
};

class Creature
{
public:
	Creature(int type) : _type(type)
	{

	}

	virtual ~Creature()
	{

	}

protected:
	int _type;
	int _hp = 0;
	int _damage = 0;
	int _defence = 0;
};

