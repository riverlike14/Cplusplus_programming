#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;

int main()
{
	int button;

	AccountHandler manager;

	while (true)
	{
		manager.ShowMenu();
		cin >> button;
		cout << endl;
		
		switch (button) {
			case CREATE:
				manager.CreateAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case INQUIRE:
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
	return 0;
}
