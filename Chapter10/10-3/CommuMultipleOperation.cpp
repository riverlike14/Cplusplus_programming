#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x=0, int y=0)
		: xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times)
	{
		Point pnt(xpos*times, ypos*times);
		return pnt;
	}

	friend Point operator*(int times, Point& pnt);
};

Point operator*(int times, Point& pnt)
{
	return pnt*times;
}


int main()
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3*pos;
	cpy.ShowPosition();

	cpy = 2*pos*3;
	cpy.ShowPosition();

	return 0;
}
