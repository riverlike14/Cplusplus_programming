#include <iostream>
#include <cstring>
#include "AccountHandler.h"
using namespace std;

AccountHandler::AccountHandler()
	: count(0)
{ };

void AccountHandler::ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print every account information" << endl;
	cout << "5. End the program" << endl;
}

void AccountHandler::CreateAccount(int accountID, char* name, int money)
{
	accountList[count++] = new Account(accountID, name, money);
	cout << "Create new account success!" << endl;
}

void AccountHandler::DepositMoney(int accountID, int money)
{
	for (int i = 0; i < count; i++)
	{
		if (accountList[i]->AccountIDCheck(accountID))
		{
			accountList[i]->Deposit(money);
			cout << "Money deposit success!" << endl;
			return;
		}
	}

	cout << "There is no account with an ID " << accountID << endl;
}

void AccountHandler::WithdrawMoney(int accountID, int money)
{
	for (int i = 0; i < count; i++)
	{
		if (accountList[i]->AccountIDCheck(accountID))
		{
			if (accountList[i]->Withdraw(money))
				cout << "Money withdraw success!" << endl;
			else
				cout << "Money withdraw failed..." << endl;
			return;
		}
	}

	cout << "There is no account with an ID " << accountID << endl;
}

void AccountHandler::ShowAllAccountInfo()
{
	for (int i = 0; i < count; i++)
	{
		accountList[i]->ShowInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < count; i++)
		delete accountList[i];
}
