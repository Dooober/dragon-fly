#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <Windows.h>

namespace df {
	long int msec(LPSYSTEMTIME systemtime);

	class Clock {
	private:
		long int previous_time; // Previous time delta() in microseconds

	public:
		Clock(); // Sets previous_time to current time
		long int delta(); // Return elapsed time since delta() was last called. Resets previous time.
		long int split() const; // Return elapsed time since delta() was last called. Does not reset previous time.
	};
}

#endif