#include "Flower.h"

Flower::Flower() {
    setSprite("flower"); // Remove when other enemy classes created
    setVelocity(df::Vector(-MOVE_SPEED, 0));
    setRandomPosition();
}

void Flower::setRandomPosition() {
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