#include "Quicksort.h"
#include "SortingDisplay.h"
void Quicksort::sortPartition(SortingDisplay * disp, int start, int end)
{
	if (start < end)
	{
		int pivotPos = end;
		int i = start;
		int j = end - 1;

		for (; i < j; i++)
		{
			if (nums[i] < nums[pivotPos])
			{
				for (; j > i; j--)
				{
					if (nums[j] >= nums[pivotPos])
					{
						disp->swapNumbers(i, j);
						break;
					}
				}
			}
		}
		
		for (int k = start; k < end; k++)
		{
			if (nums[k] < nums[pivotPos])
			{
				disp->swapNumbers(k, pivotPos);
				pivotPos = k;
				break;
			}
		}

		if(pivotPos - 1 > start)
			sortPartition(disp, start, pivotPos - 1);

		if(pivotPos + 1 < end)
			sortPartition(disp, pivotPos + 1, end);
	}
}

Quicksort::Quicksort()
{
}

void Quicksort::sort(SortingDisplay * disp)
{
	sortPartition(disp, 0, size - 1);
}