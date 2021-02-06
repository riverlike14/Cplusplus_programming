#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount 
{
private:
	int credit;

public:
	HighCreditAccount(int accountID, char* name, int money, int interest, int credit)
		: NormalAccount(accountID, name, money, interest), credit(credit)
	{ }

	virtual void Deposit(int money)
	{
		
	}

}

#endif
