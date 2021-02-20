#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "Type two numbers: ";
	cin >> num1 >> num2;

	if (num2 == 0)
	{
		cout << "dividor cannot be zero..." << endl;
		cout << "Rerun the program..." << endl;
	} else {
		cout << "quotient: " << num1 / num2 << endl;
		cout << "remainder: " << num1 % num2 << endl;
	}

	return 0;
}
