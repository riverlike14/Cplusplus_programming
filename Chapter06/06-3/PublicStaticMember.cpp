#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main()
{
	cout << SoSimple::simObjCnt << "-th SoSimple instance" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "-th SoSimple instance" << endl;
	cout << sim1.simObjCnt << "-th SoSimple instance" << endl;
	cout << sim2.simObjCnt << "-th SoSimple instance" << endl;

	return 0;
}
