#pragma once
#include <iostream>
enum userState { student = 1, manager, professor };
enum AccountMenu { ACLogin = 1, ACMakeAccount, ACShow };

struct Account
{
	char userId[50];
	char passWord[50];
	int userState = 0;
	Account* next = NULL;
	int bookState = 0;
};

class AccountManager
{
public:
	Account* Head;
	char* moveId;
	AccountManager(Account* Head, char* moveId) : Head(Head), moveId(moveId) {}
	AccountManager() {}
	/*char* moveId = new char[50];*/
	//Account* Head = new Account;
	void ShowACTitle();
	void ShowACMenu();
	char CheckUserState(Account* temp);
	void ListAccount(Account* head);
	Account* CheckUser(Account* head, char tempUserId[]);
	void Login(Account* head);
	int InputMenu();
	void MakeAccount(Account* head);
	void Initializer();
};