#include "SelectionSort.h"
#include "SortingDisplay.h"
SelectionSort::SelectionSort()
{
}

void SelectionSort::sort(SortingDisplay * disp)
{
	for (int i = 0; i < size; i++)
	{
		int largestPos = i;
		for (int j = i; j < size; j++)
		{
			if (nums[largestPos] < nums[j])
			{
				largestPos = j;
			}
		}
		disp->swapNumbers(largestPos, i);
	}
}
