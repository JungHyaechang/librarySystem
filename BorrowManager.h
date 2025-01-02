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

	std::unordered_map<std::string, int> stock; // å ���� �� 

public:
	// å ��� �ʱ�ȭ
	void initializeStock(Book book) {
		stock[book.gettitle()] = 3;
	}
	
	void displayStock(const std::string& title) {
		std::cout << char(34) << title << char(34) << " �� ��� ���� : " << stock[title] << std::endl;
	}

	void borrowBook(const std::string& title) {
		if (stock[title] > 0) {
			stock[title]--;
		}
		else {
			std::cout << "å�� ��� �����ϴ�." << std::endl;
		}		
	}

	void returnBook(const std::string& title) {
		if (stock[title] < 3) {
			stock[title]++;
		}
		else {
			std::cout << "�߸��� ����� �ݳ��Դϴ�." << std::endl;
		}
	}
};

#endif