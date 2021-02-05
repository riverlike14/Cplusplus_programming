#include "NormalAccount.h"

NormalAccount::NormalAccount(int accountID, char* name, int money, double interest)
	: Account(accountID, name, money), interest(interest)
{ }

void NormalAccount::Deposit(int money)
{

	Account::Deposit(money * (1 + interest));
}
