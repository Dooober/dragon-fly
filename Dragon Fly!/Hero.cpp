// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventOut.h"

// Game includes.
#include "Hero.h"

Hero::Hero() {
    // Link to "ship" sprite.
    setSprite("dragonfly");

    // Set object type.
    setType("Hero");

    // Set starting location.
    df::Vector p(7, 11);
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
        // down
    case df::Keyboard::S:
        if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
            move(+1);
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
