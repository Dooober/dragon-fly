#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>
#include "Frame.h"

namespace df {
	class Sprite {
	private:
		int width;
		int height;
		int max_frame_count; // Max number of frames a sprite can have
		int frame_count; // Actual number of frames sprite has
		Color color;
		int slowdown; // Animation slowdown (1=no slowdown, 0=stop)
		Frame* frame; // Array of frames
		std::string label; // Text label to identify sprite
		Sprite(); // Sprite always has one argument

	public:
		~Sprite(); // Destroy sprite and delete allocated frames
		Sprite(int max_frames);
		void setWidth(int new_width);
		int getWidth() const;
		void setHeight(int new_height);
		int getHeight() const;
		void setColor(Color new_color);
		Color getColor() const;
		int getFrameCount() const;
		int addFrame(Frame new_frame); // Return -1 if frame array full, else 0
		Frame getFrame(int frame_number) const; // Return empty frame if out of range
		void setLabel(std::string new_label);
		std::string getLabel() const;
		void setSlowdown(int new_sprite_slowdown);
		int getSlowdown() const;
		int draw(int frame_number, Vector position) const; // Draw indicated frame centered at position. Return 0 if success, else -1
		bool operator==(const Sprite& other) const; // Check if two sprites are equal (for testing)
	};
}

#endif
