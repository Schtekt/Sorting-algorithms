#include "Menu.h"
#include "SortingDisplay.h"
#include "bubblesort.h"
#include "Quicksort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

Menu::Menu(ConsoleGraphics * graf) : graf(graf)
{
	menuItems.push_back(new ConsoleDrawable("Bubblesort", { 10,1 }, { 0,0 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("HeapSort", { 8,1 }, { 0,2 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("MergeSort", { 9,1 }, { 0,4 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Selection sort", { 14,1 }, { 0,6 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Insertion sort", { 14,1 }, { 0, 8 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Quicksort", { 9,1 }, { 0,10 }, BACKGROUND_BLUE));

	selectedOption = 0;
	menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
}

Menu::Menu(): graf(new ConsoleGraphics())
{
	menuItems.push_back(new ConsoleDrawable("Bubblesort", { 10,1 }, { 0,0 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("HeapSort", { 8,1 }, { 0,2 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("MergeSort", { 9,1 }, { 0,4 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Selection sort", { 14,1 }, { 0,6 }, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Insertion sort", { 14,1 }, { 0, 8}, BACKGROUND_BLUE));
	menuItems.push_back(new ConsoleDrawable("Quicksort", { 9,1 }, { 0,10 }, BACKGROUND_BLUE));
	selectedOption = 0;
	menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
}

Menu::~Menu()
{
	delete graf;
}

void Menu::display()
{
	graf->setActive();
	for (int i = 0; i < menuItems.size(); i++)
	{
		graf->addToDraw(menuItems[i]);
	}
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			while (GetAsyncKeyState(VK_ESCAPE))
			{
			}
			break;
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			menuItems[selectedOption]->setInfo(BACKGROUND_BLUE, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			selectedOption = selectedOption == 0 ? menuItems.size() - 1:(selectedOption - 1) % menuItems.size();
			menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			menuItems[selectedOption]->setInfo(BACKGROUND_BLUE, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			selectedOption = (selectedOption + 1) % menuItems.size();
			menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_UP))
		{
			menuItems[selectedOption]->setInfo(BACKGROUND_BLUE, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			selectedOption = selectedOption == 0 ? menuItems.size() - 1 : (selectedOption - 1) % menuItems.size();
			menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			menuItems[selectedOption]->setInfo(BACKGROUND_BLUE, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			selectedOption = (selectedOption + 1) % menuItems.size();
			menuItems[selectedOption]->setInfo(BACKGROUND_GREEN, 0, menuItems[selectedOption]->size.X*menuItems[selectedOption]->size.Y);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			SortingDisplay disp(60, 30);
			SortingClass * sorter;
			switch (selectedOption)
			{
			case 0:
				sorter = new Bubblesort();
				break;
			case 1:
				sorter = new HeapSort();
				break;
			case 2:
				sorter = new MergeSort();
				break;
			case 3:
				sorter = new SelectionSort();
				break;
			case 4:
				sorter = new InsertionSort();
				break;
			case 5:
				sorter = new Quicksort();
				break;

			default:
				sorter = nullptr;
				break;
			}
			if (sorter != nullptr)
			{
				disp.pickSorter(sorter);
				disp.visualLoop();
			}
		}

		graf->draw();
		Sleep(100);
	}
}
