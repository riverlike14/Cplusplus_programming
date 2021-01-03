#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(int newID, char * newName, int money)
	:accountID(newID), balance(money)
{
	name = new char[NAME_LEN];
	strcpy(name, newName);
}

void Account::Deposit(int money)
{
	balance += money;
	cout << money << " dollars has been deposited." << endl;
}

bool Account::Withdraw(int money)
{
	if (money > balance) {
		cout << "Not enough money in the balance..." << endl;
		return false;
	}

	balance -= money;
	cout << money << " dollar has been withdrawan." << endl;
	cout << balance << " dollar remains." << endl;

	return true;
}

void Account::ShowInfo() const
{
	cout << "Account ID: " << accountID << endl;
	cout << "Name: " << name << endl;
	cout << "Balance: " << balance << endl;
}

bool Account::AccountIDCheck(int accountID)
{
	return (this->accountID == accountID);
}
