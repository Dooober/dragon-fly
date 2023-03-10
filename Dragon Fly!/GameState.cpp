#include "GameState.h"
#include "GameStart.h"
#include "EventStep.h"
#include "EventKeyboard.h"
#include "EventBossKill.h"
#include "EventClear.h"
#include "EventPowerUpEnd.h"
#include "GameManager.h"

#include "Hero.h"
#include "Bug.h"
#include "Flower.h"
#include "Boss.h"
#include "Score.h"
#include "PowerUp.h"

GameState::GameState(bool secret) {
	setType("Game State");
	this->secret = secret;

	p_normal_music = RM.getMusic("normal");
	p_boss_music = RM.getMusic("boss");

	if (secret) {
		state = BOSS;
		boss_level = 5;
		boss_timer = 0;
		boss();
	}
	else {
		state = NORMAL;
		boss_level = 1;
		boss_timer = 0;
		normal();
	}
}

GameState::~GameState() {}

int GameState::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::STEP_EVENT) {
		if (state == NORMAL) {
			boss_timer--;
			if (boss_timer == 0) {
				p_normal_music->stop();
				boss();
				state = BOSS;
			}
		}
        return 1;
    }
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
		switch (p_keyboard_event->getKey()) {
		case (df::Keyboard::ESCAPE):
			GM.setGameOver();
			break;
		}
		return 1;
	}
	if (p_e->getType() == BOSS_KILL_EVENT) {
		p_boss_music->stop();
		if (secret) {
			boss();
		} else {
			normal();
			state = NORMAL;
		}
		return 1;
	}
	if (p_e->getType() == POWERUP_END_EVENT) {
		if (state == NORMAL) {
			EventPowerUpEnd* p_e_powerup_end = (EventPowerUpEnd*)p_e;
			if (p_e_powerup_end->respawn) {
				new Bug();
				new Flower();
			}
			new PowerUp();
		}
		return 1;
	}
    return 0;
}

void GameState::normal() {
	p_normal_music->play();
	new Flower();
	new Bug();
	new PowerUp();
	int rand_timer = rand() % 21; // random timer between 0-20 seconds
	boss_timer = (11 - boss_level) * 30 + rand_timer * 30; // starts at 10 seconds + rand_timer, faster every level
}

void GameState::boss() {
	p_boss_music->play();
	EventClear es;
	WM.onEvent(&es);

	new Boss(boss_level);
	boss_level++;
}

int GameState::draw() {
	return 0;
}