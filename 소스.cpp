#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <iostream>

// ���� �н�����
#define ADMIN_PSSWORD 1111
using namespace std;

enum UserMenu { BOOK_SEARCH = 1, BOOK_LIST, BOOK_RENTAL, BOOK_RETURN, ADMIN_MODE, EXIT };
enum AdminMenu { BOOK_ADD = 1, BOOK_DELETE, BOOK_CHNAGE, GO_MAIN };


struct Node {
	char name[50];
	char genre[50];
	char author[50];
	int rental;
	Node* next;
};

class Book {
	Node* newBook;
public:
	Book(const char _name[], const char _genre[], const char _author[]) {

		newBook->rental = 0;
		strcpy_s(newBook->name, _name);
		strcpy_s(newBook->genre, _genre);
		strcpy_s(newBook->author, _author);
	}
	Book() {};
	~Book() {};
	char* getName();
	char* getGenre();
	char* getAuthor();

	const char* getRental();
	void setRental(int rental);
};


const char* Book::getRental() {
	if (newBook->rental == 0) {
		return "�̴���";
	}
	else {
		return "������";
	}
};

void Book::setRental(int _rental) {
	newBook->rental = _rental;
}

char* Book::getName() {
	return newBook->name;
};

char* Book::getGenre() {
	return newBook->genre;
};

char* Book::getAuthor() {
	return newBook->author;
};

struct HeadNode {
	Node* head; // Node�� ����Ű�� ������, head
};


class LibraryManager {
	HeadNode* H;
public:
	// ���̵� ����

	// Ÿ��Ʋ ���
	void showTitle() {
		cout << "Digitrack �������� ���α׷�\n";
	}

	// �޴����
	void showMenu() {
		cout << "=====================\n";
		cout << "1. �����˻�\n";
		cout << "2. �������\n";
		cout << "3. �����뿩\n";
		cout << "4. �����ݳ�\n";
		cout << "5. �����ڸ��\n";
		cout << "6. ����\n";
		cout << "=====================\n";
	}

	// ������ �޴� ���
	void showAdminMenu() {
		cout << "=====================\n";
		cout << "1. å����\n";
		cout << "2. å����\n";
		cout << "3. å��ġ����\n";
		cout << "4. ��������\n";
		cout << "=====================\n";
	}

	// �޴��Է�
	int inputMenu() {
		int menuNum = -1;
		cout << "�޴��Է�:";
		cin >> menuNum;
		return menuNum;
	}

	// å ã��
	void searchBook(HeadNode* H) {
		Node* someNode;
		try {
			if (H->head == NULL) throw H->head;
			someNode = H->head;

		}
		catch (HeadNode*)
		{
			cout << "���� head�� �����ϴ�.";
		}
		someNode = H->head;
		char bookName[50];
		cout << "ã���ô� å�� �����ּ��� : ";
		cin >> bookName;

		while (someNode->name != bookName)
		{
			someNode = someNode->next;
		}
		cout << bookName << "�� å�� �� ��° �����ϸ� ���� ���������ϴ�." << endl;
	}

	// å ���
	void listBook(HeadNode* L) {

		cout << "���̵�" << "\t\t" << "����" << "\t\t" << "�帣" << "\t\t" << "����" << "\t\t" << "���⿩��" << "\t\t" << "å ��ġ" << "\n";
		cout << "====================================================\n";

		Node* p;
		cout << "���Ḯ��Ʈ ��� = ( ";
		p = L->head;

		while (p != NULL)
		{
			cout << p->name;
			p = p->next;
			if (p != NULL) cout << " --> ";
		}
		cout << " )" << endl;
		
	}

	// å �뿩
	void rentalBook() {
		
	}

	// å �ݳ�
	void returnBook() {
		
	}

	// å ��ġ ����
	void changeBook() {


	}

	// å ����
	void addBook(HeadNode* H) {
		
		Node* NewNode = new Node;
		
		Node* LastNode;
		cout << "========= å �߰� =========\n";
		cout << "���� :";
		cin >> NewNode->name;
		cout << "�帣 :";
		cin >> NewNode->genre;
		cout << "���� :";
		cin >> NewNode->author;

		Book book = Book(NewNode->name, NewNode->genre, NewNode->author);
		NewNode->next = NULL;

		if (H->head == NULL)
		{
			H->head = NewNode;
			return;
		}

		LastNode = H->head;
		while (LastNode->next != NULL) LastNode = LastNode->next;
		LastNode->next = NewNode;
		

	}

	// ���� ����


	// å ����
	void deleteBook(HeadNode* H) {
		Node* prevNode;
		Node* delNode;

		if (H->head == NULL) return;
		if (H->head->next == NULL) {
			delete H->head;
			H->head = NULL;
			return;
		}
		else {
			prevNode = H->head;
			delNode = H->head->next;
			while (delNode->next != NULL) {
				prevNode = delNode;
				delNode = prevNode->next;
			}
			free(delNode);
			prevNode->next = NULL;
		}
	}

	// ������ ���
	void changeAdminMode() {
		int password = 0;
		cout << "������ ��ȣ�� �Է� :";
		cin >> password;

		if (password != ADMIN_PSSWORD) {
			cout << "�н����尡 ��ġ���� �ʽ��ϴ�.\n";
			return;
		}

		while (true) {

			showAdminMenu();
			int menuNum = inputMenu();
			switch (menuNum) {
			case BOOK_ADD:
				addBook(H);
				break;
			case BOOK_DELETE:
				deleteBook(H);
				break;
			case BOOK_CHNAGE:
				changeBook();
				break;
			case GO_MAIN:
				return; break;
			default:
				break;
			}
		}


	}

	// ����
	void _exit() {
		exit(0);
	}

	// �ʱ�ȭ
	void initialize() {


		// Ÿ��Ʋ ���
		showTitle();
		// �޴����
		while (true) {
			showMenu();
			// ����ڷ� ���� �޴� ��ȣ �Է¹���.
			int menuNum = inputMenu();

			// �޴��� ���� �޼ҵ� ����
			switch (menuNum)
			{
			case BOOK_SEARCH:
				searchBook(H);
				break;
			case BOOK_LIST:
				listBook(H);
				break;
			case BOOK_RENTAL:
				rentalBook();
				break;
			case BOOK_RETURN:
				returnBook();
				break;
			case ADMIN_MODE:
				changeAdminMode();
				break;
			case EXIT:
				_exit();
				break;
			default:
				break;
			}
		}
	}

	LibraryManager() {}
};

int main()
{
	LibraryManager manager = LibraryManager();
	manager.initialize();
}