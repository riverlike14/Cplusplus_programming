#include <iostream>
#include <cstring>
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

using namespace std;

enum {
	CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

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

void AccountHandler::CreateAccount()
{
	int button;
	cout << "[ACCOUNT SELECT]" << endl;
	cout << "1. Normal Account 2. High Credit Account" << endl;
	cout << "Select: " << endl; cin >> button;

	// if (button == NORMALACCOUNT)
	if (button == 1)
		AccountHandler::CreateNormalAccount();
	// else if (button == HIGHCREDITACCOUNT)
	else if (button == 2)
		AccountHandler::CreateHighCreditAccount();
	else
		cout << "No Account Type Selected..." << endl;
}

void AccountHandler::CreateNormalAccount()
{
	int accountID;
	char* name = new char[30];
	int money;
	int interest;

	cout << "[CREATE NORMAL ACCOUNT]" << endl;
	cout << "Account ID: "; cin >> accountID;
	cout << "Name: "; cin >> name;
	cout << "Deposit: "; cin >> money;
	cout << "Interest rate: "; cin >> interest;
	accountList[count++] = new NormalAccount(accountID, name, money, interest);
	cout << "Create new account success!" << endl;

	delete []name;
}

void AccountHandler::CreateHighCreditAccount()
{
	int accountID;
	char* name = new char[30];
	int money;
	int interest;
	int credit;

	cout << "[CREATE HIGH CREDIT ACCOUNT]" << endl;
	cout << "Account ID: "; cin >> accountID;
	cout << "Name: "; cin >> name;
	cout << "Deposit: "; cin >> money;
	cout << "Interest rate: "; cin >> interest;
	cout << "Credit(1=A, 2=B, 3=C): "; cin >> credit;
	accountList[count++] = new HighCreditAccount(accountID, name, money, interest, credit);
	cout << "Create new account success!" << endl;

	delete []name;
}

void AccountHandler::DepositMoney()
{
	int accountID;
	int money;

	cout << "[DEPOSIT]" << endl;
	cout << "Account ID: "; cin >> accountID;
	cout << "Money to deposit: "; cin >> money;
	for (int i = 0; i < count; i++)
	{
		if (accountList[i]->AccountIDCheck(accountID))
		{
			accountList[i]->Deposit(money);
			cout << money << " dollars has been deposited." << endl;
			return;
		}
	}

	cout << "There is no matching account with the ID " << accountID << endl;
}

void AccountHandler::WithdrawMoney();
{
	int accountID;
	int money;

	cout << "[WITHDRAW]" << endl;
	cout << "Account ID: "; cin >> accountID;
	cout << "Money to withdraw: "; cin >> money;
	for (int i = 0; i < count; i++)
	{
		if (accountList[i]->AccountIDCheck(accountID))
		{
			if (accountList[i]->Withdraw(money))
				cout << money << " dollar has been withdrawan." << endl;
			else
				cout << "Not enough money in the balance..." << endl;
			return;
		}
	}

	cout << "There is no matching account with the ID " << accountID << endl;
}

void AccountHandler::ShowAllAccountInfo()
{
	cout << "[INFORMATION]" << endl;
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
