#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accountID;
	char* name;
	int balance;

public:
	Account(int newID, char* newName, int money);
	Account(const Account& ref);

	void Deposit(int money);
	bool Withdraw(int money);
	void ShowInfo() const;
	bool AccountIDCheck(int accountID) const;
	~Account();
};

#endif
