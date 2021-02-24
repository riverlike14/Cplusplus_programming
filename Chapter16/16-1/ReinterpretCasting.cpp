#include <iostream>
using namespace std;

int main()
{
	int num = 0x123456;
	char* ptr = reinterpret_cast<char*>(&num);

	for (int i=0; i<sizeof(num); i++)
		cout << static_cast<int>(*(ptr+i)) << endl;

	cout << (int&)"123" << endl;

	return 0;
}
