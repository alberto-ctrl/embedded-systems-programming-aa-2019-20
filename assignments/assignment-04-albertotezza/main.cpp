// main.cpp of Library

#include "Library.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*void print_librarys(const Library& my_library) {
	cout << "\nMy List of Book added:\n";
	for(vector<Book>::const_iterator pos=my_library.books().cbegin(); pos != my_library.books().cend(); ++pos)
	{
		cout << (*pos) << endl;
	}
    cout << endl;
}*/

int main() {

  Library mylibrary;

  Book book4("0-5678-91011-1", "Il signore degli aneelli", "Padron Frodo", Date{2000, Date::Month::jan, 1}, Book::Genre::fiction);

  Book book1{"0-321-99278-4", "Programming Principles and Practices Using C++ Second Edition", "Bjarne Stroustrup", Date{2014, Date::Month::jan, 1}};
  Book book2{"0-13-110370-9", "The C Programming Language Second Edition", "Brian W.Kernighan and Dennis M.Ritchie", Date{1988, Date::Month::jan, 1}};
	Book book3{"0-201-70073-5", "The C++ Programming Language", "Bjarne Stroustrup", Date{2000, Date::Month::jan, 1}};

	Patron patron1{"Charles Dickens", 210810, 10};
	Patron patron2{"Pappa \"Too Hard\" Bear", 210811, 0};
	Patron patron3{"Momma \"Too Soft\" Bear", 210812, 20};
	Patron patron4{"Baby \"Just Right\" Bear", 210813, 0};
	Patron patron5{"Goldie Locks", 210814, 10};

//  print_librarys(mylibrary);

  mylibrary.add_book(book1);
  mylibrary.add_book(book4);
  mylibrary.add_patron(patron3);


  mylibrary.check_out_book(book4, patron3, Date{2019, Date::Month::nov, 16});
  cout << endl;
  mylibrary.check_out_book(book4, patron3, Date{2019, Date::Month::nov, 16});



}
