// Book.h

#ifndef BOOK_H
#define BOOK_H
#include "Date.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class Book {
public:
  enum Genre {
    fiction=1, nonfiction, periodical, biography, children
  };
  // function members
  string isbn () const; //{ return i; }
  string title () const; //{ return t; }
  string author () const; //{ return a; }
  Genre genre () const; //{ return gen; }
  Date copyright () const;                  // funzionava anche senza ! ! !
  bool checkInOut () const; //{return cio; }
  Book(string i, string t, string a, Genre gen/*oppure char*/, Date c, bool cio);   // Constructor
  Book();   // default Constructor
private:
  // data members
  string i;
  string t;
  string a;
  Genre gen; //gen inizializzato qui e gen mandato nel Costruttore non necessariamente sono nella stessa forma (dove scrivo "oppure char")
  Date c;
  bool cio;
};

// operators
std::ostream& operator<<(std::ostream& os, Book& d);

#endif
