#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
		: age(myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}

	void ShowPersonInfo() const
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}

	~Person()
	{
		delete []name;
		cout << "called destructor!" << endl;
	}

	Person& operator=(const Person& man)
	{
		delete []name;
		int len = strlen(man.name) + 1;
		name = new char[len];
		strcpy(name, man.name);
		age = man.age;
		return *this;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}
