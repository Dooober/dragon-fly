#ifndef __EVENT_POWER_UP_END__
#define __EVENT_POWER_UP_END__

#include "Event.h"

const std::string POWERUP_END_EVENT = "powerup_end";

class EventPowerUpEnd : public df::Event {
public:
	bool respawn;
	EventPowerUpEnd(bool respawn=false);
};

#endif