#include "Score.h"

Score::Score() {
	setBorder(false);
	setViewString(SCORE_STRING);
	setLocation(df::TOP_RIGHT);
	setColor(df::CYAN);
	setValue(0);
}
