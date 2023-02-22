#ifndef __BOX_H__
#define __BOX_H__

#include "Vector.h"

namespace df {
	class Box {
	private:
		Vector corner; // Upper left corner
		float horizontal;
		float vertical;

	public:
		Box(); // corner = (0,0), 0 horizontal, 0 vertical
		Box(Vector init_corner, float init_horizontal, float init_vertical);
		void setCorner(Vector new_corner);
		Vector getCorner() const;
		void setHorizontal(float new_horizontal);
		float getHorizontal() const;
		void setVertical(float new_vertical);
		float getVertical() const;
		bool operator==(const Box& other) const; // Check if two boxes are equal (for testing)
	};
}

#endif
