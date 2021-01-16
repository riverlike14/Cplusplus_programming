#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
	
public:
	SoSimple(int n)
		:num(n)
	{ }

	SoSimple(const SoSimple &copy)
		:num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple &copy)" << endl;
	}

	void ShowData() const
	{
		cout << "Num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)
{
	ob.ShowData();
}

int main()
{
	SoSimple obj(7);
	cout << "Before call a function" << endl;
	SimpleFuncObj(obj);
	cout << "After call a function" << endl;

	return 0;
}
