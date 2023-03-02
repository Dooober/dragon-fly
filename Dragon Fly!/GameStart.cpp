#include "GameStart.h"
#include "WorldManager.h"
#include "EventKeyboard.h"
#include "Hero.h"
#include "Score.h"
#include "GameState.h"
#include "GameManager.h"
#include "ResourceManager.h"

GameStart::GameStart() {
	setType("GameStart");
	setSprite("gamestart");
	active = true;

	// Put in center of screen
	setLocation(df::CENTER_CENTER);

	p_music = RM.getMusic("menu");
	p_music->play();
}

int GameStart::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::P:
			start(false);
			break;
		case df::Keyboard::ESCAPE:
			GM.setGameOver();
			break;
		case df::Keyboard::TILDE:
			start(true);
			break;
		}
		return 1;
	}
	return 0;
}

void GameStart::start(bool secret) {
	if (active) {
		active = !active;
		p_music->stop();
		df::ObjectList all_objects = WM.getAllObjects();
		df::ObjectListIterator li(&all_objects);
		while (!li.isDone()) {
			WM.markForDelete(li.currentObject());
			li.next();
		}
		new Hero();
		new Score();
		new GameState(secret);
	}
}

int GameStart::draw() {
	return df::Object::draw();
}