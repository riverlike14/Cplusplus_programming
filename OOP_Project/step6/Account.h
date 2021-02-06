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

	virtual int Deposit(int money);
	int Withdraw(int money);
	int GetBalance();
	void ShowInfo() const;
	bool AccountIDCheck(int accountID) const;
	~Account();
};

#endif
