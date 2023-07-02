// Patron.cpp

#include <iostream>
using std::cerr;
#include <string>
using std::string;


#include "Patron.h"

Patron::Patron()
	: name_(""), card_number_(0), fees_(0.0)
{}

Patron::Patron(string name, int card_number, double fees)
	: name_(name), card_number_(card_number), fees_(fees)
{
	if (fees < 0.) {
		cerr << "Patron::Patron(): fees less than 0\n";
		exit(EXIT_FAILURE);
	}
}

void Patron::set_fees(double fees)
{
	if (fees < 0.) {
		cerr << "Patron::set_fees(): fees cannot be smaller than zero\n";
		exit(EXIT_FAILURE);
	}
	fees_ = fees;
}

bool Patron::owes_fees() const
{
	return fees_ > 0.;					// ritorna 1 se la fees è maggiore di 0
}

std::ostream& operator<<(std::ostream& os, const Patron& p)
{
	os << p.name() << '\n' << p.card_number() << "\n" << p.fees();
	return os;
}

bool operator==(const Patron& p1, const Patron& p2)
{
	return (p1.name() == p2.name() && p1.card_number() == p2.card_number());
}

bool operator!=(const Patron& p1, const Patron& p2)
{
	return !(p1 == p2);
}
