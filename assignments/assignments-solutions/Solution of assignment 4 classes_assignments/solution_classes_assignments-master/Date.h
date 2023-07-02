// Date.h

#ifndef Date_h
#define Date_h

#include <ostream>
#include <tuple>
#include <vector>
#include <string>

class Date {
public:

	enum class Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	// constructors
	Date(int y, Month m, int d);    // check for valid date and initialise
	Date(int year, int month, int day);
	Date();                         // default constructor

	// const members: can't modify the object
	int year() const { return year_; }
	Month month() const { return month_; }
	std::string month_as_string() const { return month_to_string(month_); }
	int day() const {return day_; }

	// non-const members
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);

private:
	int year_;      
	Month month_;
	int day_;      

	// helper function, private because not part of the interface
	std::string month_to_string(Month month) const;
	Month int_to_month(int month_as_int) const;
};

// operators
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif