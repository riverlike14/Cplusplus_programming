#ifndef __POINT_H__
#define __POINT_H__

class Point
{
private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypox);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

#endif
