#include "Enemy.h"

Enemy::Enemy() {
	setType("Enemy");
}

Enemy::~Enemy() {}

int Enemy::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::OUT_EVENT) {
        setRandomPosition();
        df::EventView ev(SCORE_STRING, 1, true);
        WM.onEvent(&ev);
        return 1;
    }
    return 0;
}