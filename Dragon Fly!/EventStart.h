#ifndef __EVENT_START__
#define __EVENT_START__

#include "Event.h"

const std::string START_EVENT = "start_event";

class EventStart : public df::Event {
	public:
		EventStart();
};

#endif