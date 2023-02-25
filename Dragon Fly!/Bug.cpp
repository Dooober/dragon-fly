#include "Bug.h"
#include "EventStep.h"
#include "LogManager.h"

Bug::Bug() {
    setSprite("bug");
    setVelocity(df::Vector(-MOVE_SPEED, BUG_Y_SPEED));
    setRandomPosition();
    setPosition(df::Vector(WM.getView().getHorizontal() * 3 / 2, getPosition().getY()));
}

void Bug::setRandomPosition() {
    int view_vertical = (int)WM.getView().getVertical();
    int y_random = rand() % view_vertical; // Random y value on view

    max_y = y_random + BUG_DISTANCE;
    min_y = y_random - BUG_DISTANCE;
    LM.writeLog("Max_y = %d", max_y);
    LM.writeLog("Min_y = %d", min_y);
    LM.writeLog("Y_pos = %d", y_random);

    int x_pos = WM.getView().getHorizontal();
    setPosition(df::Vector(x_pos, y_random));
}



int Bug::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::STEP_EVENT) {
        int y_pos = getPosition().getY();
        LM.writeLog("Y position: %d", y_pos);
        if (y_pos >= max_y)
            setVelocity(df::Vector(-MOVE_SPEED, -BUG_Y_SPEED));
        else if (y_pos <= min_y)
            setVelocity(df::Vector(-MOVE_SPEED, BUG_Y_SPEED));
        return 1;
    }
    return Enemy::eventHandler(p_e);
}