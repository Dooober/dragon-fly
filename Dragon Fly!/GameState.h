#include "Object.h"

enum GameStates {
	NORMAL, BOSS
};

class GameState : public df::Object {
private:
	GameStates state; // state of the game

	int boss_timer; // Time before the boss spawns (in steps)
	int boss_level; // Level of next boss spawn

	void boss(); // starts a boss encounter
	void normal(); // starts the normal gameplay

public:
	GameState();
	~GameState();
	int eventHandler(const df::Event* p_e);
	int draw() override;
};