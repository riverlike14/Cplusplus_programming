#include <iostream>
#include "BoundCheckArray.h"
#include "BoundCheckArray.cpp"
#include "Point.h"
using namespace std;

typedef Point pt;
typedef Point* ptptr;

int main()
{
	int len = 5;

	BoundCheckArray<int> arr(len);
	for (int i = 0; i < arr.GetArrLen(); i++)
		arr[i] = i*i;
	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i] << endl;

	BoundCheckArray<pt> arrPoint(len);
	for (int i = 0; i < arrPoint.GetArrLen(); i++)
		arrPoint[i] = Point(i, i*i);
	for (int i = 0; i < arrPoint.GetArrLen(); i++)
		cout << arrPoint[i] << endl;

	BoundCheckArray<ptptr> arrPointPtr(len);
	for (int i = 0; i < len; i++)
		arrPointPtr[i] = new Point(i, i*i);
	/* for (int i = 0; i < len; i++) */
	/* 	arrPointPtr[i]->ShowPosition(); */
	for (int i = 0; i < arrPointPtr.GetArrLen(); i++)
		cout << *(arrPointPtr[i]) << endl;
	for (int i = 0; i < arrPointPtr.GetArrLen(); i++)
		delete arrPointPtr[i];

	return 0;
}
