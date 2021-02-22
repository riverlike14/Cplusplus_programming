#include <iostream>
using namespace std;

void Divide(int num1, int num2) throw (int)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "quotient: " << num1/num2 << endl;
		cout << "remainder: " << num1%num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw;
	}
}

int main()
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch(int expn)
	{
		cout << "second catch" << endl;
	}

	return 0;
}
