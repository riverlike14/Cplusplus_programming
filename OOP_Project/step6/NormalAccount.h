#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount: public Account
{
private:
	double interest;

public:
	NormalAccount(int accountID, char* name, int money, double interest);
	void Deposit(int money);
};

#endif
