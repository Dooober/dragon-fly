#include "Object.h"

enum GameStates {
	STARTSCREEN, GAMEOVER, BOSS, NORMAL
};

class GameState : public df::Object {
private:
	GameStates state; // state of the game

	int boss_timer; // Time before the boss spawns (in steps)
	int boss_level; // Level of next boss spawn

	void startscreen(); // shows the GameStart sprite
	void gameover(); // shows the gameover text when player collides with an enemy
	void boss(); // starts a boss encounter
	void normal(); // starts the normal gameplay
	void start();

public:
	GameState();
	~GameState();
	int eventHandler(const df::Event* p_e);
	int draw() override;
};