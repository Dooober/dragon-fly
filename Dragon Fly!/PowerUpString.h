#include "ViewObject.h"

enum PowerUpType {
	CLEAR, INVINCIBILITY, MULTIPLIER
};

class PowerUpString : public df::ViewObject {
private:
	int lifetime;
	PowerUpType powerup_type;

public:
	PowerUpString(PowerUpType powerup_type, int lifetime);
	int eventHandler(const df::Event* p_e) override;
};