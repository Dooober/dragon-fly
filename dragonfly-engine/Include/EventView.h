#ifndef __EVENT_VIEW_H__
#define __EVENT_VIEW_H__

#include "Event.h"

namespace df {
	const std::string VIEW_EVENT = "df::view";

	class EventView : public Event {
	private:
		std::string tag;
		int value;
		bool delta;

	public:
		EventView();
		EventView(std::string new_tag, int new_value, bool new_delta);
		void setTag(std::string new_tag);
		std::string getTag() const;
		void setValue(int new_value);
		int getValue() const;
		void setDelta(bool new_delta);
		bool getDelta() const;
	};
}

#endif
