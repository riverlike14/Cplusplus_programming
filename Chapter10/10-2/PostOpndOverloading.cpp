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

	Point(const Point &pnt)
		: xpos(pnt.xpos), ypos(pnt.ypos)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator++()
	{
		xpos++;
		ypos++;
		return *this;
	}

	const Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos++;
		ypos++;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
}

const Point operator--(Point& ref, int)
{
	const Point retobj(ref);
	ref.xpos--;
	ref.ypos--;
	return retobj;
}

int main()
{
	Point pnt1(3, 4);
	(pnt1++).ShowPosition();
	pnt1.ShowPosition();

	return 0;
}
