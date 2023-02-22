#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Vector.h"
#include "Event.h"
#include "Animation.h"
#include "Box.h"

namespace df {
	enum Solidness {
		HARD, // Collisions that impede
		SOFT, // Collisions that don't impede
		SPECTRAL // No collisions
	};

	class Object {
	private:
		int id; // Unique game engine defined identifier
		std::string type; // Game programmer defined type
		Vector position; // Position in the game world
		int altitude; // When to draw the object (0-4)
		Vector direction; // Direction vector
		float speed; // object speed in direction (magnitude)
		Solidness solidness; // Solidness to determine collisions
		Animation animation; // Animation associated with object
		Box box; // Box for sprite boundary and collisions 

	public:
		Object(); // Construct object and add to game world (WorldManager)
		virtual ~Object(); // Destroy Object and remove from game world (WorldManager)
		void setId(int new_id);
		int getId() const;
		bool operator==(const Object& other) const; // Objects are equal if IDs match
		void setType(std::string new_type);
		std::string getType() const;
		void setPosition(Vector new_pos);
		Vector getPosition() const;
		virtual int eventHandler(const Event* p_e); // Event Handling, Return 0 if ignored, 1 if handled
		virtual int draw(); // Draws the object, defined by game programmer
		int setAltitude(int new_altitude); // return 0 if success, else -1
		int getAltitude() const;
		void setSpeed(float speed);
		float getSpeed() const;
		void setDirection(Vector new_direction);
		Vector getDirection() const;
		void setVelocity(Vector new_velocity); // Sets direction and speed
		Vector getVelocity() const; // Gets velocity based on direction and speed
		Vector predictPosition(); // Predict Object position based on speed and direction.
		bool isSolid() const; // True if HARD or SOFT, else false
		int setSolidness(Solidness new_solid); // Return 0 for success, else -1
		Solidness getSolidness() const;
		int setSprite(std::string sprite_label); // Set sprite for this object to animate, return 0 if success else -1
		void setAnimation(Animation new_animation); // Set animation for this Object to a new one. Set bounding box to size of associated Sprite
		Animation getAnimation() const; // Get animation for this Object
		void setBox(Box new_box); // Set Object's bounding box
		Box getBox() const; // Get Object's bounding box
	};
}

#endif
