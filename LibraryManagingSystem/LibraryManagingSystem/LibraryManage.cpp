#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <iostream>

// 어드민 패스워드
#define ADMIN_PSSWORD 1111
using namespace std;

enum UserMenu { BOOK_SEARCH = 1, BOOK_LIST, BOOK_RENTAL, BOOK_RETURN, ADMIN_MODE, EXIT };
enum AdminMenu { BOOK_ADD = 1, BOOK_DELETE, BOOK_CHNAGE, GO_MAIN };

#include <iostream>
using namespace std;



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
	/*char* getName();
	char* getGenre();
	char* getAuthor();

	const char* getRental();
	void setRental(int rental);*/
};


class LibraryManager {
	Book* Node = new Book;
	
public:
	// 아이디 생성
	Account* Head;
	char* moveId;
	LibraryManager(Account* Head, char* moveId) : Head(Head), moveId(moveId) {}
	// 타이틀 출력
 	void ShowTitle() {
 		cout << "\n\n도서관리 프로그램 로그인 완료!!\n";
 	}

	// 메뉴출력
	void ShowMenu() {
		cout << "=====================\n";
		cout << "1. 도서검색\n";
		cout << "2. 도서목록\n";
		cout << "3. 도서대여\n";
		cout << "4. 도서반납\n";
		cout << "5. 관리자모드\n";
		cout << "6. 종료\n";
		cout << "=====================\n";
	}

	// 관리자 메뉴 출력
	void ShowAdminMenu() {
		cout << "=====================\n";
		cout << "1. 책삽입\n";
		cout << "2. 책삭제\n";
		cout << "3. 책위치변경\n";
		cout << "4. 메인으로\n";
		cout << "=====================\n";
	}

	// 메뉴입력
	int InputMenu() {
		int menuNum = -1;
		cout << "메뉴입력:";
		cin >> menuNum;
		return menuNum;
	}

	// 책 찾기
	Book* SearchBook(const int id, Book* head) {
		
		Book* tempNode;
		tempNode = head->next;
		while (tempNode != NULL)
		{
			if (tempNode->id== id)
			{
				return tempNode;
			}
			tempNode = tempNode->next;
		}
		return NULL;
	}

	// 책 목록
	void ListBook(Book* head) {
		
		Book* p;
		cout << "책 목록 = ( ";
		p = head->next;
		while (p != NULL)
		{
			cout << p->name;
			p = p->next;
			if (p != NULL) cout << " --> ";
			
		}
		cout << " )" << endl;

	}

	// 책 대여
	void RentalBook(Book* head) {

		Book* tempNode = new Book;;
		Account* userNode;
		AccountManager tempclass = AccountManager();
		int id = 0;
		
		
		//cout << moveId;
		userNode = tempclass.CheckUser(Head, moveId);
		if (!userNode->bookState)
		{
			cout << "대출 한도를 초과하였습니다.\n";
			return;
		}

		cout << "대여할 책 아이디를 입력: ";
		cin >> id;
		tempNode = SearchBook(id, Node);
		userNode->bookState = userNode->bookState - 1;
		
		if (tempNode->rental)
		{
			cout << "대출중입니다.\n";
			cout << "Id : ";
			cout << tempNode->borrower;
			cout << "빌리고 있는 중입니다.";
		}
		else
		{
			cout << "대출 가능 권수 : ";
			cout << userNode->bookState << endl;
			cout << "대여 완료\n";
			tempNode->rental = 1;
			strcpy_s(tempNode->borrower, strlen(moveId) + 1, moveId);
			

		}				
	
	}


	// 책 반납
	void ReturnBook(Book* head) {
		Book* tempNode = new Book;
		Account* userNode;
		int id = 0;
		bool isSuccess = false;
		AccountManager tempclass = AccountManager();
		cout << "반납 책 아이디를 입력:";
		cin >> id;
		tempNode = SearchBook(id, head);
		userNode = tempclass.CheckUser(Head, moveId);
		if (tempNode->rental)
		{
			cout << "반납 완료\n";
			tempNode->rental = 0;
			userNode->bookState = userNode->bookState + 1;
			strcpy_s(tempNode->borrower, 0, "");
			cout << tempNode->borrower;
		}
		else
			cout <<"일단 생각\n";
	}

	// 책 위치 변경
	void ChangeBook() {
/*
		int id1, id2 = 0;
		Book* bookPtr1 = NULL;
		Book* bookPtr2 = NULL;*/
	}

	// 책 삽입
	void AddBook(Book* H, char bookName[], char bookGenre[], char author[], int bookId) {

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
	// 파일 저장
	// 책 삭제
	void DeleteBook(Book* Head) {
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
	// 관리자 모드
	void ChangeAdminMode() {
		int password = 0;
		cout << "관리자 암호를 입력 :";
		cin >> password;

		if (password != ADMIN_PSSWORD) {
			cout << "패스워드가 일치하지 않습니다.\n";
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
				cout << "추가할 책 아이디: ";
				cin >> id;
				cout << "추가할 책 이름 : " ;
				cin >> bookName;
				cout << "추가할 책 장르 : " ;
				cin >> bookGenre;
				cout << "추가할 책 저자 : " ;
				cin >> author;

				AddBook(Node, bookName, bookGenre, author,id);
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
	// 종료
	void _exit() {
		exit(0);
	}

	// 초기화
	void initialize() {


		// 타이틀 출력
		ShowTitle();
		// 메뉴출력
		while (true) {
			ShowMenu();
			// 사용자로 부터 메뉴 번호 입력받음.
			int menuNum = InputMenu();

			// 메뉴에 따른 메소드 실행
			switch (menuNum)
			{
			case BOOK_SEARCH:
				int bookId;
				cout << "검색할 책 아이디 : ";
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

	LibraryManager() {}
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