#ifndef __EVENT_STEP_H__
#define __EVENT_STEP_H__

#include "Event.h"

namespace df {
	const std::string STEP_EVENT = "df::step";

	class EventStep : public Event {
	private:
		int step_count; // Iteration number of game loop

	public:
		EventStep();
		EventStep(int init_step_count); // Constructor with initial step count
		void setStepCount(int new_step_count);
		int getStepCount() const;
	};
}

#endif
