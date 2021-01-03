#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2)
		:num1(n1), num2(n2)
	{
		cout << "Called SoSimple Constructor" << endl;
	}

	explicit SoSimple(SoSimple &copy)
		:num1(copy.num2), num2(copy.num1)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(15, 30);

	cout << "About to declare and initialize" << endl;
	// SoSimple sim2 = sim1; // Compile Error (no matching function)
	SoSimple sim2(sim1);

	cout << "After declare and initialize" << endl;
	sim2.ShowSimpleData();
	
	return 0;
}
