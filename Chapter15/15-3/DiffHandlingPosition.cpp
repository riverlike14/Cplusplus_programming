#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

	for (int i=0; i<len; i++)
	{
		if (str[i]<'0' || str[i]>'9')
			throw str[i];
		num += (int)(pow((double)10, (len-1)-i) * (str[i]-'0'));
	}
	return num;
}

int main()
{
	char str1[100];
	char str2[200];

	try {

		while(true)
		{
			cout << "Type two numbers: ";
			cin >> str1 >> str2;

			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			cout << "Hello error" << endl;
		
			break;

			/* try */
			/* { */
			/* 	cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl; */
			/* 	break; */
			/* } */
			/* catch (char ch) */
			/* { */
			/* 	cout << "Character " << ch << " has been typed" << endl; */
			/* 	cout << "Retype process start..." << endl << endl; */
			/* } */
		}

	}
	catch (char ch)
	{
		cout << "Hello world" << endl;
	}

	cout << "End of the program" << endl;
	return 0;
}
