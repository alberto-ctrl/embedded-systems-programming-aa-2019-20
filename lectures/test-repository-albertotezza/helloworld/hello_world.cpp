#include <iostream>
using namespace std;

int main()
{
	int number_of_languages;

	cout << "Hello reader.\n"
		<< "Welcome to C++.\n";

	cout << "How many programming languages have you used? ";
	cin >> number_of_languages;

	if (number_of_languages<1)
		cout << "You may prefer a more elementary course.\n";
	else
		cout << "Enjoy the course.\n";

	return 0;
}
