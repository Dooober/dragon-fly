#ifndef __VIEW_OBJECT_H__
#define __VIEW_OBJECT_H__

#include <string>
#include "Object.h"
#include "Event.h"

namespace df {
	enum ViewObjectLocation {
		UNDEFINED = -1,
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT
	};

	class ViewObject : public Object {
	private:
		std::string view_string; // Label for value
		int value;
		bool draw_value; // True if should draw value
		bool border; // True if border around display
		Color color; // Color for text
		ViewObjectLocation location;

	public:
		ViewObject();
		virtual int draw() override;
		virtual int eventHandler(const Event* p_e) override;
		void setLocation(ViewObjectLocation new_location);
		ViewObjectLocation getLocation() const;
		void setValue(int new_value);
		int getValue() const;
		void setBorder(bool new_border);
		bool getBorder() const;
		void setColor(Color new_color);
		Color getColor() const;
		void setViewString(std::string new_view_string);
		std::string getViewString() const;
		void setDrawValue(bool new_draw_value = true);
		bool getDrawValue() const;
	};
}

#endif
