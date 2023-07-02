#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

#include "Book.h"

void print_books(const vector<Book>& my_books) {
	cout << "\nMy books are:\n";
	for(vector<Book>::const_iterator pos=my_books.cbegin(); pos != my_books.cend(); ++pos)
	{
		cout << (*pos) << endl;
	}
    cout << endl;
}

int main() {

	// create few books
	Book default_b;
	cout << default_b << endl;

    Book book1{"9780-4390-2348-1",
        "Hunger Games, The",
        "Collins, Suzanne",
        Date{2008, 12, 1},					// provo il mese con il numero
        Book::Genre::fiction};

    Book book2{"9780-4393-5807-1",
        "Harry Potter and the Order of the Phoenix",
        "Rowling, J.K.",
        Date{2003, Date::Month::jan, 1},
        Book::Genre::children};

    Book book3{"9781-4165-3932-2",
        "Einstein: His Life and Universe",
        "Isaacson, Walter",
        Date{2007, Date::Month::jan, 1},
        Book::Genre::biography};

    Book book4{"9780-3160-6760-7",
        "Lone Survivor",
        "Luttrell, Marcus",
        Date{2008, Date::Month::jan, 1},
        Book::Genre::nonfiction};

    Book book5{"1234-5678-1234-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

	// Books not working (only check is on isbn)

/*
	Book book6{"",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

	Book book7{"12d-5678-1234-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

    Book book8{"1234-56d-1234-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

    Book book9{"1234-5678-12a4-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

    Book book10{"1234-5678-1234-xsd",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

    Book book11{"1234-5678-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};

    Book book12{"1234-5678-1234-1234-x",
        "Triathlete Issue 2/14",
        "Competitor Group",
        Date{2014, Date::Month::jan, 1},
        Book::Genre::periodical};
*/

	// create a vector of book
	vector<Book> my_books;
	my_books.push_back(book1);
	my_books.push_back(book2);
	my_books.push_back(book3);
	my_books.push_back(book4);
	my_books.push_back(book5);

	print_books(my_books);

    Book book_test{"9780-4390-2348-1",
        "Hunger Games, The",
        "Collins, Suzanne",
        Date{2008, Date::Month::jan, 1},
        Book::Genre::fiction};

    if (book_test == book1)
        cout << book_test.isbn() << "==" << book1.isbn() << endl;

    if (book_test != book2) {
        cout << book_test.isbn() << "!=" << book2.isbn() << endl;
    }

	my_books.at(0).check_out();
	print_books(my_books);

	my_books.at(0).check_in();
	print_books(my_books);

	my_books.at(0).check_in();

}
