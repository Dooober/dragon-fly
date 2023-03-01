#include "PowerUp.h"
#include "EventOut.h"
#include "EventStart.h"
#include "WorldManager.h"

PowerUp::PowerUp() {
    setType("PowerUp");
    setSolidness(df::SOFT);
    setSprite("powerup");
    setVelocity(df::Vector(-1, 0));
    setRandomPosition();
    setPosition(df::Vector(WM.getView().getHorizontal() * 3 / 2.5, getPosition().getY()));
}

int PowerUp::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::OUT_EVENT) {
        setRandomPosition();
        return 1;
    }
    if (p_e->getType() == START_EVENT) {
        WM.markForDelete(this);
        return 1;
    }
    return 0;
}

void PowerUp::setRandomPosition() {
    int view_vertical = (int)WM.getView().getVertical();
    int modifier = view_vertical / 6;
    int y_random = rand() % view_vertical; // Random y value on view
    if (y_random >= (view_vertical / 2)) { // add modifier to eliminate these enemies in the center
        y_random += modifier;
    }
    else {
        y_random -= modifier;
    }
    int x_pos = WM.getView().getHorizontal();
    setPosition(df::Vector(x_pos, y_random));
}
