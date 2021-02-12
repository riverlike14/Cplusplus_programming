#include <iostream>
using namespace std;

class BoundCheck2dIntArray
{
private:
	int** arr;
	int height;
	int width;

	BoundCheck2dIntArray(const BoundCheck2dIntArray& arr) { }
	BoundCheck2dIntArray& operator=(const BoundCheck2dIntArray& arr) { }
public: 
	BoundCheck2dIntArray(int height, int width)
		: height(height), width(width)
	{
		arr = new int*[height];
		for (int i = 0; i < height; i++) {
			arr[i] = new int[width];
		}
	}

	int* operator[] (int idx)
	{
		cout << "[]operator called...!" << endl;
		if (idx < 0 || idx >= height)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	~BoundCheck2dIntArray() {;}
};

int main()
{
	int height = 1;
	int width = 2;
	BoundCheck2dIntArray arr(height, width);

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			arr[i][j] = i + j;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cout << arr[i][j] << endl;

	return 0;
}
