// Book.cpp

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <iomanip>
using std::boolalpha;

#include "Book.h"

	Book::Book()
		:isbn_{"0-0-0-x"}, 
		title_{"?"},
		author_{"?"},
		copyright_date_{Date{}},
		genre_{Genre::unknown},
		checked_out_{false}
	{}

	// when you create a book, it cannot be already checked_out... 
	// this is the reason I'm not using checked_out as argument	 
	Book::Book(string isbn, string title, string author, Date copyright_date, Genre genre)
		:isbn_{isbn}, 
		title_{title}, 
		author_{author}, 
		copyright_date_{copyright_date}, 
		genre_{genre}, 
		checked_out_{false}
		{
			if (!isbn_valid()) 
			{
				cerr << "Book:Book(): isbn is invalid\n";
				exit(EXIT_FAILURE);
			}
		}


    void Book::check_out()
    {
        if (checked_out_) 
		{
			cerr << "Book::check_out(): tried to check out a book already checked out\n";
			exit(EXIT_FAILURE);
		}

        checked_out_ = true;
    }

    void Book::check_in()
    {
        if (!checked_out_)
		{
			cerr << "Book::check_in(): tried to check in a book already checked it\n";
			exit(EXIT_FAILURE);
		}

        checked_out_ = false;
    }

	// this is a little C++ advanced....   
	bool Book::is_number(const std::string &s) const
	{
  		return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
	}

	bool Book::isbn_valid() const
	{
		// tokenize the isbn
		vector<string> tokens;
		
		size_t pos{0};
		size_t next = isbn_.find("-", pos);
		while (next!= isbn_.npos) {
			tokens.push_back(isbn_.substr(pos,(next-pos)));
			pos = next+1;
			next = isbn_.find("-", pos);
		}
		tokens.push_back(isbn_.substr(pos));

		if  (tokens.size() != 4) 
			return false;
		if 	(tokens.at(3).size() != 1)
			return false;
	
		return (is_number(tokens.at(0)) && is_number(tokens.at(1)) && is_number(tokens.at(2)) && isalnum(tokens.at(3)[0]));
	}


	bool operator==(const Book& b1, const Book& b2)
	{
		return b1.isbn() == b2.isbn();
	}

	bool operator!=(const Book& b1, const Book& b2)
	{
		return !(b1 == b2);
	}


std::string Book::genre_to_string(Book::Genre genre) const
{
	switch (genre)
	{
	case Genre::fiction:
		return "fiction";
	case Genre::nonfiction:
		return "nonfiction";
	case Genre::periodical:
		return "periodical";
	case Genre::biography:
		return "biography";
	case Genre::children:
		return "children";
	case Genre::unknown:
		return "unknown";
	default:
		cerr << "Book::genre_to_string(): input is not a Genre\n";
		exit(EXIT_FAILURE); 
	} 
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
	os << "Title: " << b.title() << endl
		<< "Author: " << b.author() << endl
		<< "ISBN: " << b.isbn() << endl
		<< "Genre: " << b.genre_as_string() << endl
		<< "Copyright date: " << b.copyright() << endl
		<< "Checked out: " << boolalpha << b.checked_out();
	return os;
}