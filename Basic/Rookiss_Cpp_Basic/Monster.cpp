#include "Monster.h"

#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "-------------------" << endl;
	cout << "[���� ����]  " << "HP : " << _hp << "  Damage : " << _damage << " Defence : " << _defence << endl;
	cout << "-------------------" << endl;
}