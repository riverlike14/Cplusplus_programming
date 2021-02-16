#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int x, int y)
	: xpos(x), ypos(y)
{ }

void Point::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

ostream& operator<< (ostream& os, const Point& pt)
{
	os << '[' << pt.xpos << ", " << pt.ypos << ']';
	return os;
}
