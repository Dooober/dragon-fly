#include "Object.h"

class PowerUp : df::Object {
public:
	PowerUp();
	int eventHandler(const df::Event* p_e);
	void setRandomPosition();

};