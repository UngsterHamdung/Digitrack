#include <iostream>
#include "LibraryManage.h"

using namespace std;


void LibraryManager::ShowTitle()
{
	cout << "\n\n�������� ���α׷� �α��� �Ϸ�!!\n";
}
void LibraryManager::ShowMenu()
{
	cout << "=====================\n";
	cout << "1. �����˻�\n";
	cout << "2. �������\n";
	cout << "3. �����뿩\n";
	cout << "4. �����ݳ�\n";
	cout << "5. �����ڸ��\n";
	cout << "6. ����\n";
	cout << "=====================\n";
}

void LibraryManager::ShowAdminMenu()
{
		cout << "=====================\n";
		cout << "1. å����\n";
		cout << "2. å����\n";
		cout << "3. å��ġ����\n";
		cout << "4. ��������\n";
		cout << "=====================\n";
}
int LibraryManager::InputMenu()
{
	int menuNum = -1;
	cout << "�޴��Է�:";
	cin >> menuNum;
	return menuNum;
}
Book* LibraryManager::SearchBook(const int id, Book* head) 
{

	Book* tempNode;
	tempNode = head->next;
	while (tempNode != NULL)
	{
		if (tempNode->id == id)
		{
			return tempNode;
		}
		tempNode = tempNode->next;
	}
	return NULL;
}

void LibraryManager::ListBook(Book* head) 
{

	Book* p;
	cout << "å ��� = ( ";
	p = head->next;
	while (p != NULL)
	{
		cout << p->name;
		p = p->next;
		if (p != NULL) cout << " --> ";

	}
	cout << " )" << endl;
}

void LibraryManager::RentalBook(Book* head) {

	Book* tempNode = new Book;;
	Account* userNode;
	AccountManager tempclass = AccountManager();
	int id = 0;


	//cout << moveId;
	userNode = tempclass.CheckUser(Head, moveId);
	if (!userNode->bookState)
	{
		cout << "���� �ѵ��� �ʰ��Ͽ����ϴ�.\n";
		return;
	}

	cout << "�뿩�� å ���̵� �Է�: ";
	cin >> id;
	tempNode = SearchBook(id, Node);
	userNode->bookState = userNode->bookState - 1;

	if (tempNode->rental)
	{
		cout << "�������Դϴ�.\n";
		cout << "Id : ";
		cout << tempNode->borrower;
		cout << "������ �ִ� ���Դϴ�.";
	}
	else
	{
		cout << "���� ���� �Ǽ� : ";
		cout << userNode->bookState << endl;
		cout << "�뿩 �Ϸ�\n";
		tempNode->rental = 1;
		strcpy_s(tempNode->borrower, strlen(moveId) + 1, moveId);


	}

}

void LibraryManager::ReturnBook(Book* head) {
	Book* tempNode = new Book;
	Account* userNode;
	int id = 0;
	bool isSuccess = false;
	AccountManager tempclass = AccountManager();
	cout << "�ݳ� å ���̵� �Է�:";
	cin >> id;
	tempNode = SearchBook(id, head);
	userNode = tempclass.CheckUser(Head, moveId);
	if (tempNode->rental)
	{
		cout << "�ݳ� �Ϸ�\n";
		tempNode->rental = 0;
		userNode->bookState = userNode->bookState + 1;
		strcpy_s(tempNode->borrower, 0, "");
		cout << tempNode->borrower;
	}
	else
		cout << "�ϴ� ����\n";
}



void LibraryManager::ChangeBook()
{

}

void LibraryManager::AddBook(Book* H, char bookName[], char bookGenre[], char author[], int bookId) {

	Book* LastNode;
	Book* book = new Book();
	strcpy_s(book->name, strlen(bookName) + 1, bookName);
	strcpy_s(book->genre, strlen(bookGenre) + 1, bookGenre);
	strcpy_s(book->author, strlen(author) + 1, author);
	book->id = bookId;
	book->rental = 0;
	//Book *book = new Book(bookName, bookGenre, author);
	book->next = NULL;

	if (H->next == NULL)
	{
		H->next = book;
		return;
	}

	LastNode = H->next;
	while (LastNode->next != NULL) LastNode = LastNode->next;
	LastNode->next = book;


}
void LibraryManager::DeleteBook(Book* Head) {
	Book* prevNode;
	Book* delNode;

	if (Head->next == NULL) return;
	if (Head->next->next == NULL) {
		delete Head->next;
		Head->next = NULL;
		return;
	}
	else {
		prevNode = Head->next;
		delNode = Head->next->next;
		while (delNode->next != NULL) {
			prevNode = delNode;
			delNode = prevNode->next;
		}
		free(delNode);
		prevNode->next = NULL;
	}
}


void LibraryManager::ChangeAdminMode() {
	int password = 0;
	cout << "������ ��ȣ�� �Է� :";
	cin >> password;

	if (password != ADMIN_PSSWORD) {
		cout << "�н����尡 ��ġ���� �ʽ��ϴ�.\n";
		return;
	}

	while (true) {

		ShowAdminMenu();
		int menuNum = InputMenu();
		switch (menuNum) {
		case BOOK_ADD:
			char bookName[50];
			char bookGenre[50];
			char author[50];
			int id;
			cout << "�߰��� å ���̵�: ";
			cin >> id;
			cout << "�߰��� å �̸� : ";
			cin >> bookName;
			cout << "�߰��� å �帣 : ";
			cin >> bookGenre;
			cout << "�߰��� å ���� : ";
			cin >> author;

			AddBook(Node, bookName, bookGenre, author, id);
			break;
		case BOOK_DELETE:
			DeleteBook(Node);
			break;
		case BOOK_CHNAGE:
			ChangeBook();
			break;
		case GO_MAIN:
			return; break;
		default:
			break;
		}
	}
}

void LibraryManager::_exit()
{
	exit(0);
}

void LibraryManager::initialize()
{
	// Ÿ��Ʋ ���
	ShowTitle();
	// �޴����
	while (true) {
		ShowMenu();
		// ����ڷ� ���� �޴� ��ȣ �Է¹���.
		int menuNum = InputMenu();

		// �޴��� ���� �޼ҵ� ����
		switch (menuNum)
		{
		case BOOK_SEARCH:
			int bookId;
			cout << "�˻��� å ���̵� : ";
			cin >> bookId;
			SearchBook(bookId, Node);
			break;
		case BOOK_LIST:
			ListBook(Node);
			break;
		case BOOK_RENTAL:
			RentalBook(Node);
			break;
		case BOOK_RETURN:
			ReturnBook(Node);
			break;
		case ADMIN_MODE:
			ChangeAdminMode();
			break;
		case EXIT:
			_exit();
			break;
		default:
			break;
		}
	}
}
