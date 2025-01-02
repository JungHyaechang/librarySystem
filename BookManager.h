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
	// å�� ��ü�� �߰�
	void AddBook(const Book& newbook) {
		books.push_back(newbook);
	}
	// å
	void DispalyAllBooks() {
		std::cout << "NBC �������� å ���" << std::endl << "=============================" << std::endl;
		for (int i = 0; i < books.size(); i++) {
			std::cout << "å ���� : " << books[i].gettitle() << std::endl << "���� : " << books[i].getauthor() << std::endl
				<< "-----------------------------" << std::endl;
		}
	}

	Book* GetBookbyTitle(const std::string& title) {
		Book* book = FindBookbyTitle(title);
		if (book == nullptr) {
			std::cout << "ã���� å�� " << char(34) << title << char(34) << " �� �����ϰ� ���� �ʽ��ϴ�. " << std::endl;
		}
		else {
			std::cout << "ã���� å�� ���� �����ϰ� �ֽ��ϴ�. " << std::endl;
			return book;
		}
	}

	Book* GetBookbyAuthor(const std::string& author) {
		Book* book = FindBookbyAuthor(author);
		if (book == nullptr) {
			std::cout << char(34) << author << char(34) << " ������ å�� �����ϰ� ���� �ʽ��ϴ�. " << std::endl;
		}
		else {
			std::cout << "ã���� å�� ���� �����ϰ� �ֽ��ϴ�. " << std::endl;
			return book;
		}
	}
};

#endif