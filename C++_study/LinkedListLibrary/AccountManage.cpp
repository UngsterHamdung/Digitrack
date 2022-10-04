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
		cout << "Digitrack 도서관리 프로그램\n";
	}
	void ShowACMenu() {
		cout << "=====================\n";
		cout << "1. 로그인\n";
		cout << "2. 회원가입\n";
		cout << "3. 아이디 찾기\n";
		cout << "4. 비밀번호 찾기\n";
		cout << "=====================\n";
	}
	char CheckUserState(Account* temp)
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

	Account* CheckUser(Account* temp, char tempUserId[])
	{
		Account* tempNode;
		tempNode = temp->next;
		while (tempNode != NULL)
		{
			if (!strcmp(tempNode->userId, tempUserId))
			{
				cout << "ID 있음";
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
		cout << "아이디를 입력하세요 : ";
		cin >> tempId;
		checkerNode = CheckUser(Head, tempId);
		
		cout << "비밀번호를 입력하세요 : ";
		cin >> tempPassWord;
	}
	int InputMenu() {
		int menuNum = -1;
		cout << "메뉴입력:";
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
		cout << "아이디를 입력하세요 : ";
		cin >> tempId;
		idcheckerNode = CheckUser(Head, tempId);
		while (!idflag)
		{
			cout << "아이디 중복을 확인 중입니다";
			// search
			if (strcmp(idcheckerNode->userId, tempId) == 0)
				cout << "Id 중복";
			else
			{
				idflag == 1;
			}
		}
		strcpy_s(tempNode->userId, strlen(tempId) + 1, tempId);
		cout << "비밀번호를 입력하세요 : ";
		cin >> tempPassWord;
		while (!pwflag)
		{
			cout << "비밀번호를 재 입력하세요 : ";
			cin >> checkPassWord;
			if (strcmp(checkPassWord, tempPassWord))
			{
				cout << "비밀번호 일치";
				pwflag = 1;
			}

		}
		strcpy_s(tempNode->passWord, strlen(tempPassWord) + 1, tempPassWord);
		cout << "직업을 고르세요\n";
		cout << "1. 학생\n";
		cout << "2. 교수\n";
		cout << "3. 교직원\n";
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