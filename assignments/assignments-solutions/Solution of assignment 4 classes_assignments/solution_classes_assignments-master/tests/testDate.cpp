// testDate.cpp

#include <iostream>
using std::cout;
using std::endl;
#include "../Date.h"

int main()
{
	cout << "Testing Date class\n\n"; 

	// create a few Date objects

	// 1. default date
	Date default_d;
    cout << "Default date: " << default_d << endl;

	Date today{2019, Date::Month::oct, 27};
	Date birthday{1970, 9, 17};
	
	cout << "Today:" << today << endl;
	cout << "Birthday" << birthday << endl;

	// Dates with wrong day
	// Date wrongDay1{2019, Date::Month::jan, -1};
	// Date wrongDay2{2019, Date::Month::jan, 35};
	// Dates with wrong month
	// Date wrongMonth{2019, 14, 1}; // this does not compile

	// test copy operation (=)
	Date tomorrow = today;
	tomorrow.add_day(1);

	// test print day (and function month to string)
	cout << "today:" << today << endl;
	cout << "tomorrow:" << tomorrow << endl;
		
    Date next_year = today;
    next_year.add_year(1);
	
	cout << "next year: " << next_year << endl;
}