#include "Boss.h"
#include "Score.h"
#include "Projectile.h"

#include "EventView.h"
#include "EventStep.h"
#include "EventOut.h"
#include "EventBossKill.h"
#include "WorldManager.h"

Boss::Boss(int difficulty) {
	this->difficulty = difficulty;
	setType("Boss");
	setSprite("dragonfly");
	setPosition(df::Vector(WM.getBoundary().getHorizontal() + 5, WM.getBoundary().getVertical() / 2)); // Position off screen
	setVelocity(df::Vector(-0.5, 0)); // Move on screen slowly

	state = ENTERING;
	lifetime = difficulty + 2; // 3 actions to start, then add 1 per difficulty level
	rest_position = getPosition() + df::Vector(-12, 0); // Rest position on the screen

	if (difficulty > 12) // time between actions = 3 seconds - 0.25 seconds per difficulty, until difficulty 12
		time_between_actions = 0;
	else
		time_between_actions = (6 - difficulty) * 15; // (3 * 30) - (difficulty * 15) = (6 - difficulty) * 15
	wait_timer = time_between_actions;
	
	max_projectiles = difficulty;
	projectile_count = 0;
	projectile_speed = (difficulty * 0.1) + 0.5; // Speed of projectiles slowly scales with difficulty
	if (difficulty > 15) // Delay starts 15, decreases every diffulty until difficulty 15
		shooting_delay = 0;
	else
		shooting_delay = 15 - difficulty;
	steps_until_shot = shooting_delay;

	attack_speed = (difficulty * 0.1) + 1; // Speed of melee attacks scales with difficulty
	reset_speed = 0.5;
}

Boss::~Boss() {}

int Boss::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::STEP_EVENT) {
        step();
        return 1;
    }
    if (p_e->getType() == df::OUT_EVENT) {
		df::EventView ev(SCORE_STRING, 50 * difficulty, true);
		EventBossKill ebk;
		WM.onEvent(&ev);
		WM.onEvent(&ebk);
		WM.markForDelete(this);
        return 1;
    }
    return 0;
}

void Boss::step() {
	switch (state) {
	case ENTERING:
		enter();
		break;
	case LEAVING:
		leave();
		break;
	case WAITING:
		wait();
		break;
	case SHOOTING:
		shoot();
		break;
	case ATTACKING:
		attack();
		break;
	case RESETTING:
		reset();
		break;
	}
}


void Boss::enter() {
	if (getPosition() == rest_position) { // Switch to watiting state
		state = WAITING;
		setVelocity(df::Vector(0, 0));
	}
}

void Boss::leave() {}

void Boss::wait() {
	if (lifetime == 0) {
		state = LEAVING;
		setVelocity(df::Vector(0.5, 0));
		return; 	// If this triggers, we want the function to end here so that the state can never change
	}
	
	if (wait_timer == 0) {
		// Choose between the two attacks
		int choice = rand() % 2;
		if (choice == 0)
			state = ATTACKING;
		else
			state = SHOOTING;


		// Reset the wait timer, and decrease the lifetime
		wait_timer = time_between_actions;
		lifetime--;
	}
	else wait_timer--;
}

// Calculates the hero's position
df::Vector getHeroPos() {
	df::ObjectList hlist = WM.objectsOfType("Hero");
	df::ObjectListIterator hli(&hlist);
	df::Object* hero = hli.currentObject();
	df::Vector hero_pos = hero->getPosition();
	return hero_pos;
}

// Calculates the direction vector of an attack
df::Vector calculateDir(df::Vector target, df::Vector pos) {
	df::Vector dir(target.getX() - pos.getX(), target.getY() - pos.getY()); // Vector subtraction, since Cooper's engine does not support it
	dir.normalize(); // Normalize since we just want the direction vector, not the velocity
	return dir;
}

void Boss::shoot() {
	if (steps_until_shot == 0) {
		// Get the hero's position
		df::Vector hero_pos = getHeroPos();

		// Shoot a projectile at the hero
		df::Vector pos = getPosition();
		df::Vector dir = calculateDir(hero_pos, pos);
		new Projectile(pos, projectile_speed, dir);


		// Reset timer, increase projectile count
		steps_until_shot = shooting_delay;
		projectile_count++;
	}
	else steps_until_shot--;

	// Runs last so that the state does not change before an extra projectile is shot
	if (projectile_count == max_projectiles) {
		projectile_count = 0;
		state = WAITING;
	}
}

void Boss::attack() {
	// If this is the first time it is called in an action, set the target position just like in shoot
	if (getSpeed() == 0) {
		// Get the hero's position
		df::Vector hero_pos = getHeroPos();

		// Attack the hero
		df::Vector dir = calculateDir(hero_pos, getPosition());
		setDirection(dir);
		setSpeed(attack_speed);
	}

	// If the boss misses the hero, change state
	if (getPosition().getX() < 5) {
		state = RESETTING;
		df::Vector dir = calculateDir(rest_position, getPosition());
		setDirection(dir);
	}
}

void Boss::reset() {

	// If the boss reaches a suitable x position, end the action
	if (getPosition().getX() >= rest_position.getX()) {
		state = WAITING;
		setSpeed(0);
	}

}