#ifndef CONSOLEDRAWABLE
#define CONSOLEDRAWABLE
#include <Windows.h>
class ConsoleDrawable
{
public:
	COORD coordinate;
	COORD size;
	SMALL_RECT rect;
	CHAR_INFO * information;
public:
	ConsoleDrawable(const char * info, COORD size, COORD pos, WORD attribute);
	ConsoleDrawable(char * info, COORD size, COORD pos, WORD attribute);
	ConsoleDrawable(char info, COORD size, COORD pos, WORD attribute);
	ConsoleDrawable(CHAR_INFO * info, COORD size, COORD pos);
	~ConsoleDrawable();
	void move(int x, int y);
	void setPos(int x, int y);
	void setInfo(WORD info, int start, int end);
};

#endif
