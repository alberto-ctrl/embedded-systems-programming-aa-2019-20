// date_time.cpp

#include "DateTime.h"

#include <ostream>
#include <iostream>
#include <iomanip>

// default constructor
DateTime::DateTime()
	// default date: 01 gennaio 2000
	:year_{00},
	month_{01},
	day_{01},
	// default time: 00:00
	hour_{00},
  minute_{00}
{}

// constructor
DateTime::DateTime(int year, int month, int day, int hour, int minute)
	:year_{year},
	month_{month},
	day_{day},
	hour_{hour},
	minute_{minute}
{
  // check for data provided by the input file
	if (year_<0 || year_>99 || month_<1 || month_>12 || day_<1 || day_>31 || hour_<0 || hour_>23 || minute_<0 || minute_>59)  {
		std::cerr << "DateTime(): wrong temporal information\n";
		exit(EXIT_FAILURE);
	}
}

// output by return: i, an integer type obtained by conversion of the calling DateTime type variable
int DateTime::date_hours_conv() const
{
	  int i{0};
	  i+=year_*60*24*31*12;
	  i+=month_*60*24*31;
	  i+=day_*60*24;
	  i+=hour_*60;
	  i+=minute_;
	  return i;
}

// operators
std::ostream& operator<<(std::ostream& os, const DateTime& t)
{
	return os << std::setfill ('0') << std::setw (2) << t.year()
		 					 << ' ' << std::setfill ('0') << std::setw (2) <<  t.month()
		 					 << ' ' << std::setfill ('0') << std::setw (2) << t.day()
	 	 					 << ' ' << std::setfill ('0') << std::setw (2) << t.hour()
		 					 << ' ' << std::setfill ('0') << std::setw (2) << t.minute();
}
