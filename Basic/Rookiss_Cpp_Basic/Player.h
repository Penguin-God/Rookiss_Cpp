#pragma once
#include "Creature.h"

enum JobType 
{
    KNIGTH = 1,
    ARCHER,
    MAGE,
};

class Player : public Creature
{
public:
    Player(int type) : Creature(PLAYER), _playerType(type)
    {
        switch (type)
        {
        case 0: break;
        case 1: break;
        case 2: break;
        }
    }

    virtual void PrintInfo() override;
public:
    int _playerType;
};

class Knigth : public Player
{
public:
    Knigth() : Player(1)
    {
        _hp = 150;
        _damage = 10;
        _defence = 5;
    }
};

class Archer : public Player
{
public:
    Archer() : Player(2)
    {
        _hp = 80;
        _damage = 15;
        _defence = 3;
    }
};

class Mage : public Player
{
public:
    Mage() : Player(3)
    {
        _hp = 50;
        _damage = 25;
        _defence = 1;
    }
};
