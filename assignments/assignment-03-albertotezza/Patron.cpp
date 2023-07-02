// Patron.cpp

#include "Patron.h"
#include <iostream>
#include <string>
using namespace std;

//costruttore della struttura Book - controlla dati inseriti
Patron::Patron(string uu, string cc_n, int aa)
  :u{uu}, c_n{cc_n}, a{aa} // vado ad accedere ai dati privati della Classe Patron
{
  if(static_cast<int>(c_n.size())>7){
    cerr << "invalid Card number" << endl;
    exit(1);
  }

  if(a<0 || a>99){
    cerr << "invalid Age" << endl;
    exit(1);
  }

}

// return username
string Patron::username() const {
  return u;
}

// return card_number
string Patron::card_number() const {
  return c_n;
}

// return age
int Patron::age() const {
    return a;
}

// have_fee decision
bool Patron::have_fee() {
  if(a<12 || a>65){
    h_f = 0;}
  else{
    h_f = 1;}
  return h_f;
}

// fee value depending heve_fee
float Patron::fee() {
  if(h_f){
    f=7.50;
  }
  else{
    f=0;
  }
  return f;
}

// dati di default per il costruttore di default
const Patron& default_patron() {
  static Patron pp {"First Name, Last Name","654321",0};
  return pp;
}

// funzione per il Costruttore di default
Patron::Patron()
	:u{default_patron().username()},
	c_n{default_patron().card_number()},
  a{default_patron().age()}
{
}


// operators
ostream& operator<<(ostream& os, Patron& p) {
  return os << "Username: " << p.username() << endl
    << "Card number: " << p.card_number() << endl
    << "Age: " << p.age() << endl
    << "Have fee to pay?: " << p.have_fee() << endl
    << "Fee: " << p.fee() << endl ;
}
