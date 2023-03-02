#include "Object.h"
#include "ResourceManager.h"

enum GameStates {
	NORMAL, BOSS
};

class GameState : public df::Object {
private:
	GameStates state; // state of the game
	bool secret;
	df::Music* p_boss_music;
	df::Music* p_normal_music;

	int boss_timer; // Time before the boss spawns (in steps)
	int boss_level; // Level of next boss spawn

	void boss(); // starts a boss encounter
	void normal(); // starts the normal gameplay

public:
	GameState(bool secret=false);
	~GameState();
	int eventHandler(const df::Event* p_e);
	int draw() override;
};