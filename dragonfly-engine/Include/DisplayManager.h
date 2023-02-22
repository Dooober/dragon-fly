// logfile manager

#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__

#include <SFML/Graphics.hpp>
#include "Manager.h"
#include "Color.h"
#include "Vector.h"

#define DM df::DisplayManager::getInstance()

namespace df {

	enum Justification {
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED
	};

	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFALT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";

	class DisplayManager : public Manager {
	private:
		DisplayManager(); // Singleton
		DisplayManager(DisplayManager const&); // Don't allow copy
		void operator=(DisplayManager const&); // Don't allow assignment
		sf::Font font; // Font used for ASCII graphics
		sf::RenderWindow* p_window; // Pointer to SFML window
		int window_horizontal_pixels;
		int window_vertical_pixels;
		int window_horizontal_chars;
		int window_vertical_chars;

	public:
		static DisplayManager& getInstance(); // Get the display manager
		int startUp(); // Opens graphics window, ready for text-based display. Returns 0 if success, else -1
		void shutDown(); // Close graphics window
		int drawCh(Vector world_pos, char ch, Color color) const; // Draw character at window location (x, y) with color. Return 0 if success, else -1
		int drawString(Vector pos, std::string str, Justification just, Color color) const; // Draws string at window location (x,y). Return 0 if success, else -1
		int getHorizontal() const; // Return window's horizontal maximum (chars)
		int getVertical() const; // Return window's vertical maximum (chars)
		int getHorizontalPixels() const; // Return window's horizontal maximum (pixels)
		int getVerticalPixels() const; // Return window's vertical maximum (pixels)
		int swapBuffers(); // Render current window buffer. Return 0 if success, else -1
		sf::RenderWindow* getWindow() const; // Return pointer to SFML graphics window
		int setFont(std::string filename); // Sets the font (Mostly used for testing). Return 0 for success else -1
	};
}
#endif