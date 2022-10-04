#include <iostream>
using namespace std;

enum userState {student = 1, professor, manager};
enum AccountMenu {ACLogin=1, ACMakeAccount, ACFindId, ACFindPW};

struct Account
{
	char userId[50];
	char passWord[50];
	int userState = 0;
	Account* next;
};

class AccountManager
{
public:

	Account* Head = new Account;

	void ShowACTitle() {
		cout << "Digitrack �������� ���α׷�\n";
	}
	void ShowACMenu() {
		cout << "=====================\n";
		cout << "1. �α���\n";
		cout << "2. ȸ������\n";
		cout << "3. ���̵� ã��\n";
		cout << "4. ��й�ȣ ã��\n";
		cout << "=====================\n";
	}
	char CheckUserState(Account* temp)
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

	Account* CheckUser(Account* temp, char tempUserId[])
	{
		Account* tempNode;
		tempNode = temp->next;
		while (tempNode != NULL)
		{
			if (!strcmp(tempNode->userId, tempUserId))
			{
				cout << "ID ����";
				return tempNode;
			}
			tempNode = tempNode->next;
		}
	}
	void Login(Account * head)
	{
		Account* tempNode;
		char tempId[50];
		char tempPassWord[50];
		Account* checkerNode;
		cout << "���̵� �Է��ϼ��� : ";
		cin >> tempId;
		checkerNode = CheckUser(Head, tempId);
		
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin >> tempPassWord;
	}
	int InputMenu() {
		int menuNum = -1;
		cout << "�޴��Է�:";
		cin >> menuNum;
		return menuNum;
	}

	void MakeAccount(Account * head)
	{
		Account* tempNode = new Account;
		Account* LastNode;
		char tempId[50];
		char tempPassWord[50];
		char checkPassWord[50];
		int idflag=0;
		int pwflag = 0;
		Account* idcheckerNode;
		cout << "���̵� �Է��ϼ��� : ";
		cin >> tempId;
		idcheckerNode = CheckUser(Head, tempId);
		while (!idflag)
		{
			cout << "���̵� �ߺ��� Ȯ�� ���Դϴ�";
			// search
			if (strcmp(idcheckerNode->userId, tempId) == 0)
				cout << "Id �ߺ�";
			else
			{
				idflag == 1;
			}
		}
		strcpy_s(tempNode->userId, strlen(tempId) + 1, tempId);
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin >> tempPassWord;
		while (!pwflag)
		{
			cout << "��й�ȣ�� �� �Է��ϼ��� : ";
			cin >> checkPassWord;
			if (strcmp(checkPassWord, tempPassWord))
			{
				cout << "��й�ȣ ��ġ";
				pwflag = 1;
			}

		}
		strcpy_s(tempNode->passWord, strlen(tempPassWord) + 1, tempPassWord);
		cout << "������ ������\n";
		cout << "1. �л�\n";
		cout << "2. ����\n";
		cout << "3. ������\n";
		int menuNum = InputMenu();
		switch (menuNum)
		{
		case student:
			tempNode->userState = 1;
		case professor:
			tempNode->userState = 2;
		case manager:
			tempNode->userState = 3;
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
	void Initializer()
	{
		ShowACTitle();
		while (true)
		{
			ShowACMenu();
			int menuNum = InputMenu();
			switch(menuNum)
			{
			case ACLogin:
				Login(Head);
				break;
			case ACMakeAccount:
				MakeAccount(Head);
				break;
			case ACFindId:
				break;
			case ACFindPW:
				break;
			}
		}
	}
}; 

int main()
{
	AccountManager manager = AccountManager();
	manager.Initializer();
	
}