#ifndef __VECTOR_H__
#define __VECTOR_H__

namespace df {
	class Vector {
	private:
		float x; // Horizontal
		float y; // Vertical

	public:
		Vector(float init_x, float init_y); // Create Vector with (x,y)
		Vector(); // (0,0)
		void setX(float new_x);
		float getX() const;
		void setY(float new_y);
		float getY() const;
		void setXY(float new_x, float new_y);
		float getMagnitude() const; // Returns the magnitude of the vector
		void normalize(); // Normalize the vector
		void scale(float s); // Scale the vector
		Vector operator+(const Vector& other) const; // Add two vectors and returns a new one
		bool operator==(const Vector& other) const; // Check if two vectors are equal
	};
}

#endif