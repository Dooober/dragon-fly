#ifndef __FRAME_H__
#define __FRAME_H__
#include <string>
#include "Vector.h"
#include "Color.h"

namespace df {

	class Frame {
	private:
		int width;
		int height;
		std::string frame_str;

	public:
		Frame(); // Create empty frame
		Frame(int new_width, int new_height, std::string frame_str); // Create frame
		void setWidth(int new_width);
		int getWidth() const;
		void setHeight(int new_height);
		int getHeight() const;
		void setString(std::string new_frame_str);
		std::string getString() const;
		int draw(Vector position, Color color) const; // Draw self centered at position with color, return 0 if success else -1
		bool operator==(const Frame& other) const; // Check if two frames are equal (for testing)
	};
}

#endif
