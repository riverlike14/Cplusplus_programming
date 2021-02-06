#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount: public Account
{
private:
	int interest;

public:
	NormalAccount(int accountID, char* name, int money, int interest);
	NormalAccount(const NormalAccount& ref);

	virtual void Deposit(int money);
};

#endif
