#include "Player.h"

#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "-------------------" << endl;
	cout << "[�÷��̾� ����]  " << "HP : " << _hp << "  Damage : " << _damage << " Defence : " << _defence << endl;
	cout << "-------------------" << endl;
}