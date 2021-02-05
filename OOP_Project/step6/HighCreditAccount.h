#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount: public NormalAccount 
{
private:
	int credit;

public:
	HighCreditAccount(int accountID, char* name, int money, double interest, int credit)
		: NormalAccount(accountID, name, money, interest)
	{ }

}

#endif
