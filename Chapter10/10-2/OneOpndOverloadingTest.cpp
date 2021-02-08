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

	void operator++()
	{
		xpos += 1;
		ypos += 1;
	}
};

int main()
{
	Point pos(1, 2);
	++pos;
	pos.ShowPosition();

	/* ++(++pos); */
	pos.ShowPosition();

	return 0;
}
