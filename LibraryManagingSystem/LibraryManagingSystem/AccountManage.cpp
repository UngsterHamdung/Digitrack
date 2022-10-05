#include "AccountManage.h"
#include <iostream>

using namespace std;

void AccountManager::ShowACTitle()
{
	cout << "Digitrack �������� ���α׷�\n";
}

char AccountManager::CheckUserState(Account* temp)
{
	switch (temp->userState)
	{
	case 1:

		return (char)*"�л�";

	case 2:
		return (char)*"����";
	case 3:
		return (char)*"������";
	}

}



void AccountManager::ShowACMenu() {
	cout << "=====================\n";
	cout << "1. �α���\n";
	cout << "2. ȸ������\n";
	cout << "3. ȸ������Ʈ\n";
	//cout << "4. ��й�ȣ ã��\n";
	cout << "=====================\n";
}

void AccountManager::ListAccount(Account* head)
{
	Account* tempNode;
	cout << "���� ���̵� ��� = ( ";
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
			cout << "ID ����\n";
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
	cout << "���̵� �Է��ϼ��� : ";
	cin >> tempId;
	checkerNode = CheckUser(Head, tempId);
	strcpy_s(moveId, strlen(tempId) + 1, tempId);
	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> tempPassWord;

}
int AccountManager::InputMenu() {
	int menuNum = -1;
	cout << "�޴��Է�:";
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
	cout << "���̵� �Է��ϼ��� : ";
	cin >> tempId;
	idcheckerNode = CheckUser(Head, tempId);

	while (!idflag)
	{
		cout << "���̵� �ߺ��� Ȯ�� ���Դϴ�\n";
		// search
		if (idcheckerNode == NULL)
		{
			cout << "Id ��밡��!" << endl;
			break;
		}
		if (strcmp(idcheckerNode->userId, tempId) == 0)
		{
			cout << "Id �ߺ�\n";
			cout << "�ٽ� ���̵� �Է��ϼ��� : ";
			cin >> tempId;
		}
		else
		{
			idflag == 1;
			cout << "Id ��밡��!" << endl;
		}
	}
	strcpy_s(tempNode->userId, strlen(tempId) + 1, tempId);
	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> tempPassWord;
	while (!pwflag)
	{
		cout << "��й�ȣ�� �� �Է��ϼ��� : ";
		cin >> checkPassWord;
		if (!strcmp(checkPassWord, tempPassWord))
		{
			cout << "��й�ȣ ��ġ\n";
			pwflag = 1;
		}

	}
	strcpy_s(tempNode->passWord, strlen(tempPassWord) + 1, tempPassWord);
	cout << "=====================\n";
	cout << "������ ������\n";
	cout << "1. �л�\n";
	cout << "2. ������\n";
	cout << "3. ����\n";
	cout << "=====================\n";
	int menuNum = InputMenu();
	switch (menuNum)
	{
	case student:
		tempNode->userState = 1;
		tempNode->bookState = 1;
		cout << "�л� ����\n";
		break;
	case manager:
		tempNode->userState = 2;
		tempNode->bookState = 2;
		cout << "������ ����\n";
		break;
	case professor:
		tempNode->userState = 3;
		tempNode->bookState = 3;
		cout << "���� ����\n";
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
