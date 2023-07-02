// Library.cpp

#include <iostream>
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::find;
#include "Library.h"

Library::Library()
{
}

// C++ advanced style
/*
bool Library::book_exists(const Book& b)
{
	vector<Book>::const_iterator b_itr{std::find(books_.begin(), books_.end(), b)};
	return !(b_itr == books_.cend());
}
*/

// C++ easier style

bool Library::book_exists(const Book& b)
{
	for (int i=0; i<books_.size(); ++i)
		if (books_[i] == b)
			return true;
	return false;
}


// C++ advanced style
/*
bool Library::patron_exists(const Patron& p)
{
	vector<Patron>::const_iterator p_itr{std::find(patrons_.begin(), patrons_.end(), p)};
	return !(p_itr == patrons_.cend());
}
*/


// C++ easier style
bool Library::patron_exists(const Patron& p)
{
	for (int i=0; i<patrons_.size(); ++i)
		if (patrons_[i] == p)
			return true;
	return false;
}


void Library::add_book(const Book& b)
{
	// check if the book is already in the library
	if (book_exists(b)) {
		cerr << "Library::add_book(): book is already in the library\n";
		exit(EXIT_FAILURE);
	}
	books_.push_back(b);
}

void Library::add_patron(const Patron& p)
{
	// check if patron is already in library
	if (patron_exists(p)) {
		cerr << "Library::add_patron(): patrons is already in the library\n";
		exit(EXIT_FAILURE);
	}

	patrons_.push_back(p);
}


// make sure patron and book is part of library
// if either is not part of library report an error
// if no error create a transaction to place into transactions vector
void Library::check_out_book(Book& b, const Patron& p, const Date& d)
{
	if (!book_exists(b)) {
		cerr << "check_out_book(): book " << b.title() << " does not exit\n";
		exit(EXIT_FAILURE);
	}
	if (!patron_exists(p)) {
		cerr << "check_out_book(): patron " << p.name() << " does not exit\n";
		exit(EXIT_FAILURE);
	}

	if (b.checked_out()) {
		cerr << "check_out_book(): book " << b.title() << " already checked out\n";
		exit(EXIT_FAILURE);
	}

	b.check_out();
	transactions_.push_back(Transaction{b, p, d});
}


vector<string> Library::get_patrons_with_fees()
{
	vector<string> patrons_owe_fees;

	for(vector<Patron>::const_iterator itr = patrons_.begin(); itr < patrons_.end(); ++itr)
		if((*itr).owes_fees())
				patrons_owe_fees.push_back((*itr).name());

	return patrons_owe_fees;
}
