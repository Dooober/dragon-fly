#include "PowerUpString.h"
#include "EventStep.h"
#include "WorldManager.h"

PowerUpString::PowerUpString(PowerUpType powerup_type, int lifetime) {
	std::string string;
	switch (powerup_type) {
	case CLEAR:
		string = "Clear time left:";
		break;
	case INVINCIBILITY:
		string = "Invincibility time left:";
		break;
	case MULTIPLIER:
		string = "Multiplier time left:";
		break;
	}
	setViewString(string);
	setValue(lifetime);
	this->lifetime = lifetime;
	setBorder(false);
}

int PowerUpString::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		if (lifetime == 0) {
			WM.markForDelete(this);
		}
		else {
			lifetime--;
			setValue(lifetime);
		}
		return 1;
	}
	return 0;
}