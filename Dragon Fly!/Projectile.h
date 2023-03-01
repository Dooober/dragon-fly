#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "Enemy.h"

class Projectile : public Enemy {
public:
	Projectile(df::Vector pos, float speed, df::Vector dir); // Creates a projectile 
	void setRandomPosition(); // This will just delete the object so the boss can shoot another one
};


#endif // !__PROJECTILE_H__