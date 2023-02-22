#ifndef __EVENT_COLLISION_H__
#define __EVENT_COLLISION_H__

#include "Event.h"
#include "Object.h"

namespace df {
	const std::string COLLISION_EVENT = "df::collision";

	class EventCollision : public Event {
	private:
		Vector pos; // Where collision occured
		Object* p_obj1; // Object moving, causing collision
		Object* p_obj2; // Object being collided with

	public:
		EventCollision(); // Create empty collision event at (0,0)
		EventCollision(Object* p_o1, Object* p_o2, Vector p); // Create collision event between o1 and o2 at p. Object o1 caused collision
		void setObject1(Object* p_new_o1);
		Object* getObject1() const;
		void setObject2(Object* p_new_o2);
		Object* getObject2() const;
		void setPosition(Vector new_pos);
		Vector getPosition() const;
	};
}

#endif