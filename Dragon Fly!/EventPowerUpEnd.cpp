#include "EventPowerUpEnd.h"

EventPowerUpEnd::EventPowerUpEnd(bool respawn) {
	setType(POWERUP_END_EVENT);
	this->respawn = respawn;
}