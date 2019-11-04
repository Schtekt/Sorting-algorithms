#ifndef SORTINGDISPLAY_H
#define SORTINGDISPLAY_H
#include "ConsoleGraphics.h"
class SortingClass;
class SortingDisplay
{
private:
	std::vector<int> numbersToSort;
	std::vector<ConsoleDrawable*> representatives;
	ConsoleDrawable * sortStats;
	int nrOfSwaps;
	ConsoleGraphics * graf;
	SortingClass * sorter;

public:
	SortingDisplay(ConsoleGraphics* graf, int size, int consoleHeight);
	SortingDisplay(int size, int consoleHeight);
	~SortingDisplay();
	void pickSorter(SortingClass * sorter);
	void visualLoop();
	void swapNumbers(int firstIndex, int secondIndex);
	void colorIndex(int index, WORD attribute);
};

#endif