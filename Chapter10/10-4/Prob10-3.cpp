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
	
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos)
{
	int x, y;
	scanf("%d %d", &x, &y);
	pos.xpos = x;
	pos.ypos = y;
	return is;
}


int main()
{
	Point pos1;
	cout << "Type x, y: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "Type x, y: ";
	cin >> pos2;
	cout << pos2;

	return 0;
}
