#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventClear.h"
#include "EventOut.h"
#include "Hero.h"
#include "Bug.h"
#include "Flower.h"
#include "PowerUp.h"
#include "ScoreMultiplier.h"
#include "GameOver.h"
#include "PowerUpString.h"
#include "EventPowerUpEnd.h"

int scoreMult = 1;

Hero::Hero() {
    // Link to "ship" sprite.
    setSprite("dragonfly");

    // Make box one char smaller on all sides for better collisions
    df::Vector new_corner(getBox().getCorner() + df::Vector(1, 1));
    df::Box new_box(new_corner, getBox().getHorizontal() - 2, getBox().getVertical() - 2);
    setBox(new_box);

    // Set object type.
    setType("Hero");

    // Set starting location.
    df::Vector p(-7, WM.getView().getVertical() / 2);
    setPosition(p);

    lastPowerUp = -1;
    powerUpDuration = -1;

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
        if (powerUpDuration >= 0)
            powerUpDuration--;
        if (powerUpDuration < 0 && lastPowerUp == 0) {
            lastPowerUp = -1;
            EventPowerUpEnd epue(true);
            WM.onEvent(&epue);
        } else if (powerUpDuration < 0 && lastPowerUp == 1) {
            lastPowerUp = -1;
            setSolidness(df::HARD);
            getAnimation().getSprite()->setColor(df::GREEN);
            EventPowerUpEnd epue;
            WM.onEvent(&epue);
        } else if (powerUpDuration < 0 && lastPowerUp == 2) {
            lastPowerUp = -1;
            scoreMult = 1;
            EventPowerUpEnd epue;
            WM.onEvent(&epue);
        }
        step();
        return 1;
    }
    if (p_e->getType() == df::COLLISION_EVENT) {
        const df::EventCollision* p_collision_event = dynamic_cast <df::EventCollision const*> (p_e);
        if ((p_collision_event->getObject1()->getType() == "PowerUp" && p_collision_event->getObject2()->getType() == "Hero") || (p_collision_event->getObject1()->getType() == "PowerUp" && p_collision_event->getObject2()->getType() == "PowerUp")) {
            int powerUp = rand() % 3;
            lastPowerUp = powerUp;
            LM.writeLog("%d", powerUp);
            // Clear Enemies
            if (powerUp == 0) {
                powerUpDuration = 50;
                EventClear es;
                WM.onEvent(&es);
                new PowerUpString(CLEAR, powerUpDuration);
                return 1;
            // Invincibility
            } else if (powerUp == 1) {
                powerUpDuration = 150;
                setSolidness(df::SPECTRAL);
                getAnimation().getSprite()->setColor(df::YELLOW);
                new PowerUpString(INVINCIBILITY, powerUpDuration);
                return 1;
            // 2x Multiplier
            } else if (powerUp == 2) {
                powerUpDuration = 250;
                scoreMult = 2;
                new PowerUpString(MULTIPLIER, powerUpDuration);
                return 1;
            }
            
        } 

        new GameOver(); // Gameover
        return 1;
    }
    if (p_e->getType() == df::OUT_EVENT) {
        new GameOver(); // Gameover
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

