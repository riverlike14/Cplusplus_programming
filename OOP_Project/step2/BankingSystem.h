#ifndef __BANKING_SYSTEM_H__
#define __BANKING_SYSTEM_H__

void ShowMenu();
void CreateAccount(int accountID, char * name, int money);
void DepositMoney(int accountID, int money);
void WithdrawMoney(int accountID, int money);
void ShowAllAccountInfo();

#endif
