// Library.h

#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>

using namespace std;
#include "Date.h"
#include "Book.h"
#include "Patron.h"


class Library {
  public:
    Library();    // default Constructor
  /*
    Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> transactions);   // Constructor

    // _function members_
    vector<Book> books() const { return v_book_; }
    vector<Patron> patrons() const { return v_patron_; }
    vector<Transaction> transactions() const { return v_transaction_; }
  */

    void add_book(const Book new_book);
    void add_patron(const Patron new_patron);
    void check_out_book(const Book b, const Patron p, const Date d);
    vector<Patron> patrons_owe_fees();

  private:
    // struct Transaction
    struct Transaction {
      Book trans_book;
      Patron trans_patron;
      Date trans_date;
    };

    // _data members_
    vector<Book> v_book_;
    vector<Patron> v_patron_;
    vector<Transaction> v_transaction_;


};

// operators
//std::ostream& operator<<(std::ostream& os, Patron& p);

#endif
