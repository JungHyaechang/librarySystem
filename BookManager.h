#ifndef BOOK_MANAGER
#define BOOK_MANAGER
#include <string>
#include <vector>
#include "Book.h"
#include <iostream>

class Book_Manager {
private:
	std::vector<Book> books;

protected:
	Book* FindBookbyTitle(const std::string& title) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].gettitle() == title) {
				return &books[i];
			}
		}
		return nullptr;
	}
	Book* FindBookbyAuthor(const std::string& author) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getauthor() == author) {
				return &books[i];
			}
		}
		return nullptr;
	}

public:
	// 책을 객체에 추가
	void AddBook(const Book& newbook) {
		books.push_back(newbook);
	}
	// 책
	void DispalyAllBooks() {
		std::cout << "NBC 도서관의 책 목록" << std::endl << "=============================" << std::endl;
		for (int i = 0; i < books.size(); i++) {
			std::cout << "책 제목 : " << books[i].gettitle() << std::endl << "저자 : " << books[i].getauthor() << std::endl
				<< "-----------------------------" << std::endl;
		}
	}

	Book* GetBookbyTitle(const std::string& title) {
		Book* book = FindBookbyTitle(title);
		if (book == nullptr) {
			std::cout << "찾으신 책인 " << char(34) << title << char(34) << " 은 소장하고 있지 않습니다. " << std::endl;
		}
		else {
			std::cout << "찾으신 책은 현재 소장하고 있습니다. " << std::endl;
			return book;
		}
	}

	Book* GetBookbyAuthor(const std::string& author) {
		Book* book = FindBookbyAuthor(author);
		if (book == nullptr) {
			std::cout << char(34) << author << char(34) << " 저자의 책은 소장하고 있지 않습니다. " << std::endl;
		}
		else {
			std::cout << "찾으신 책은 현재 소장하고 있습니다. " << std::endl;
			return book;
		}
	}
};

#endif