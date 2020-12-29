#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

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
	void Init(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	}

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
	Circle innerCircle, outerCircle;

public:
	void Init(int inx, int iny, int inr, int outx, int outy, int outr)
	{
		innerCircle.Init(inx, iny, inr);
		outerCircle.Init(outx, outy, outr);
	}

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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
