#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include "Event.h"
#include "Vector.h"

namespace df {
	const std::string MSE_EVENT = "df::mouse";

	// Types of mouse actions df recognizes
	enum EventMouseAction {
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED,
		PRESSED,
		MOVED
	};

	// Keys df recognizes
	namespace Mouse {
		enum Button {
			UNDEFINED_MOUSE_BUTTON = -1,
			LEFT,
			RIGHT,
			MIDDLE
		};
	}

	class EventMouse : public Event {
	private:
		Mouse::Button mouse_button; // mouse button
		EventMouseAction mouse_action; // mouse action
		Vector mouse_xy; // mouse position

	public:
		EventMouse();
		void setMouseButton(Mouse::Button new_mouse_button);
		Mouse::Button getMouseButton() const;
		void setMouseAction(EventMouseAction new_action);
		EventMouseAction getMouseAction() const;
		void setMousePosition(Vector new_mouse_xy);
		Vector getMousePosition() const;
	};
}

#endif