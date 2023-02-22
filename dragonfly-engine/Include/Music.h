#ifndef __MUSIC_H__
#define __MUSIC_H__

#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Music {
	private:
		Music(Music const&); // No copy
		void operator=(Music const&); // No assignment
		sf::Music music;
		std::string label;

	public:
		Music();
		int loadMusic(std::string filename); // Associate music buffer with file. Return 0 if success, else -1
		void setLabel(std::string new_label);
		std::string getLabel() const;
		void play(bool loop = true); // Play music, default to loop
		void stop();
		void pause();
		sf::Music* getMusic();
	};
}

#endif

