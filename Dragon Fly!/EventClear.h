#ifndef __EVENT_CLEAR__
#define __EVENT_CLEAR__

#include "Event.h"

const std::string CLEAR_EVENT = "clear";

class EventClear : public df::Event {
	public:
		EventClear();
};

#endif