#include "Projectile.h"
#include "LogManager.h"

Projectile::Projectile(df::Vector pos, float speed, df::Vector dir) {
	setSprite("projectile");

	setPosition(pos);
	setSpeed(speed);
	setDirection(dir); 
	setAltitude(3);
	setSolidness(df::SOFT);
}

void Projectile::setRandomPosition() {
	WM.markForDelete(this);
}