#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>
#include "Event.h"

namespace df {

	class Manager {
	private:
		std::string m_type; // Manager type
		bool is_started; // True when started successfully

	protected:
		void setType(std::string type); // Set type

	public:
		Manager();
		virtual ~Manager();

		std::string getType() const; // Get manager type
		virtual int startUp(); // Startup the manager, return 0 if successful, else return negative number
		virtual void shutDown(); // Shutdown the manager
		bool isStarted() const; // Return true when startUp() returns 0
		int onEvent(const Event* p_event) const; // Sends an event to all game objects, returns the number of objects an event is sent to
	};
}

#endif