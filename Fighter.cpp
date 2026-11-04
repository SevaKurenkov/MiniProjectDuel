#include "Fighter.h"
// TODO: конструктор, урон, лечение, чтение HP, проверка жизни.
Fighter::Fighter(int maxHp) {
	if (maxHp > 0) {
		hp_ = maxHp;
		maxHp_ = maxHp;
	}
	else {
		return;
	}
}

void Fighter::takeDamage(int amount) {
	if (amount < 0) {
		return;
	}
	if (amount < hp_) {
		hp_ = hp_ - amount;
	}
	else {
		hp_ = 0;
	}
}


void Fighter::heal(int amount) {
	if (amount < 0) {
		return;
	}
	if (amount + hp_ <= maxHp_) {
		hp_ = hp_ + amount;
	}
	else {
		hp_ = maxHp_;
	}
}

int Fighter::hp() const {return hp_;}

bool Fighter::alive() const {
	if (hp_ > 0) {return true;}
	else {return false;}
}