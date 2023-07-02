// DateTime.h

#ifndef DateTime_H
#define DateTime_H

#include <ostream>

class DateTime {
public:
	DateTime();	// default constructor
	DateTime(int year, int month, int day, int hour, int minute);	// constructor

	int year() const { return year_; }
	int month() const { return month_; }
	int day() const { return day_; }
	int hour() const { return hour_; }
	int minute() const { return minute_; }
	int date_hours_conv() const;

private:
	int year_;
	int month_;
	int day_;
	int hour_;
	int minute_;
};

// operators
std::ostream& operator<<(std::ostream& os, const DateTime& t);

#endif
