#include "NormalAccount.h"

NormalAccount::NormalAccount(int accountID, char* name, int money, int interest)
	: Account(accountID, name, money), interest(interest)
{ }

NormalAccount::NormalAccount(const NormalAccount& ref)
	: NormalAccount(ref.accountID, ref.name, ref.balance, ref.interest)
{ }

virtual void NormalAccount::Deposit(int money)
{
	Account::Deposit((GetBalance() * interest) / 100 + money);
}
