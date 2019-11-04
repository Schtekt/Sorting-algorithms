#ifndef MENU_H
#define MENU_H
#include "SortingDisplay.h"
class Menu
{
private:
	std::vector<ConsoleDrawable*> menuItems;
	ConsoleGraphics * graf;
	int selectedOption;
public:
	Menu(ConsoleGraphics* graf);
	Menu();
	~Menu();
	void display();
};

#endif