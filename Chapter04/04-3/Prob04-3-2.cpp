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
		int len;

		len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);

		len = strlen(mycompany) + 1;
		company = new char[len];
		strcpy(company, mycompany);

		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy(phone, myphone);
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
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
