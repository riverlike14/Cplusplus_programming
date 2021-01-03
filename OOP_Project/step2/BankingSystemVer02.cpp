#include <iostream>
#include "Account.h"
#include "BankingSystem.h"
using namespace std;

int main()
{
	int button;
	int accountID;
	char * name = new char[NAME_LEN];
	int money;

	while (true)
	{
		ShowMenu();
		cin >> button;
		cout << endl;
		
		switch (button) {
			case CREATE:
				cout << "[CREATE]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Name: "; cin >> name;
				cout << "Deposit: "; cin >> money;
				CreateAccount(accountID, name, money);
				break;
			case DEPOSIT:
				cout << "[DEPOSIT]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Money to deposit: "; cin >> money;
				DepositMoney(accountID, money);
				break;
			case WITHDRAW:
				cout << "[WITHDRAW]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Money to withdraw: "; cin >> money;
				WithdrawMoney(accountID, money);
				break;
			case INQUIRE:
				cout << "[INFORMATION]" << endl;
				ShowAllAccountInfo();
				break;
			case EXIT:
				cout << "Bye..." << endl;
				goto ExitProgram;
			default:
				cout << "Wrong number typed. Try again..." << endl;
		}

		cout << endl;
	}

ExitProgram:
	delete name;
	return 0;
}
