#include <iostream>
using namespace std;

template <class T>
void SwapData(T& data1, T& data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0)
		: xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main()
{
	Point p1(3, 5);
	Point p2(-1, 1);
	p1.ShowPosition();
	p2.ShowPosition();

	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

	int num1 = 3;
	int num2 = 5;
	cout << num1 << ", " << num2 << endl;

	SwapData(num1, num2);
	cout << num1 << ", " << num2 << endl;

	return 0;
}
