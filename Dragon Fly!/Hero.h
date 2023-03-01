// Hero.h

#include "EventKeyboard.h"
#include "EventCollision.h"
#include "Object.h"
#include "Clock.h"

class Hero : public df::Object {

private:
	float fallSpeed;
	float moveSlowdown;
	float moveCountdown;
	void kbd(const df::EventKeyboard* p_keyboard_event);
	void move(int dy);
	void step();
	int powerUpDuration;
	int lastPowerUp;

public:
	Hero();
	~Hero();
	int eventHandler(const df::Event* p_e) override;
};
