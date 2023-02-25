#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "Hero.h"
#include "Bug.h"
#include "Flower.h"
#include "PowerUp.h"

Hero::Hero() {
    // Link to "ship" sprite.
    setSprite("dragonfly");

    // Set object type.
    setType("Hero");

    // Set starting location.
    df::Vector p(-7, WM.getView().getVertical() / 2);
    setPosition(p);

    fallSpeed = 0;
    moveSlowdown = 10;
    moveCountdown = moveSlowdown;
}

Hero::~Hero() {}

// Handle event.
// Return 0 if ignored, else 1.
int Hero::eventHandler(const df::Event* p_e) {
    // Keyboard event
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
        kbd(p_keyboard_event);
        return 1;
    }
    if (p_e->getType() == df::STEP_EVENT) {
        step();
        return 1;
    }
    if (p_e->getType() == df::COLLISION_EVENT) {
        const df::EventCollision* p_collision_event = dynamic_cast <df::EventCollision const*> (p_e);
        LM.writeLog("Collision between %s, %s\n", p_collision_event->getObject1()->getType().c_str(), p_collision_event->getObject2()->getType().c_str());
        if ((p_collision_event->getObject1()->getType() == "PowerUp") && (p_collision_event->getObject2()->getType() == "Hero")) {
            // Delete Powerup and all Enemies
            WM.markForDelete(p_collision_event->getObject1());
            df::ObjectList all_enemies = WM.objectsOfType("Enemy");
            df::ObjectListIterator li(&all_enemies);
            while (!li.isDone()) {
                WM.markForDelete(li.currentObject());
                li.next();
            }
            // Add them back
            new Flower();
            new Bug();
            new PowerUp();
            return 1;
        } else if ((p_collision_event->getObject1()->getType() == "Hero") && (p_collision_event->getObject2()->getType() == "PowerUp")) {
            // Delete Powerup and all Enemies
            WM.markForDelete(p_collision_event->getObject2());
            df::ObjectList all_enemies = WM.objectsOfType("Enemy");
            df::ObjectListIterator li(&all_enemies);
            while (!li.isDone()) {
                WM.markForDelete(li.currentObject());
                li.next();
            }
            // Add them back
            new Flower();
            new Bug();
            new PowerUp();
            return 1;
        }

        GM.setGameOver(); // Gameover
        return 1;
    }
    if (p_e->getType() == df::OUT_EVENT) {
        GM.setGameOver(); // Gameover
        return 1;
    }
    return 0;
}

void Hero::kbd(const df::EventKeyboard* p_keyboard_event) {
    switch (p_keyboard_event->getKey()) {
        // up
    case df::Keyboard::W:
        if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
            move(-1);
        break;
    default:
        return;
    };

    return;
}

// Move up or down.
void Hero::move(int dy) {
    if (moveCountdown > 0)
        return;
    moveCountdown = moveSlowdown;
    // If stays on window, allow move.
    df::Vector new_pos(getPosition().getX(), getPosition().getY() + dy);
    // Flip fall speed to create "jump"
    if (new_pos.getY() > 2) {
        fallSpeed = -0.4;
    }
}

void Hero::step() {
    if (getPosition().getX() < 7) {
        df::Vector forwards(getPosition().getX() + 0.5, getPosition().getY());
        WM.moveObject(this, forwards);
        if (getPosition().getX() > 7) {
            df::Vector adjust(7, getPosition().getY());
            WM.moveObject(this, adjust);
        }
    }
    // 0.4 is terminal velocity (can be tweaked if it doesnt feel right)
    if (fallSpeed < 0.4) {
        // Increase until terminal velocity
        fallSpeed += 0.03;
    }
    // printf("%f\n", fallSpeed);
    // Set new position with fallSpeed changed
    df::Vector new_pos(getPosition().getX(), getPosition().getY() + fallSpeed);
    WM.moveObject(this, new_pos);
    moveCountdown--;
    if (moveSlowdown < 0)
        moveSlowdown = 0;
}

