// Library.cpp

#include "Library.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

  Library::Library()
/*
    :v_book_{},
    v_patron_{},
    v_transaction_{}
*/
  {}

//---------------------------------------------------------------------------------------------------------------------------------------------
/*
  Library::Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> transactions)
  :v_book_{books},
  v_patron_{patrons},
  v_transaction_{transactions}
  {
    ;
  }
*/
//---------------------------------------------------------------------------------------------------------------------------------------------
void Library::add_book(const Book new_book)
{
  v_book_.push_back(new_book);
}

//---------------------------------------------------------------------------------------------------------------------------------------------
void Library::add_patron(const Patron new_patron)
{
  v_patron_.push_back(new_patron);
}

//---------------------------------------------------------------------------------------------------------------------------------------------
void Library::check_out_book(const Book b, const Patron p, const Date d)
{
  bool b_ok{false};
  bool p_ok{false};
  int i_b{0};
  int i_p{0};

  for(i_b=0; i_b<static_cast<int>(v_book_.size()); ++i_b)
    if(b.title()==v_book_[i_b].title())
      b_ok=true;

  for(i_p=0; i_p<static_cast<int>(v_patron_.size()); ++i_p)
    if(p.name()==(v_patron_[i_p]).name())
      p_ok=true;

  if (b_ok && p_ok) {
      Transaction t{b, p, d};
      v_transaction_.push_back(t);    // aggiungo al vettore di transactions il libro

      v_book_.erase(v_book_.begin()+i_b);
      v_patron_.erase(v_patron_.begin()+i_p);     // elimino libro e patron da v_book_ e v_patron_
  }
  else {
    cout << "chech_out_book() : error, stai cercando di fare il check out di un 'book' o di un 'patron' non presente nella 'library'" << endl;
    exit(EXIT_FAILURE);
  }
}

//---------------------------------------------------------------------------------------------------------------------------------------------
vector<Patron> Library::patrons_owe_fees()
{
  vector<Patron> pa;
  for(int i=0; i<static_cast<int>(v_patron_.size()); ++i)
    if ((v_patron_[i]).fees()!=0.)
      pa.push_back(v_patron_[i]);
  return pa;
}

//---------------------------------------------------------------------------------------------------------------------------------------------
/*
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
*/
