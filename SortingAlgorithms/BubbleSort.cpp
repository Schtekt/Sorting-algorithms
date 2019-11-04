#include "BubbleSort.h"
#include "SortingDisplay.h"
Bubblesort::Bubblesort()
{
}

void Bubblesort::sort(SortingDisplay* disp)
{
	bool swap = true;
	while (swap)
	{
		swap = false;
		for (int i = 1; i < size; i++)
		{
			if (nums[i] > nums[i - 1])
			{
				disp->swapNumbers(i, i - 1);
				swap = true;
			}
		}
	}
}
