#ifndef __BOSS_H__
#define __BOSS_H__

#include "Object.h"

#define ENTER_LEAVE_SPEED 1
enum BossState {
	ENTERING, LEAVING, WAITING, SHOOTING, ATTACKING, RESETTING
};

class Boss : public df::Object {
private:
	// General boss attributes
	int difficulty; // Difficulty set when creating the boss
	BossState state; // The current state that the boss is in
	int lifetime; // Number of actions left before the boss leaves
	df::Vector rest_position; // Where the boss rests on screen

	// Waiting attributes
	int time_between_actions; // Number of steps between attacks
	int wait_timer;

	// Shooting attributes
	int max_projectiles; // Number of projectiles in a "Shooting" attack
	int projectile_count; // Number of projectiles that have been shot in current attack
	float projectile_speed; // Speed of the projectiles
	int shooting_delay; // Number of steps in between shots
	int steps_until_shot; // Number of steps left until the next shot

	// Attacking/Resetting attributes
	float attack_speed; // Speed of an "Attacking" action
	float reset_speed; // Speed of the "Resetting" action


	void step(); // step event

	// These functions each correspond to a state in the finite state machine
	void enter(); // Boss enters the screen
	void leave(); // Boss leaves the screen
	void wait(); // Boss waiting for a new action
	void shoot(); // Boss shoots projectiles at the player
	void attack(); // Boss moves towards player
	void reset(); // Boss resets position to resting position after attacking

public:
	Boss(int difficulty);
	~Boss();
	int eventHandler(const df::Event* p_e);
};


#endif