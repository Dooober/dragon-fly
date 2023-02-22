#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <string>
#include "Manager.h"
#include "Sprite.h"
#include "Sound.h"
#include "Music.h"

#define RM df::ResourceManager::getInstance()

namespace df {
	const int MAX_SPRITES = 1000;
	const int MAX_SOUNDS = 64;
	const int MAX_MUSICS = 64;

	class ResourceManager : public Manager {
	private:
		ResourceManager(); // Singleton
		ResourceManager(ResourceManager const&); // Don't allow copy
		void operator=(ResourceManager const&); // Don't allow assignment
		Sprite* p_sprite[MAX_SPRITES]; // Array of sprites
		int sprite_count; // Count number of loaded sprites
		Sound sound[MAX_SOUNDS]; // Array of sound buffers
		int sound_count;
		Music music[MAX_MUSICS]; // Array of music buffers
		int music_count;

	public:
		static ResourceManager& getInstance(); // Get resource manager
		int startUp();
		void shutDown(); // Free up allocated sprites
		int loadSprite(std::string filename, std::string label); // Load sprite from file, return 0 if success else -1
		int unloadSprite(std::string label); // unload sprite, return 0 if success else -1
		Sprite* getSprite(std::string label) const;
		int loadSound(std::string filename, std::string label); // load sound, return 0 if success else -1
		int unloadSound(std::string label); // Remove sound, return 0 if success, else -1
		Sound* getSound(std::string label); // Find sound. Return pointer if found else NULL
		int loadMusic(std::string filename, std::string label); // load music, return 0 if success else -1
		int unloadMusic(std::string label); // Remove music, return 0 if success, else -1
		Music* getMusic(std::string label); // Find music. Return pointer if found else NULL
	};
}


#endif