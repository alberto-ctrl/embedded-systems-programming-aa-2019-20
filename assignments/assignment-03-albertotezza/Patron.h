// Patron.h

#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
using namespace std;

class Patron {
public:
  //__function members__
  Patron(string u, string c_n, int a);   // Constructor
  Patron();   // default Constructor

  string username() const;
  string card_number() const;
  int age() const;
  bool have_fee();
  float fee();


private:
  //__data members__
  string u; // user_name
  string c_n; // card_number
  int a; // age
  bool h_f; // have_fee
  float f; // fee value

};

// operators
std::ostream& operator<<(std::ostream& os, Patron& p);

#endif
