#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};

	void ShowPositionInfo(int position)
	{
		switch (position)
		{
			case CLERK:
				cout << "Position: CLERK" << endl;
				break;
			case SENIOR:
				cout << "Position: SENIOR" << endl;
				break;
			case ASSIST:
				cout << "Position: ASSIST" << endl;
				break;
			case MANAGER:
				cout << "Position: MANAGER" << endl;
				break;
		}
	}
}

class NameCard
{
private:
	char * name;
	char * company;
	char * phone;
	int position;

public:
	NameCard(char * myname, char * mycompany, char * myphone, int myposition)
		:position(myposition)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);

		company = new char[strlen(mycompany) + 1];
		strcpy(company, mycompany);

		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}

	NameCard(const NameCard &copy)
		:position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);

		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}

	void ShowNameCardInfo() const
	{
		cout << "Name: " << name << endl;
		cout << "Company: " << company << endl;
		cout << "Phone: " << phone << endl;
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}

	~NameCard()
	{
		delete []name;
		delete []company;
		delete []phone;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}
