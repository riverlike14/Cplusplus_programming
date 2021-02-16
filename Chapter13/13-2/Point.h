#ifndef __POINT_H__
#define __POINT_H__

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0);
	void ShowPosition() const;
	friend ostream& operator<< (ostream&, const Point&);
};

#endif
