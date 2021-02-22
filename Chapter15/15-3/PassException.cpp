#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw (double)num2;
	cout << "quotient: " << num1/num2 << endl;
	cout << "remainder: " << num1%num2 << endl;
}

int main()
{
	int num1, num2;
	cout << "Type two numbers: ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2);
		cout << "End division." << endl;
	}
	catch (int expn)
	{
		cout << "dividor cannot be " << expn << endl;
		cout << "Rerun the probram." << endl;
	}
	catch (double expn)
	{
		cout << "Hello world" << endl;
	}

	Divide(num1, num2);

	cout << "End of the probram..." << endl;

	return 0;
}
