#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <string>
#include "Sprite.h"
#include "Box.h"

namespace df {
	class Animation {
	private:
		Sprite* p_sprite; // Sprite
		std::string name; // Sprite name in ResourceManager
		int index; // Current index frame for Sprite
		int slowdown_count; // Slowdown counter

	public:
		Animation();
		void setSprite(Sprite* p_new_sprite);
		Sprite* getSprite() const;
		void setName(std::string new_name);
		std::string getName() const;
		void setIndex(int new_index);
		int getIndex() const;
		void setSlowdownCount(int new_slowdown_count); // -1 means stop animation
		int getSlowdownCount() const; // -1 means stop animation
		int draw(Vector position); // Draw single frame centered at position (x,y). Accounts for slowdown, advances Sprite frame. Return 0 if success, else -1
		Box getBox() const; // Get bounding box of associated sprite
		bool operator==(const Animation& other) const; // Check if two animations are equal (for testing)
	};
}


#endif