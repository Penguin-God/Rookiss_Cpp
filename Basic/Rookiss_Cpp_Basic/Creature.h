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

	virtual void PrintInfo() = 0;

	void OnDamaged(Creature* attaker);
	bool IsDead() { return _hp <= 0; }

public:
	int _type;
	int _hp = 0;
	int _damage = 0;
	int _defence = 0;
};

