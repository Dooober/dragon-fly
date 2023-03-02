#include "PowerUp.h"
#include "EventOut.h"
#include "EventClear.h"
#include "EventCollision.h"
#include "ResourceManager.h"
#include "WorldManager.h"

PowerUp::PowerUp() {
    setType("PowerUp");
    setSolidness(df::SOFT);
    setSprite("powerup");
    setVelocity(df::Vector(-0.75, 0));
    setRandomPosition();
    setPosition(df::Vector(WM.getView().getHorizontal() * 3 / 2.5, getPosition().getY()));
}

int PowerUp::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::COLLISION_EVENT) {
        const df::EventCollision* p_collision_event = dynamic_cast <df::EventCollision const*> (p_e);
        if ((p_collision_event->getObject1()->getType() == "Hero") || (p_collision_event->getObject2()->getType() == "Hero")) {
            WM.markForDelete(this);
            df::Sound* p_sound = RM.getSound("powerup");
            if (p_sound)
                p_sound->play();
            
            
        }
        return 1;
    }
    if (p_e->getType() == df::OUT_EVENT) {
        setRandomPosition();
        return 1;
    }
    if (p_e->getType() == CLEAR_EVENT) {
        WM.markForDelete(this);
        return 1;
    }
    return 0;
}

void PowerUp::setRandomPosition() {
    int view_vertical = (int)WM.getView().getVertical();
    int y_random = rand() % view_vertical; // Random y value on view
    int x_pos = WM.getView().getHorizontal();
    setPosition(df::Vector(x_pos, y_random));
}
