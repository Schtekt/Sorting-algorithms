#include "HeapSort.h"
#include "SortingDisplay.h"
void HeapSort::heapify(int n, int root, SortingDisplay * disp)
{
	int largest = root;
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	if (left < n && nums[left] < nums[largest])
		largest = left;

	if (right < n && nums[right] < nums[largest])
		largest = right;

	if (largest != root)
	{
		disp->swapNumbers(largest, root);
		heapify(n, largest, disp);
	}
}

HeapSort::HeapSort()
{
}

void HeapSort::sort(SortingDisplay * disp)
{
	// create a min heap, the parent node will always be the smallest node.
	for (int i = size / 2; i >= 0; i--)
	{
		heapify(size, i, disp);
	}

	// remove the root node by inserting it in last place, 
	for (int i = size - 1; i >= 0; i--)
	{
		disp->swapNumbers(0, i);
		heapify(i, 0, disp);
	}
}
