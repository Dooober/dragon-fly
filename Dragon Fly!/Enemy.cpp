#include "Enemy.h"

Enemy::Enemy() {
	setType("Enemy");
	setSprite("testbox"); // Remove when other enemy classes created
	setDirection(df::Vector(-1, 0));
	setSpeed(move_speed);
    setRandomPosition();
}

Enemy::~Enemy() {}

void Enemy::setRandomPosition() {
    int view_vertical = (int)WM.getView().getVertical();
    int modifier = view_vertical / 6;
    int y_random = rand() % view_vertical; // Random y value on view
    if (y_random >= (view_vertical / 2)) { // add modifier to eliminate these enemies in the center
        y_random += modifier;
    } else {
        y_random -= modifier;
    }
    int x_pos = WM.getView().getHorizontal();
    setPosition(df::Vector(x_pos, y_random));
}

int Enemy::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::OUT_EVENT) {
        setRandomPosition();
        df::EventView ev(SCORE_STRING, 1, true);
        WM.onEvent(&ev);
        return 1;
    }
    return 0;
}