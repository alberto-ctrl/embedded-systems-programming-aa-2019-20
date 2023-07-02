// testPatron.cpp

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include "Patron.h"


void print_patrons(const vector<Patron>& patrons) {
	cout << "\nThe patrons are:\n";
	for(vector<Patron>::const_iterator pos=patrons.cbegin(); pos != patrons.cend(); ++pos)
	{
		cout << (*pos) << endl;
	}
    cout << endl;
}

void print_patrons_with_fees(const vector<Patron>& patrons) {
	cout << "\nThe patrons with fees are:\n";
	for(vector<Patron>::const_iterator pos=patrons.cbegin(); pos != patrons.cend(); ++pos)
	{
		if ((*pos).owes_fees())
			cout << (*pos) << endl;
	}
    cout << endl;
}

int main() {
    Patron patron1{"Reggiani, Monica",100,0};
    Patron patron2{"Roberto, Oboe",101,0};
    Patron patron3{"Boschetti, Giovanni",102,0};
    Patron patron4{"Faccio, Maurizio",103,0};

	// Patron wrong_patron{"a,b", 106, -10};
	
	// create a vector of patrons
	vector<Patron> the_patrons;
	the_patrons.push_back(patron1);
	the_patrons.push_back(patron2);
	the_patrons.push_back(patron3);
	the_patrons.push_back(patron4);

	print_patrons(the_patrons);

    // set library fees of two patrons
    the_patrons.at(0).set_fees(10);
	print_patrons(the_patrons);

	the_patrons.at(the_patrons.size()-1).set_fees(20);
	print_patrons_with_fees(the_patrons);

	the_patrons.at(0).set_fees(-10);

}