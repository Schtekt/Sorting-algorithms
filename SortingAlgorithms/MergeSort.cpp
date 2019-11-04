#include "MergeSort.h"
#include "SortingDisplay.h"

void MergeSort::merge(int left, int right, int middle, SortingDisplay* disp)
{
	int sizeOfLeft = middle - left + 1;
	int sizeOfRight = right - left - sizeOfLeft + 1;

	int* subLeft = new int[sizeOfLeft];
	int* subRight = new int[sizeOfRight];

	// keep track of the indices instead of the actual numbers.
	for (int i = left; i <= middle; i++)
	{
		subLeft[i - left] = i;
	}

	for (int i = 0; i < sizeOfRight; i++)
	{
		subRight[i] = i + 1 + middle;
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int globalIndex = 0;

	while (leftIndex < sizeOfLeft && rightIndex < sizeOfRight)
	{
		// the current right position is larger than the current left position.
		// place the current right position at the front, swapping a left position (not necesserily the current left position!)
		if (nums[subLeft[leftIndex]] < nums[subRight[rightIndex]])
		{
			disp->swapNumbers(globalIndex + left, subRight[rightIndex]);
			if (globalIndex < sizeOfLeft)
			{
				subLeft[globalIndex] = subRight[rightIndex];
			}
			else
			{
				subLeft[leftIndex] = subRight[rightIndex];
			}
			subRight[rightIndex++] = globalIndex + left;
			globalIndex++;
		}
		// If the current left position is not at the current position, place it there, swapping with the left position at front.
		else if(globalIndex + left != subLeft[leftIndex])
		{
			disp->swapNumbers(globalIndex + left, subLeft[leftIndex]);
			if (globalIndex < sizeOfLeft)
			{
				subLeft[globalIndex] = subLeft[leftIndex];
			}
			else
			{
				subLeft[leftIndex + 1] = subLeft[leftIndex];
			}
			subLeft[leftIndex++] = globalIndex + left;
			globalIndex++;
		}
		else
		{
			globalIndex++;
			leftIndex++;
		}
	}

	while (leftIndex < sizeOfLeft)
	{
		if (globalIndex + left != subLeft[leftIndex])
		{
			disp->swapNumbers(globalIndex + left, subLeft[leftIndex]);
			if (globalIndex < sizeOfLeft)
			{
				subLeft[globalIndex] = subLeft[leftIndex];
			}
			else
			{
				subLeft[leftIndex + 1] = subLeft[leftIndex];
			}
			subLeft[leftIndex++] = globalIndex + left;
			globalIndex++;
		}
		else
		{
			globalIndex++;
			leftIndex++;
		}
	}
	delete[] subRight;
	delete[] subLeft;

}

void MergeSort::divideAndMerge(int left, int right, SortingDisplay* disp)
{
	if (left < right)
	{
		int middle = (left + right) / 2;

		divideAndMerge(left, middle, disp);
		divideAndMerge(middle + 1, right, disp);
		merge(left, right, middle, disp);
	}
}

void MergeSort::sort(SortingDisplay * disp)
{
	divideAndMerge(0, size - 1, disp);
}
