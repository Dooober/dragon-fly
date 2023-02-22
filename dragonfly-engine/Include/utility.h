#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Vector.h"
#include "Box.h"
#include "Object.h"

namespace df {
	bool positionsIntersect(Vector p1, Vector p2);
	bool boxIntersectsBox(Box A, Box B);
	Vector worldToView(Vector world_pos);
	Vector viewToWorld(Vector view_pos);
	Box getWorldBox(const Object* p_o);
	Box getWorldBox(const Object* p_o, Vector where);
	std::string toString(int i);
	float charHeight();
	float charWidth();
	Vector spacesToPixels(Vector spaces);
	Vector pixelsToSpaces(Vector pixels);
}

#endif