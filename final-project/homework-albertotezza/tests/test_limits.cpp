// test_limits.cpp

#include <limits>
#include <iostream>
using std::cout;
using std::endl;


int main() {

  int imin = std::numeric_limits<int>::min(); // minimum value
  int imax = std::numeric_limits<int>::max();


  float fmin = std::numeric_limits<float>::min(); // minimum positive value
  float fmax = std::numeric_limits<float>::max();

  cout << "minimum <int> value: " << imin << endl;
  cout << "maximum <int> value: " << imax << endl;
  cout << "minimum <float> value: " << fmin << endl;
  cout << "maximum <float> value: " << fmax << endl;

  // from: AA:00 MM:01 DD:01 HH:00 MM:00
  // to:   AA:99 MM:12 DD:31 HH:23 MM:59
  // there are: 52595999 minutes (no problem with int +-2147483647)

  return 0;
}
