#include "Game.h"
#include "Player.h"

#include <iostream>
using namespace std;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{

}

void Game::Update()
{

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