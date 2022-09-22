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
		return "미대출";
	}
	else {
		return "대출중";
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
	Node* head; // Node를 가리키는 포인터, head
};


class LibraryManager {
	HeadNode* H;
public:
	// 아이디 생성

	// 타이틀 출력
	void showTitle() {
		cout << "Digitrack 도서관리 프로그램\n";
	}

	// 메뉴출력
	void showMenu() {
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
	void showAdminMenu() {
		cout << "=====================\n";
		cout << "1. 책삽입\n";
		cout << "2. 책삭제\n";
		cout << "3. 책위치변경\n";
		cout << "4. 메인으로\n";
		cout << "=====================\n";
	}

	// 메뉴입력
	int inputMenu() {
		int menuNum = -1;
		cout << "메뉴입력:";
		cin >> menuNum;
		return menuNum;
	}

	// 책 찾기
	void searchBook(HeadNode* H) {
		Node* someNode;
		try {
			if (H->head == NULL) throw H->head;
			someNode = H->head;

		}
		catch (HeadNode*)
		{
			cout << "아직 head가 없습니다.";
		}
		someNode = H->head;
		char bookName[50];
		cout << "찾으시는 책을 적어주세요 : ";
		cin >> bookName;

		while (someNode->name != bookName)
		{
			someNode = someNode->next;
		}
		cout << bookName << "이 책은 몇 번째 존재하며 누가 빌려갔습니다." << endl;
	}

	// 책 목록
	void listBook(HeadNode* L) {

		cout << "아이디" << "\t\t" << "제목" << "\t\t" << "장르" << "\t\t" << "저자" << "\t\t" << "대출여부" << "\t\t" << "책 위치" << "\n";
		cout << "====================================================\n";

		Node* p;
		cout << "연결리스트 목록 = ( ";
		p = L->head;

		while (p != NULL)
		{
			cout << p->name;
			p = p->next;
			if (p != NULL) cout << " --> ";
		}
		cout << " )" << endl;
		
	}

	// 책 대여
	void rentalBook() {
		
	}

	// 책 반납
	void returnBook() {
		
	}

	// 책 위치 변경
	void changeBook() {


	}

	// 책 삽입
	void addBook(HeadNode* H) {
		
		Node* NewNode = new Node;
		
		Node* LastNode;
		cout << "========= 책 추가 =========\n";
		cout << "제목 :";
		cin >> NewNode->name;
		cout << "장르 :";
		cin >> NewNode->genre;
		cout << "저자 :";
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

	// 파일 저장


	// 책 삭제
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

	// 관리자 모드
	void changeAdminMode() {
		int password = 0;
		cout << "관리자 암호를 입력 :";
		cin >> password;

		if (password != ADMIN_PSSWORD) {
			cout << "패스워드가 일치하지 않습니다.\n";
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

	// 종료
	void _exit() {
		exit(0);
	}

	// 초기화
	void initialize() {


		// 타이틀 출력
		showTitle();
		// 메뉴출력
		while (true) {
			showMenu();
			// 사용자로 부터 메뉴 번호 입력받음.
			int menuNum = inputMenu();

			// 메뉴에 따른 메소드 실행
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
