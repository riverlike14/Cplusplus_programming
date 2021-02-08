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

	Point operator-()
	{
		Point pnt(-xpos, -ypos);
		return pnt;
	}
	
	Point operator~()
	{
		Point pnt(ypos, xpos);
		return pnt;
	}
};


int main()
{
	Point pnt1(3, 4);
	Point pnt2 = ~pnt1;
	pnt1.ShowPosition();
	pnt2.ShowPosition();

	return 0;
}
