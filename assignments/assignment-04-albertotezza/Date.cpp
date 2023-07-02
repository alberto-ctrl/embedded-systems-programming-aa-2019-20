#include <ostream>
using std::ostream;
#include <iostream>
using std::cerr;
#include <string>
using std::string;
#include <tuple>
#include <algorithm>

#include "Date.h"

Date::Date(int year, Month month, int day)
	:year_{year}, month_{month}, day_{day}
{
	if (month_<Date::Month::jan || month_>Date::Month::dec || day_<1 || day_>31)  {
		cerr << "Date(): invalid date\n";
		exit(EXIT_FAILURE);
	}
}

Date::Date(int year, int month, int day)
	:year_{year}, month_{int_to_month(month)}, day_{day}
{
	if (month_<Date::Month::jan || month_>Date::Month::dec || day_<1 || day_>31)  {
		cerr << "invalid date\n";
		exit(EXIT_FAILURE);
	}
}

//----------------------------------------------------------------------------default_constructor------
const Date& default_date()
{
	static Date dd{2001,Date::Month::jan,1};   // start of 21st century
	return dd;
}

Date::Date()
	:year_{default_date().year()},
	month_{default_date().month()},
	day_{default_date().day()}
{
}
//-----------------------------------------------------------------------------------------------------

// increase the date by n years
void Date::add_year(int n)
{
	year_ += n;
}

// increase the date by n months
void Date::add_month(int n)
{
	// too complicated
}

// increase the Date by n days
void Date::add_day(int n)
{
	day_ += n;
	if (day_ > 31) {
		cerr << "add_day() results in invalid date\n";
		exit(EXIT_FAILURE);
	}

}

std::string Date::month_to_string(Date::Month month) const
{
	switch (month) {
	case Month::jan:
		return "january";
	case Month::feb:
		return "february";
	case Month::mar:
		return "march";
	case Month::apr:
		return "april";
	case Month::may:
		return "may";
	case Month::jun:
		return "june";
	case Month::jul:
		return "july";
	case Month::aug:
		return "august";
	case Month::sep:
		return "september";
	case Month::oct:
		return "october";
	case Month::nov:
		return "november";
	case Month::dec:
		return "december";
	default:
		cerr << "Date::month_to_string(): input is not a Month\n";
		exit(EXIT_FAILURE);
	}
}

Date::Month Date::int_to_month(int month_as_int) const
{
	switch (month_as_int)
	{
	case 1:
		return Month::jan;
	case 2:
		return Month::feb;
	case 3:
		return Month::mar;
	case 4:
		return Month::apr;
	case 5:
		return Month::may;
	case 6:
		return Month::jun;
	case 7:
		return Month::jul;
	case 8:
		return Month::aug;
	case 9:
		return Month::sep;
	case 10:
		return Month::oct;
	case 11:
		return Month::nov;
	case 12:
		return Month::dec;
	default:
		cerr << "Date::int_to_mont(): " << month_as_int << " is not between 1 and 12\n";
		exit(EXIT_FAILURE);
	}
}

// operators
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month_as_string()
		<< ',' << d.day() << ')';
}
