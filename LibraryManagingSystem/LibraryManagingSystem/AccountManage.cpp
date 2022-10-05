#include "AccountManage.h"
#include <iostream>

using namespace std;

void AccountManager::ShowACTitle()
{
	cout << "Digitrack 도서관리 프로그램\n";
}

char AccountManager::CheckUserState(Account* temp)
{
	switch (temp->userState)
	{
	case 1:

		return (char)*"학생";

	case 2:
		return (char)*"교수";
	case 3:
		return (char)*"교직원";
	}

}



void AccountManager::ShowACMenu() {
	cout << "=====================\n";
	cout << "1. 로그인\n";
	cout << "2. 회원가입\n";
	cout << "3. 회원리스트\n";
	//cout << "4. 비밀번호 찾기\n";
	cout << "=====================\n";
}

void AccountManager::ListAccount(Account* head)
{
	Account* tempNode;
	cout << "유저 아이디 목록 = ( ";
	tempNode = head->next;
	while (tempNode != NULL)
	{
		cout << tempNode->userId;
		tempNode = tempNode->next;
		if (tempNode != NULL) cout << " --> ";

	}
	cout << " )" << endl;
}

Account* AccountManager::CheckUser(Account* head, char tempUserId[])
{
	Account* tempNode;
	tempNode = head->next;
	if (tempNode == NULL)
		return NULL;
	while (tempNode != NULL)
	{
		if (!strcmp(tempNode->userId, tempUserId))
		{
			cout << "ID 있음\n";
			return tempNode;
		}
		tempNode = tempNode->next;
	}
	return NULL;
}

void AccountManager::Login(Account* head)
{
	Account* tempNode;
	char tempId[50];
	char tempPassWord[50];
	Account* checkerNode;
	cout << "아이디를 입력하세요 : ";
	cin >> tempId;
	checkerNode = CheckUser(Head, tempId);
	strcpy_s(moveId, strlen(tempId) + 1, tempId);
	cout << "비밀번호를 입력하세요 : ";
	cin >> tempPassWord;

}
int AccountManager::InputMenu() {
	int menuNum = -1;
	cout << "메뉴입력:";
	cin >> menuNum;
	return menuNum;
}

void AccountManager::MakeAccount(Account* head)
{
	Account* tempNode = new Account;
	Account* LastNode;

	char tempId[50];
	char tempPassWord[50];
	char checkPassWord[50];
	int idflag = 0;
	int pwflag = 0;
	Account* idcheckerNode;
	cout << "아이디를 입력하세요 : ";
	cin >> tempId;
	idcheckerNode = CheckUser(Head, tempId);

	while (!idflag)
	{
		cout << "아이디 중복을 확인 중입니다\n";
		// search
		if (idcheckerNode == NULL)
		{
			cout << "Id 사용가능!" << endl;
			break;
		}
		if (strcmp(idcheckerNode->userId, tempId) == 0)
		{
			cout << "Id 중복\n";
			cout << "다시 아이디를 입력하세요 : ";
			cin >> tempId;
		}
		else
		{
			idflag == 1;
			cout << "Id 사용가능!" << endl;
		}
	}
	strcpy_s(tempNode->userId, strlen(tempId) + 1, tempId);
	cout << "비밀번호를 입력하세요 : ";
	cin >> tempPassWord;
	while (!pwflag)
	{
		cout << "비밀번호를 재 입력하세요 : ";
		cin >> checkPassWord;
		if (!strcmp(checkPassWord, tempPassWord))
		{
			cout << "비밀번호 일치\n";
			pwflag = 1;
		}

	}
	strcpy_s(tempNode->passWord, strlen(tempPassWord) + 1, tempPassWord);
	cout << "=====================\n";
	cout << "직업을 고르세요\n";
	cout << "1. 학생\n";
	cout << "2. 교직원\n";
	cout << "3. 교수\n";
	cout << "=====================\n";
	int menuNum = InputMenu();
	switch (menuNum)
	{
	case student:
		tempNode->userState = 1;
		tempNode->bookState = 1;
		cout << "학생 선택\n";
		break;
	case manager:
		tempNode->userState = 2;
		tempNode->bookState = 2;
		cout << "교직원 선택\n";
		break;
	case professor:
		tempNode->userState = 3;
		tempNode->bookState = 3;
		cout << "교수 선택\n";
		break;
	default:
		break;
	}
	tempNode->next = NULL;

	if (head->next == NULL)
	{
		head->next = tempNode;
		return;
	}

	LastNode = head->next;
	while (LastNode->next != NULL) LastNode = LastNode->next;
	LastNode->next = tempNode;
}

void AccountManager::Initializer()
{
	ShowACTitle();
	bool changeMode = true;
	while (changeMode)
	{
		ShowACMenu();
		int menuNum = InputMenu();
		switch (menuNum)
		{
		case ACLogin:
			Login(Head);
			changeMode = false;
			//cout << moveId;
			break;
		case ACMakeAccount:
			MakeAccount(Head);
			break;
		case ACShow:
			ListAccount(Head);
			break;

		}
	}
}
