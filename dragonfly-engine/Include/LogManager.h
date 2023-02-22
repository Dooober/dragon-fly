// logfile manager

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>
#include "Manager.h"

#define LM df::LogManager::getInstance()

namespace df {
	const std::string LOGFILE_NAME = "dragonfly.log";
	char* getTimeString();

	class LogManager : public Manager {
	private:
		LogManager(); // Singleton
		LogManager(LogManager const&); // Don't allow copy
		void operator=(LogManager const&); // Don't allow assignment
		bool do_flush; // True if flush to disk after each write
		bool log_time_string; // If true, pre-pend the time string to the game's log message
		bool log_step_count; // If true, pre-pend the step count to the game's log message
		FILE* p_file; // Pointer to logfile struct

	public:
		~LogManager(); // if logfile is open, close it
		static LogManager& getInstance(); // Get the log manager
		int startUp(); // Opens the logfile
		void shutDown(); // Close logfile
		void setFlush(bool do_flush = true); // set flush of logfile after each write
		void logTimeString(bool do_log_time_string = true); // Pre-pend the time string to the game's log message
		//void logStepCount(bool log_step_count = true); // Pre-pend the step count to the game's log message
		int writeLog(const char* fmt, ...) const; // write to logfile, supports string formatting, return number of bytes written or -1 if error
	};
}
#endif