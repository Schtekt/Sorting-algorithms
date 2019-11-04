#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortingClass.h"
class SortingDisplay;
class MergeSort : public SortingClass
{
private:
	void merge(int left, int right, int middle, SortingDisplay* disp);
	void divideAndMerge(int left, int right, SortingDisplay* disp);
public:
	void sort(SortingDisplay * disp);
};

#endif