#include "Field.h"
#include "Monster.h"
#include "Player.h"

#include <stdlib.h>

Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();
	Battle(player);
}

void Field::CreateMonster()
{
	int random = 1 + rand() % 3;

	switch (random)
	{
	case SLIME: _monster = new Slime(); break;
	case ORC: _monster = new Orc(); break;
	case SKELETON: _monster = new Skeleton(); break;
	}
}

void Field::Battle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		_monster->OnDamaged(player);
		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		player->OnDamaged(_monster);
		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}
	}
}