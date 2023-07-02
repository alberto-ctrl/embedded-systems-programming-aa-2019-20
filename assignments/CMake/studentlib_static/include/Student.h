// Student.h
#ifndef Student_h
#define Student_h

#include<string>

class Student{
public:
	Student(std::string);
	void display();
private:
	std::string name_;
};

#endif