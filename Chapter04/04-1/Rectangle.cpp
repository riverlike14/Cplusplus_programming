#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
	if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY()))
	{
		cout << "Wrong initial position" << endl;
		return false;
	}

	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{
	cout << "Upper Left: [" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
	cout << "Lower Right: [" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << endl;
	cout << endl;
}
