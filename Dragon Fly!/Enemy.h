// Enemy.h

#include "Object.h"
#include "EventOut.h"
#include "WorldManager.h"
#include "Score.h"

class Enemy : public df::Object {

private:
	int moveSpeed;
	void setRandomPosition(); // Sets itself to a random y position and a set x position

public:
	Enemy();
	~Enemy();
	int eventHandler(const df::Event* p_e) override;
};
