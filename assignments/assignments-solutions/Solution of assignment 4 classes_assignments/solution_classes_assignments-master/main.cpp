// main.cpp

#include "Library.h"
#include "Book.h"
#include "Date.h"
#include "Patron.h"

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;


int main() {
	Library my_library;

	Book book1{"0-321-99278-4", "Programming Principles and Practices Using C++ Second Edition", "Bjarne Stroustrup", Date{2014, Date::Month::jan, 1}};
	Book book2{"0-13-110370-9", "The C Programming Language Second Edition", "Brian W.Kernighan and Dennis M.Ritchie", Date{1988, Date::Month::jan, 1}};
	Book book3{"0-201-70073-5", "The C++ Programming Language", "Bjarne Stroustrup", Date{2000, Date::Month::jan, 1}};

	Patron patron1{"Charles Dickens", 210810, 10};
	Patron patron2{"Pappa \"Too Hard\" Bear", 210811, 0};
	Patron patron3{"Momma \"Too Soft\" Bear", 210812, 20};
	Patron patron4{"Baby \"Just Right\" Bear", 210813, 0};
	Patron patron5{"Goldie Locks", 210814, 10};

	my_library.add_book(book1);
	my_library.add_book(book2);

	my_library.add_patron(patron1);
	my_library.add_patron(patron2);
	my_library.add_patron(patron3);
	my_library.add_patron(patron4);


	my_library.check_out_book(book1, patron4, Date{2019, Date::Month::jan, 1});
	my_library.check_out_book(book2, patron3, Date{2019,Date::Month::jan, 1});

	if(my_library.book_exists(book1));

//	my_library.check_out_book(book3, patron1, Date{2019,Date::Month::jan, 1});
//	my_library.check_out_book(book2, patron5, Date{2019,Date::Month::jan, 1});
//	my_library.check_out_book(book1, patron1, Date{2019,Date::Month::jan, 1});

	vector<string> patrons_owe_fees = my_library.get_patrons_with_fees();

	for(vector<string>::const_iterator pos=patrons_owe_fees.cbegin(); pos != patrons_owe_fees.cend(); ++pos)
		cout << (*pos) << endl;

}
