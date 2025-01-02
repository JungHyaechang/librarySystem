#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

// ���� ��
void printline() {
	for (int i = 0; i < 29; i++) {
		std::cout << "=";
	}
	std::cout << std::endl;
}


int main() {
	
	Book_Manager book_manager;
	Borrow_Manager borrow_manager;
	
	// å ����
	Book book1("Do it! C++ ���� ����", "����ä");
	Book book2("Effective C++ third Edition", "Scott Meyers");
	Book book3("A tour of C++", "Bjarne Stroupstrup");

	// å ��Ͽ� å �߰�
	book_manager.AddBook(book1);
	book_manager.AddBook(book2);
	book_manager.AddBook(book3);

	// å ���
	book_manager.DispalyAllBooks();

	
	// å �ִ��� Ȯ��
	book_manager.GetBookbyTitle("C++ �ڻ쳻����");
	book_manager.GetBookbyAuthor("����â");
	book_manager.GetBookbyAuthor("����ä");
	book_manager.GetBookbyTitle("Effective C++ third Edition");
	printline();

	// å ��� �ʱ�ȭ
	borrow_manager.initializeStock(book1);
	borrow_manager.initializeStock(book2);
	borrow_manager.initializeStock(book3);

	// å ��� ��Ȳ
	borrow_manager.displayStock("Do it! C++ ���� ����");
	borrow_manager.displayStock("Effective C++ third Edition");
	borrow_manager.displayStock("A tour of C++");

	printline(); 
	// å �뿩
	borrow_manager.borrowBook("Do it! C++ ���� ����"); // stock : 2��
	borrow_manager.displayStock("Do it! C++ ���� ����");
	borrow_manager.borrowBook("Do it! C++ ���� ����"); // stock : 1��
	borrow_manager.displayStock("Do it! C++ ���� ����");
	borrow_manager.borrowBook("Do it! C++ ���� ����"); // stock : 0��
	borrow_manager.displayStock("Do it! C++ ���� ����");
	borrow_manager.borrowBook("Do it! C++ ���� ����"); // �뿩 �Ұ�

	printline();
	// å �ݳ�
	borrow_manager.returnBook("Do it! C++ ���� ����"); 
	borrow_manager.displayStock("Do it! C++ ���� ����"); // stock : 1��
	borrow_manager.returnBook("Do it! C++ ���� ����");
	borrow_manager.displayStock("Do it! C++ ���� ����"); // stock : 2��

	return 0;
}




