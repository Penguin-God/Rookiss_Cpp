#include "Game.h"
#include "Player.h"
#include "Field.h"

#include <iostream>
using namespace std;

Game::Game() : _player(nullptr), _field(nullptr)
{
    
}

Game::~Game()
{
    if (_field != nullptr)
        delete _field;
    if (_player != nullptr)
        delete _player;
}

void Game::Init()
{
    _field = new Field();
}

void Game::Update()
{
    if (_player == nullptr)
        CreatePlayer();

    if (_player->IsDead())
    {
        delete _player;
        _player = nullptr;
        CreatePlayer();
    }

    _field->Update(_player);
}

void Game::CreatePlayer()
{
    while (_player == nullptr)
    {
        cout << "������ ����ּ���" << endl;
        int jobNumber = InputNumber("(1) ��� (2) �ü� (3) ����");
        if (jobNumber < 1 || jobNumber > 3) continue;

        switch (jobNumber)
        {
        case KNIGTH: _player = new Knigth();
        case ARCHER: _player = new Archer();
        case MAGE: _player = new Mage();
        }
    }
}

int Game::InputNumber(const char* msg)
{
    cout << msg << endl;
    cout << ">>";
    int result;
    cin >> result;
    return result;
}