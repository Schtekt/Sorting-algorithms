#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "SortingClass.h"
class InsertionSort :public SortingClass
{
private:
	void insert(int currPos, int targetPos, SortingDisplay * disp);
public:
	void sort(SortingDisplay * disp);
};

#endif