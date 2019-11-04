#include "SortingDisplay.h"
#include "bubblesort.h"
#include "Quicksort.h"
#include "InsertionSort.h"
#include <iostream>
#include<time.h>
#include <string>

SortingDisplay::SortingDisplay(ConsoleGraphics * graf, int size, int consoleHeight): graf(graf), nrOfSwaps(0), sortStats(nullptr)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		int number = (rand() % (consoleHeight - 1)) + 2;
		numbersToSort.push_back(number);
		representatives.push_back(new ConsoleDrawable(' ', { 1, (SHORT)number }, { (SHORT)i * 2, (SHORT)(-number + consoleHeight + 1) }, number * 255 / consoleHeight));
	}
}
SortingDisplay::SortingDisplay(int size, int consoleHeight): nrOfSwaps(0), sortStats(nullptr)
{
	graf = new ConsoleGraphics();
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		int number = (rand() % (consoleHeight - 1)) + 2;
		numbersToSort.push_back(number);
		//representatives.push_back(new ConsoleDrawable(' ', { 1, (SHORT)number }, { (SHORT)i * 2, (SHORT)(-number + consoleHeight + 1) }, number*255/consoleHeight));
		representatives.push_back(new ConsoleDrawable(' ', { 1, (SHORT)number }, { (SHORT)i * 2, (SHORT)(-number + consoleHeight + 1) }, BACKGROUND_RED));
	}

	/*numbersToSort.push_back(20);
	numbersToSort.push_back(8);
	numbersToSort.push_back(6);
	numbersToSort.push_back(2);
	numbersToSort.push_back(4);
	numbersToSort.push_back(5);
	numbersToSort.push_back(7);
	numbersToSort.push_back(15);
	numbersToSort.push_back(11);*/

	for (int i = 0; i < numbersToSort.size(); i++)
	{
		representatives.push_back(new ConsoleDrawable(' ', { 1, (SHORT)numbersToSort[i] }, { (SHORT)(i) * 2, (SHORT)(-numbersToSort[i] + consoleHeight + 1) }, BACKGROUND_RED));
	}
}

SortingDisplay::~SortingDisplay()
{
	delete graf;
}

void SortingDisplay::pickSorter(SortingClass * sorter)
{
	this->sorter = sorter;
}

void SortingDisplay::visualLoop()
{
	for (int i = 0; i < representatives.size(); i++)
	{
		graf->addToDraw(representatives[i]);
	}

	graf->setActive();
	sorter->addNumbers(&numbersToSort[0], numbersToSort.size());
	graf->draw();
	nrOfSwaps = 0;
	sorter->sort(this);
	std::string tmp = "nr of swaps: " + std::to_string(nrOfSwaps);
	sortStats = new ConsoleDrawable(tmp.c_str(), {(SHORT)tmp.size(),1}, {100,2}, FOREGROUND_GREEN);
	graf->addToDraw(sortStats);
	graf->draw();
	while (true)
	{
		Sleep(500);
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			GetAsyncKeyState(VK_RETURN);
			while (GetAsyncKeyState(VK_ESCAPE))
			{
			}
			break;
		}
	}
	delete sorter;
}

void SortingDisplay::swapNumbers(int firstIndex, int secondIndex)
{
	nrOfSwaps++;
	SHORT tmp = representatives[firstIndex]->rect.Left;
	representatives[firstIndex]->setPos(representatives[secondIndex]->rect.Left, representatives[firstIndex]->rect.Top);
	representatives[secondIndex]->setPos(tmp, representatives[secondIndex]->rect.Top);

	ConsoleDrawable* tmpRep = representatives[firstIndex];
	representatives[firstIndex] = representatives[secondIndex];
	representatives[secondIndex] = tmpRep;
	graf->draw();
	Sleep(20);

	int tmpInt = numbersToSort[firstIndex];
	numbersToSort[firstIndex] = numbersToSort[secondIndex];
	numbersToSort[secondIndex] = tmpInt;
}

void SortingDisplay::colorIndex(int index, WORD attribute)
{
	representatives[index]->information->Attributes = attribute;
}
