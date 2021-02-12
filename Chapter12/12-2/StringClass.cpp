#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* str;
public:
	String()
	{
		str = NULL;
	}

	String(const char* mystr)
	{
		str = new char[strlen(mystr) + 1];
		strcpy(str, mystr);
	}

	String(const String& mystr)
	{
		str = new char[strlen(mystr.str) + 1];
		strcpy(str, mystr.str);
	}

	String& operator=(const String& mystr)
	{
		if (str != NULL)
			delete []str;
		str = new char[strlen(mystr.str) + 1];
		strcpy(str, mystr.str);
		return *this;
	}

	String operator+(const String& mystr)
	{
		char* ans = new char[strlen(str) + strlen(mystr.str) + 1];
		strcpy(ans, str);
		strcat(ans, mystr.str);
		String ret(ans);
		delete []ans;
		return ret;
	}

	String& operator+=(const String& mystr)
	{
		/* *this = *this + mystr; */
		char* ans = new char[strlen(str) + strlen(mystr.str) + 1];
		strcpy(ans, str);
		strcat(ans, mystr.str);
		if (str != NULL)
			delete []str;
		str = ans;
		return *this;
	}

	bool operator==(const String& mystr)
	{
		return !strcmp(str, mystr.str);
	}

	friend ostream& operator<<(ostream& os, const String&);
	friend istream& operator>>(istream& os, String&);

	~String()
	{
		if (str != NULL)
			delete []str;
	}
};

ostream& operator<<(ostream& os, const String& mystr)
{
	os << mystr.str;
	return os;
}

istream& operator>>(istream& is, String& mystr)
{
	char str[100];
	is >> str;
	mystr = String(str);
	return is;
}

int main()
{
	String str1 = "I'm ";
	String str2 = "Wooyoung Jang";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "Identical string!" << endl;
	else
		cout << "Different string!" << endl;

	String str4;
	cout << "Enter string: ";
	cin >> str4;
	cout << "Entered string: " << str4 << endl;

	return 0;
}
