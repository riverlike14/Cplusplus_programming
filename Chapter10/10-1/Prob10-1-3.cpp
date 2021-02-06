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

	friend bool operator==(const Point &pos1, const Point pos2);
	friend bool operator!=(const Point &pos1, const Point pos2);
};

bool operator==(const Point &pos1, const Point pos2)
{
	if (pos1.xpos != pos2.xpos)
		return false;
	if (pos1.ypos != pos2.ypos)
		return false;

	return true;
}

bool operator!=(const Point &pos1, const Point pos2)
{
	return !(pos1 == pos2);
}

int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos2.ShowPosition();

	cout << (pos1 == pos2) << endl;
	cout << (pos1 != pos2) << endl;

	return 0;
}

