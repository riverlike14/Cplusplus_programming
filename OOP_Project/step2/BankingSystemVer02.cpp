#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 30;

struct Account
{
	int accountID;
	char * name = new char[NAME_LEN];
	int balance = 0;

	void InitAccount(int newID, char * newName, int money);
	void Deposit(int money);
	bool Withdraw(int money);
	void ShowInfo() const;
};

enum {
	CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

void ShowMenu();
Account CreateAccount(int accountID, char * name, int money);
void DepositMoney(int accountID, int money);
void WithdrawMoney(int accountID, int money);
void ShowAllAccountInfo();

Account accountList[100];
int count = 0;


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


void Account::InitAccount(int newID, char * newName, int money)
{
	accountID = newID;
	strcpy(name, newName);
	balance += money;
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
	return true;
}

void Account::ShowInfo() const
{
	cout << "Account ID: " << accountID << endl;
	cout << "Name: " << name << endl;
	cout << "Balance: " << balance << endl;
}


void ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print every account information" << endl;
	cout << "5. End the program" << endl;
}

Account CreateAccount(int accountID, char * name, int money)
{
	Account newAccount;
	newAccount.InitAccount(accountID, name, money);

	accountList[count] = newAccount;
	count++;

	cout << "Create new account success!" << endl;

	return newAccount;
}

void DepositMoney(int accountID, int money)
{
	for (int i = 0; i < count; i++)
	{
		if (accountList[i].accountID == accountID)
		{
			accountList[i].Deposit(money);
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
		if (accountList[i].accountID == accountID)
		{
			if (accountList[i].Withdraw(money))
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
		accountList[i].ShowInfo();
		cout << endl;
	}
}
