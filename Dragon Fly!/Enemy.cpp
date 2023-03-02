#include "Enemy.h"

#include "EventClear.h"
#include "ScoreMultiplier.h"

Enemy::Enemy() {
	setType("Enemy");
    setSolidness(df::SOFT);
}

Enemy::~Enemy() {}

int Enemy::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::OUT_EVENT) {
        setRandomPosition();
        df::EventView ev(SCORE_STRING, 1 * scoreMult, true);
        WM.onEvent(&ev);
        return 1;
    }
    if (p_e->getType() == CLEAR_EVENT) {
        WM.markForDelete(this);
        return 1;
    }
    return 0;
}