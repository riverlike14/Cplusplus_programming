#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y)
		:xpos(x), ypos(y)
	{ }

	void ShowPointInfo() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

class Circle
{
private:
	Point center;
	int radius;

public:
	Circle(int x, int y, int r)
		:center(x, y), radius(r)
	{ }

	void ShowCircleInfo() const
	{
		cout << "Center: ";
		center.ShowPointInfo();
		cout << "Radius: " << radius << endl;
	}
};

class Ring
{
private:
	Circle innerCircle;
	Circle outerCircle;

public:
	Ring(int inx, int iny, int inr, int outx, int outy, int outr)
		:innerCircle(inx, iny, inr), outerCircle(outx, outy, outr)
	{ }

	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outerCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
