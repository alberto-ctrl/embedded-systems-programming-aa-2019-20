// Patron.h

#ifndef Patron_h
#define Patron_h

#include <string>

class Patron
{
public:
	Patron();
	Patron(std::string name, int card_number, double fees);

	std::string name() const { return name_; }
	int card_number() const { return card_number_; }
	double fees() const { return fees_; };

	void set_fees(double fees);
	bool owes_fees() const;

private:
	std::string name_;
	int card_number_;
	double fees_;
};

std::ostream& operator<<(std::ostream& os, const Patron& p);
bool operator==(const Patron& p1, const Patron& p2);
bool operator!=(const Patron& p1, const Patron& p2);

#endif