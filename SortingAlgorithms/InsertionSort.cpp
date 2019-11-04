#include "InsertionSort.h"
#include "SortingDisplay.h"
void InsertionSort::insert(int currPos, int targetPos, SortingDisplay * disp)
{
	if (currPos != targetPos)
	{
		for (int i = currPos; i > targetPos; i--)
		{
			disp->swapNumbers(i - 1, i);
		}
	}
}

void InsertionSort::sort(SortingDisplay * disp)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j] > nums[i])
			{
				insert(i, j + 1, disp);
				break;
			}
			else if (j == 0)
			{
				insert(i, 0, disp);
			}
		}
	}
}
