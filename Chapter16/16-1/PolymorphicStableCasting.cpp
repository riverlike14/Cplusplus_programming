#include <iostream>
using namespace std;

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
private:
	int num;
public:
	SoComplex(int test=0)
		: num(test)
	{ }

	void test()
	{
		cout << "Test" << endl;
	}

	virtual void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main()
{
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	if (comPtr == NULL)
		cout << "Type cast failed..." << endl;
	else
		comPtr->ShowSimpleInfo();

	return 0;
}
