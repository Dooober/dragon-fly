#include "GameStart.h"
#include "WorldManager.h"
#include "EventKeyboard.h"
#include "EventStart.h"
#include "Hero.h"
#include "Score.h"
#include "GameState.h"

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
			start();
			break;
		}
		return 1;
	}
	return 0;
}

void GameStart::start() {
	if (active) {
		active = !active;
		new Hero();
		new Score();
		new GameState();
		WM.markForDelete(this);
	}
}

int GameStart::draw() {
	return df::Object::draw();
}