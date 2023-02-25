#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Object.h"
#include "EventOut.h"
#include "WorldManager.h"
#include "Score.h"
#include "EventView.h"

#define MOVE_SPEED 1.0f

class Enemy : public df::Object {

public:
	Enemy();
	~Enemy();
	virtual void setRandomPosition() = 0; // Sets itself to a random y position and a set x position
	int eventHandler(const df::Event* p_e) override;
};

#endif // !__ENEMY_H__