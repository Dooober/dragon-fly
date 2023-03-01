// GameStar.h

#include "ViewObject.h"

class GameStart : public df::ViewObject {
	public:
		bool active;
		GameStart();
		int eventHandler(const df::Event* p_e) override;
		int draw() override;
};