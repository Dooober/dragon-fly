#include "ViewObject.h"

class GameOver : public df::ViewObject {

public:
	GameOver();
	~GameOver();
	int draw() override;
};
