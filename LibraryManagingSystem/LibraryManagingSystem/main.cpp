#include <iostream>
#include "AccountManage.h"
#include "LibraryManage.h"

int main(void)
{
	Account* Head = new Account;
	char* moveId = new char[50];
	AccountManager account_manager = AccountManager(Head, moveId);
	account_manager.Initializer();
	LibraryManager manager = LibraryManager(Head, moveId);
	manager.initialize();
	return 0;
}