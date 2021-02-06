#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(int newID, char * newName, int money)
	:accountID(newID), balance(money)
{
	name = new char[30];
	strcpy(name, newName);
}

Account::Account(const Account& ref)
	:accountID(ref.accountID), balance(ref.balance)
{
	name = new char[30];
	strcpy(name, ref.name);
}

virtual void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (money > balance) 
		return 0;

	balance -= money;
	return money;
}

int Account::GetBalance()
{
	return balance;
}

void Account::ShowInfo() const
{
	cout << "Account ID: " << accountID << endl;
	cout << "Name: " << name << endl;
	cout << "Balance: " << balance << endl;
}

bool Account::AccountIDCheck(int accountID) const
{
	return (this->accountID == accountID);
}

Account::~Account()
{
	delete []name;
}
