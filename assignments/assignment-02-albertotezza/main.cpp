// main.cpp
#include "Book.h" //non serve il #include "Date.h" (perchè viene poi chiamato in Book.h)
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
/*  cout << "iserire codice ISBN: ";
  char isbn;
  cin >> isbn;
  cout << endl << "iserire titolo: ";
  char titolo;
  cin << titolo;
  cout << endl << "iserire autore: ";
  char autore;
  cin << autore;
  cout << endl << "iserire genere (1=fiction, 2=nonfiction, 3=periodical, 4=biography, 5=children): ";
  int genere;
  cin << genere;
*/

  Book libro{"1-2-3-x","Casa tua","Pamela Anderson",Book::nonfiction,Date{1970,Date::jun,25},0};
  cout << "il libro inserito e':" << libro << endl;
  Book librodefault;
  cout << "il libro inserito e':" << librodefault << endl;
  //cout << libro.d();
  return 0;
}
