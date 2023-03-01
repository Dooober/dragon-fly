#include "GameStart.h"
#include "EventKeyboard.h"
#include "EventStart.h"
#include "Hero.h"
#include "Bug.h"
#include "Flower.h"
#include "PowerUp.h"

GameStart::GameStart() {
	setType("GameStart");
	setSprite("gamestart");
	active = true;

	// Put in center of screen
	setLocation(df::CENTER_CENTER);
}

int GameStart::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::P:
			if (active) {
				active = false;
				EventStart event_start;
				WM.onEvent(&event_start);
				WM.markForDelete(this);
			}
			break;
		}
		return 1;
	}
	return 0;
}

int GameStart::draw() {
	return df::Object::draw();
}