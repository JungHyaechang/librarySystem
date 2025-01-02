#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

// 구분 선
void printline() {
	for (int i = 0; i < 29; i++) {
		std::cout << "=";
	}
	std::cout << std::endl;
}


int main() {
	
	Book_Manager book_manager;
	Borrow_Manager borrow_manager;
	
	// 책 생성
	Book book1("Do it! C++ 완전 정복", "문종채");
	Book book2("Effective C++ third Edition", "Scott Meyers");
	Book book3("A tour of C++", "Bjarne Stroupstrup");

	// 책 목록에 책 추가
	book_manager.AddBook(book1);
	book_manager.AddBook(book2);
	book_manager.AddBook(book3);

	// 책 목록
	book_manager.DispalyAllBooks();

	
	// 책 있는지 확인
	book_manager.GetBookbyTitle("C++ 박살내보자");
	book_manager.GetBookbyAuthor("정혜창");
	book_manager.GetBookbyAuthor("문종채");
	book_manager.GetBookbyTitle("Effective C++ third Edition");
	printline();

	// 책 재고 초기화
	borrow_manager.initializeStock(book1);
	borrow_manager.initializeStock(book2);
	borrow_manager.initializeStock(book3);

	// 책 재고 현황
	borrow_manager.displayStock("Do it! C++ 완전 정복");
	borrow_manager.displayStock("Effective C++ third Edition");
	borrow_manager.displayStock("A tour of C++");

	printline(); 
	// 책 대여
	borrow_manager.borrowBook("Do it! C++ 완전 정복"); // stock : 2권
	borrow_manager.displayStock("Do it! C++ 완전 정복");
	borrow_manager.borrowBook("Do it! C++ 완전 정복"); // stock : 1권
	borrow_manager.displayStock("Do it! C++ 완전 정복");
	borrow_manager.borrowBook("Do it! C++ 완전 정복"); // stock : 0권
	borrow_manager.displayStock("Do it! C++ 완전 정복");
	borrow_manager.borrowBook("Do it! C++ 완전 정복"); // 대여 불가

	printline();
	// 책 반납
	borrow_manager.returnBook("Do it! C++ 완전 정복"); 
	borrow_manager.displayStock("Do it! C++ 완전 정복"); // stock : 1권
	borrow_manager.returnBook("Do it! C++ 완전 정복");
	borrow_manager.displayStock("Do it! C++ 완전 정복"); // stock : 2권

	return 0;
}




