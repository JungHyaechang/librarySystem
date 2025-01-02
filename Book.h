#ifndef BOOK
#define BOOK
#include <string>

class Book {
private:
	std::string title;
	std::string author;
public:
	Book(std::string booktitle, std::string authorname) : title(booktitle), author(authorname) {}
	~Book() {}
	 
	std::string gettitle() const {
		return title;
	}

	std::string getauthor() const {
		return author;
	}
};

#endif 

