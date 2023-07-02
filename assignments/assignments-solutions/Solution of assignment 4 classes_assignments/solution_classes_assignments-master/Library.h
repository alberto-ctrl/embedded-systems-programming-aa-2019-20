// Library.h

#ifndef Library_h
#define Library_h

#include <vector>
#include <string>

#include "Book.h"
#include "Patron.h"
#include "Date.h"

class Library {
public:

	Library();

	void add_book(const Book& b);
	void add_patron(const Patron& p);
	void check_out_book(Book& b, const Patron& p, const Date& d);
    std::vector<std::string> get_patrons_with_fees();

private:

	// type for transaction, combining Book, Patron, and Date types
	struct Transaction {
		Book book_;
		Patron patron_;
		Date date_;
	};


	std::vector<Book> books_;
	std::vector<Patron> patrons_;
	std::vector<Transaction> transactions_;

// se sposto a public queste funzioni poi posso usarle nel main
	bool book_exists(const Book& b);
	bool patron_exists(const Patron& p);
};

#endif
