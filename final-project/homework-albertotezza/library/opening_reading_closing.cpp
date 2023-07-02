// opening_reading_closing.cpp

#include "IOManagement.h"
#include "BookingsManagement.h"
#include "GlobalVariables.h"

#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::endl;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;

// function for open the input files (.txt)
// input const by value: file_name, name of file to open (example: "parcheggioUnoIngresso.txt")
ifstream opening(string file_name)
{
  // open a file in read mode
  ifstream infile;
  infile.open("../input_files/"+file_name);

  if (!infile.is_open()) {
     cerr << "error opening the input file" << endl;
     exit(EXIT_FAILURE);
  }

  return infile;
}

// function utilized for getting data from opened files
// input by reference: infile, passing of opened file for reading and get the data
// input + output by reference: readed_car, the function fill this variable with the data readed from infile
bool reading(ifstream& infile, Car& readed_car)
{
  string line;
  if (getline(infile, line))
  {
    // reading line phase
    istringstream iss(line);
    string string1;
    int int1, int2, int3, int4, int5;
    if (!(iss >> string1 >> int1 >> int2 >> int3 >> int4 >> int5)) {
       cerr << "error reading the input file (wrong data)" << endl;
       exit(EXIT_FAILURE);
     } // error
     // variables creation phase:
     Car filling{string1, DateTime{int1, int2, int3, int4, int5}};
     readed_car = filling;
     return true;
  }
   else
       return false;
}

// funtion utilized in bookings_management()
// input by reference: infile, passing of opened file for reading and get the data
// input + output by reference: readed_car, the function fill this variable with the data readed from infile
// input + output by reference: car_in
// input + output by reference: car_out
bool reading(ifstream& infile, Car& readed_booking, Car& car_in, Car& car_out)
{
  string line;
  if (getline(infile, line))
  {
    // reading line phase
    istringstream iss(line);
    string string1;
    int int1, int2, int3, int4, int5, int6, int7, int8, int9, int10, int11;
    if (!(iss >> int1 >> int2 >> int3 >> int4 >> int5 >> string1 >> int6 >> int7 >> int8 >> int9 >> int10 >> int11)) {
       cerr << "error reading the input file (wrong data)" << endl;
       exit(EXIT_FAILURE);
     } // error
     // variables creation phase
     Car filling{string1, DateTime{int1, int2, int3, int4, int5}};
     readed_booking=filling;
     Car filling_in{string1, DateTime{int6, int7, int8, 0, 0}};
     car_in=filling_in;
     Car filling_out{string1, DateTime{int9, int10, int11, 23, 59}};
     car_out=filling_out;
     return true;
  }
   else
       return false;
}

// input by reference: infile, passing of opened file to close that
void closing(ifstream& infile)
{
  // close the opened file.
  infile.close();
}
