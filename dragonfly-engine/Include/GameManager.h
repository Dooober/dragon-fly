#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Manager.h"

#define GM df::GameManager::getInstance()

namespace df {
	const int FRAME_TIME_DEFAULT = 33;

	class GameManager : public Manager {
	private:
		GameManager();
		GameManager(GameManager const&);
		void operator=(GameManager const&);
		bool game_over; // If true, game loop should stop
		int frame_time; // Target time per game loop in ms

	public:
		static GameManager& getInstance(); // Get the singleton instance of GameManager
		int startUp(); // Startup the GameManager
		void shutDown(); // Shuts down the GameManager
		void run(); // Run game loop
		void setGameOver(bool new_game_over = true); // Sets the game over status, if true game loop will stop
		bool getGameOver() const; // Get game over status
		int getFrameTime() const; // Return target time for game loop in ms
	};
}

#endif