// Book.cpp
#include "Book.h"
#include "Date.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

//costruttore della struttura Book
Book::Book(string ii, string tt, string aa, Genre gengen, Date cc, bool cciioo)
  :i{ii}, t{tt}, a{aa}, gen{gengen}, c{cc}, cio{cciioo} //vado ad accedere ai dati privati della Classe Book
{
  //controllo _n-n-n-x_ per gli ISBNs
  if (i[1]!='-' || i[3]!='-' || i[5]!='-') {
    cerr << "invalid ISBN" << endl;
    exit(1);
  }
  if(isalpha(i[0]) || isalpha(i[2]) || isalpha(i[4])) {
    cerr << "invalid ISBN" << endl;
    exit(1);
  }

  //controllo se il genere fa pare di uno di quelli considerati
  if(gen<Book::fiction || gen>Book::children) {
    cerr << "invalid genre for book selected";
    exit(1);
  }
}

// Costruttore di default
const Book& default_book()
{
	static Book bb{"1-2-3-x","Titolo","Autore",Book::fiction,Date{2000,Date::jun,1},0};   // libro di default
	return bb;
}

// funzione per il Costruttore di default
Book::Book()
	:i{default_book().isbn()},
	t{default_book().title()},
	a{default_book().author()},
  gen{default_book().genre()},
  c{default_book().copyright()},
  cio{default_book().checkInOut()}
{
}

// return isbn
string Book::isbn() const
{
	return i;
}

// return title
string Book::title() const
{
	return t;
}

// return author
string Book::author() const
{
	return a;
}

// return month
Book::Genre Book::genre() const
{
	return gen;
}

// return copyright DAY
Date Book::copyright() const
{
  return c;
}

// return booleano check io o out
bool Book::checkInOut () const
{
  return cio;
}

// operators
ostream& operator<<(ostream& os, Book& b) {
  return os << '(' << b.isbn()
    << ',' << b.title()
    << ',' << b.author()
    << ',' << b.genre()
    << ',' << b.copyright()
    << ',' << b.checkInOut() << ')';
}
