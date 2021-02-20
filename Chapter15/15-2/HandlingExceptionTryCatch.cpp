#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "Type two numbers: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "quotient: " << num1 / num2 << endl;
		cout << "remainder: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "dividor cannot be zero..." << endl;
		cout << "Rerun the program..." << endl;
	}

	cout << "end of main" << endl;

	return 0;
}
