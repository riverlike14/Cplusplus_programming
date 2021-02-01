#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
	int count;
	Account* accountList[100];

public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount(int accountID, char* name, int money);
	void DepositMoney(int accountID, int money);
	void WithdrawMoney(int accountID, int money);
	void ShowAllAccountInfo();
	~AccountHandler();
};

#endif
