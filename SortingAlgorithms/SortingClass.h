#ifndef SORTINGCLASS_H
#define SORTINGCLASS_H
class SortingDisplay;
class SortingClass
{
protected:
	int* nums;
	int size;
public:
	void addNumbers(int* numbers, int size);
	virtual void sort(SortingDisplay * disp) = 0;
};

#endif