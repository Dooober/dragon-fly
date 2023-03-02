// GameStar.h

#include "ViewObject.h"
#include "ResourceManager.h"

class GameStart : public df::ViewObject {
	private:
		void start(bool secret);
		df::Music* p_music;

	public:
		bool active;
		GameStart();
		int eventHandler(const df::Event* p_e) override;
		int draw() override;
};