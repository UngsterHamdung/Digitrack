#include <iostream>
#include "AccountManage.h"

// 어드민 패스워드
#define ADMIN_PSSWORD 1111

enum UserMenu { BOOK_SEARCH = 1, BOOK_LIST, BOOK_RENTAL, BOOK_RETURN, ADMIN_MODE, EXIT };
enum AdminMenu { BOOK_ADD = 1, BOOK_DELETE, BOOK_CHNAGE, GO_MAIN };


class Book {

public:
	char name[50];
	char genre[50];
	char author[50];
	char borrower[50];
	int id;
	int rental;
	Book* next;
	Book() {};
	~Book() {};
};


class LibraryManager {
	Book* Node = new Book;

public:
	// 아이디 생성
	Account* Head;
	char* moveId;
	LibraryManager(Account* Head, char* moveId) : Head(Head), moveId(moveId) {}
	// 타이틀 출력
	void ShowTitle();
	void ShowMenu(); 
	void ShowAdminMenu();
	int InputMenu();
	Book* SearchBook(const int id, Book* head);
	void ListBook(Book* head);
	void RentalBook(Book* head);
	void ReturnBook(Book* head);
	void ChangeBook();
	void AddBook(Book* H, char bookName[], char bookGenre[], char author[], int bookId);
	void DeleteBook(Book* Head);
	void ChangeAdminMode();
	void _exit();
	void initialize();
};

int main()
{
	Account* Head = new Account;
	char* moveId = new char[50];
	AccountManager account_manager = AccountManager(Head, moveId);
	account_manager.Initializer();
	LibraryManager manager = LibraryManager(Head, moveId);
	manager.initialize();

}