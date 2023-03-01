#include "Event.h"

const std::string BOSS_KILL_EVENT = "boss_kill";

class EventBossKill : public df::Event {
public:
	EventBossKill();
};
