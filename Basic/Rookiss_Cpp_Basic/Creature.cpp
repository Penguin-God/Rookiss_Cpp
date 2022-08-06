#include "Creature.h"

void Creature::OnDamaged(Creature* attacker)
{
	int damage = attacker->_damage - _defence;
	if (damage < 0) return;

	_hp -= damage;
	if (_hp < 0) _hp = 0;
}