#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortingClass.h"
class Quicksort: public SortingClass
{
private:
	void sortPartition(SortingDisplay * disp, int start, int end);
public:
	Quicksort();
	void sort(SortingDisplay * disp);
};

#endif