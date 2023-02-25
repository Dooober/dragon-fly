#include "Enemy.h"

#define BUG_DISTANCE 4
#define BUG_Y_SPEED 0.25f

class Bug : public Enemy {
private:
	int max_y; // bug will move between the max and min y, set by BUG_DISTANCE
	int min_y;

public:
	Bug();
	void setRandomPosition(); // Sets itself to a random y position and a set x position
	int eventHandler(const df::Event* p_e) override;
};