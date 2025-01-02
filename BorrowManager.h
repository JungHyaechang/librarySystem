#ifndef BORROW_MANAGER
#define BORROW_MANAGER
#include <map>
#include "Book.h"
#include "BookManager.h"
#include <unordered_map>
#include <vector>
#include <iostream>

class Borrow_Manager {
	
private:

	std::unordered_map<std::string, int> stock; // 책 쌓인 수 

public:
	// 책 재고 초기화
	void initializeStock(Book book) {
		stock[book.gettitle()] = 3;
	}
	
	void displayStock(const std::string& title) {
		std::cout << char(34) << title << char(34) << " 의 재고 수량 : " << stock[title] << std::endl;
	}

	void borrowBook(const std::string& title) {
		if (stock[title] > 0) {
			stock[title]--;
		}
		else {
			std::cout << "책의 재고가 없습니다." << std::endl;
		}		
	}

	void returnBook(const std::string& title) {
		if (stock[title] < 3) {
			stock[title]++;
		}
		else {
			std::cout << "잘못된 경로의 반납입니다." << std::endl;
		}
	}
};

#endif