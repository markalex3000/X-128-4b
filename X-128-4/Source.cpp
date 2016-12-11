// Guess user number between 1 and 100

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

int main() {
	int the_number{ 0 };
	int upper_bound{ 100 };
	int lower_bound{ 0 };
	int test_number{ 0 };
	int temp{ 0 };
	char side = 'L';

	cout << "enter the number you want me to guess: ";
	cin >> the_number;


	while (upper_bound - lower_bound > 1) {

		if (side == 'L')
		{
			temp = (upper_bound - lower_bound) / 2;
			test_number = upper_bound - temp;
		}
		else
		{
			temp = (test_number - lower_bound) / 2;
			lower_bound = test_number;
			test_number = upper_bound - temp;
		}


		cout << "TL - Is the number less than  " << test_number << "?\n";
		if (the_number < test_number) {
			cout << "- Yes, it seems your number (" << the_number << ") is less than " <<
				test_number << '\n';
			side = 'L';
			upper_bound = test_number;
		}
		else {
			cout << "TR - No,  it seems your number (" << the_number << ") at least "<<
				test_number << '\n';
			side = 'R';
			}

	}
	cout << "Upper_bound is: " << upper_bound << '\n';
	cout << "Lower_bound is: " << lower_bound << '\n';

	cout<<"Your number (" << the_number << ") is: " << upper_bound - 1 << "\n";

	keep_window_open();
}

