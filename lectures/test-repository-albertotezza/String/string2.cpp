// string2.cpp (Josuttis ch. 13.1.2)

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	const string delims{" \t,.;"};
	string line;

	// for every line read successfully
	while (getline(cin, line)) {
		string::size_type beg_idx, end_idx;

		// search beginning of the first word
		beg_idx = line.find_first_not_of(delims);

		// while beginning of a word found
		while (beg_idx!=string::npos) {
			// search end of the actual word
			end_idx = line.find_first_of(delims, beg_idx);
			if (end_idx == string::npos) {
				// end of word is end of getline
				end_idx = line.length();
			}

			// print chracters in reverse order
			for (int i=end_idx-1; i>=static_cast<int>(beg_idx); --i) {
				cout << line[i];
			}

			cout << ' ';

			// search begining of the next word
			beg_idx = line.find_first_not_of(delims, end_idx);
		}
		cout << endl;
	}

}
