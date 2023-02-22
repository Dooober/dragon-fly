#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Manager.h"

#define IM df::InputManager::getInstance()

namespace df {

	class InputManager : public Manager {
	private:
		InputManager(); // Singleton
		InputManager(InputManager const&); // Don't allow copy
		void operator=(InputManager const&); // Don't allow assignment


	public:
		static InputManager& getInstance(); // Get the only instance of the InputManager
		int startUp(); // Startup game world
		void shutDown(); // Shutdown game world
		void getInput();
	};
}


#endif