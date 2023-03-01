#include "Bug.h"
#include "EventStep.h"

Bug::Bug() {
    setSprite("bug");
    setVelocity(df::Vector(-MOVE_SPEED, BUG_Y_SPEED));
    setRandomPosition();
    setPosition(df::Vector(WM.getView().getHorizontal() * 3 / 2, getPosition().getY()));
}

void Bug::setRandomPosition() {
    int view_vertical = (int)WM.getView().getVertical();
    int y_random = rand() % view_vertical; // Random y value on view
    
    // KNOWN BUG, MAX AND MIN NEED TO BE ON VIEW
    max_y = y_random + BUG_DISTANCE;
    min_y = y_random - BUG_DISTANCE;

    int x_pos = WM.getView().getHorizontal();
    setPosition(df::Vector(x_pos, y_random));
}



int Bug::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::STEP_EVENT) {
        int y_pos = getPosition().getY();
        if (y_pos >= max_y)
            setVelocity(df::Vector(-MOVE_SPEED, -BUG_Y_SPEED));
        else if (y_pos <= min_y)
            setVelocity(df::Vector(-MOVE_SPEED, BUG_Y_SPEED));
        return 1;
    }
    return Enemy::eventHandler(p_e);
}