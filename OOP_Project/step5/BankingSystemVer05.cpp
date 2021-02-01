#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;

int main()
{
	int button;
	int accountID;
	char* name = new char[30];
	int money;

	AccountHandler manager;

	while (true)
	{
		manager.ShowMenu();
		cin >> button;
		cout << endl;
		
		switch (button) {
			case CREATE:
				cout << "[CREATE]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Name: "; cin >> name;
				cout << "Deposit: "; cin >> money;
				manager.CreateAccount(accountID, name, money);
				break;
			case DEPOSIT:
				cout << "[DEPOSIT]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Money to deposit: "; cin >> money;
				manager.DepositMoney(accountID, money);
				break;
			case WITHDRAW:
				cout << "[WITHDRAW]" << endl;
				cout << "Account ID: "; cin >> accountID;
				cout << "Money to withdraw: "; cin >> money;
				manager.WithdrawMoney(accountID, money);
				break;
			case INQUIRE:
				cout << "[INFORMATION]" << endl;
				manager.ShowAllAccountInfo();
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
	delete []name;
	return 0;
}
