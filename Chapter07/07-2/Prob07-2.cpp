#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;

public:
	MyFriendInfo(char* myname, int myage)
		: age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}

	~MyFriendInfo()
	{
		delete []name;
	}

	void ShowMyFriendInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(char* name, int age, char* myaddr, char* myphone)
		: MyFriendInfo(name, age)
	{
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);

		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}

	~MyFriendDetailInfo()
	{
		delete []addr;
		delete []phone;
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "Address: " << addr << endl;
		cout << "Phone: " << phone << endl;
		cout << endl;
	}
};

int main()
{
	MyFriendDetailInfo detail1("Jang", 30, "Seoul", "010-4597-4921");
	MyFriendDetailInfo detail2("Lee", 26, "Daejeon", "010-9429-5720");

	detail1.ShowMyFriendDetailInfo();
	detail2.ShowMyFriendDetailInfo();

	return 0;
}
