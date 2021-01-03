#include <iostream>
#include <cstring>
#include "Account.h"
#include "BankingSystem.h"
using namespace std;

Account* accountList[100];
int count = 0;

void ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print every account information" << endl;
	cout << "5. End the program" << endl;
}

void CreateAccount(int accountID, char * name, int money)
{
	accountList[count] = new Account(accountID, name, money);
	count++;

	cout << "Create new account success!" << endl;
}

void DepositMoney(int accountID, int money)
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

void WithdrawMoney(int accountID, int money)
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

void ShowAllAccountInfo()
{
	for (int i = 0; i < count; i++)
	{
		accountList[i]->ShowInfo();
		cout << endl;
	}
}
