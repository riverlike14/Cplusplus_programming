#include <iostream>

using namespace std;

class Printer
{
private:
	string str;
public:
	void SetString(string newstr);
	void ShowString();
};

void Printer::SetString(string newstr)
{
	str = newstr;
}

void Printer::ShowString()
{
	cout << str << endl;
}

int main()
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}
