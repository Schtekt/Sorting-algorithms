#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortingClass.h"

class HeapSort : public SortingClass
{
private:
	void heapify(int n, int root, SortingDisplay* disp);
public:
	HeapSort();
	void sort(SortingDisplay * disp);
};


#endif