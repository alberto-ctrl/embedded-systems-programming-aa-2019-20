// Student.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Student.h"

Student::Student(string name)
:name_(name)
{}

void Student::display()
{
	cout << "A student with name " << name_ << endl;
}

