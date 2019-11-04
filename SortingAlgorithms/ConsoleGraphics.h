#ifndef CONSOLEGRAPHICS
#define CONSOLEGRAPHICS
#include "ConsoleDrawable.h"
#include <vector>
class ConsoleGraphics
{
private:
	HANDLE first, second;
	HANDLE * active;
	std::vector<ConsoleDrawable*> toDraw;
public:
	ConsoleGraphics();
	~ConsoleGraphics();
	void setActive();
	void addToDraw(ConsoleDrawable* drawable);
	void draw();
	void clear(int numberOfChars);
};

#endif // !CONSOLEGRAPHICS
