#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

const int NAME_LEN = 30;

enum {
	CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

class Account
{
private:
	int accountID;
	char * name;
	int balance;

public:
	Account(int newID, char * newName, int money);
	void Deposit(int money);
	bool Withdraw(int money);
	void ShowInfo() const;
	bool AccountIDCheck(int accountID);
};

#endif
