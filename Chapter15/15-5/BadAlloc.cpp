#include <iostream>
#include <new>
using namespace std;

int main()
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "-th try to memory allocation" << endl;
			new int[10000][10000];
		}
	}
	/* catch(bad_alloc& bad) */
	catch(...)
	{
		/* cout << bad.what() << endl; */
		cout << "No more allocation!" << endl;
	}

	return 0;
}
