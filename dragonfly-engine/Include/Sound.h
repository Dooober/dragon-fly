#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Sound {
	private:
		sf::Sound sound;
		sf::SoundBuffer sound_buffer;
		std::string label;

	public:
		Sound();
		~Sound();
		int loadSound(std::string filename); // Load sound from file. Return 0 if success, else -1
		void setLabel(std::string new_label);
		std::string getLabel() const;
		void play(bool loop = false); // play sound, if loop is true then repeat
		void stop(); // stop sound
		void pause(); // Pause sound
		sf::Sound getSound() const; // return SFML sound
	};
}


#endif
