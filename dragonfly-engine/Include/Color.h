#ifndef __COLOR_H__
#define __COLOR_H__

namespace df {
	enum Color {
		UNDEFINED_COLOR = -1,
		BLACK = 0,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};
	const Color COLOR_DEFAULT = WHITE;
}

#endif