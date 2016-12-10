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
	int upper_bound{ 500 };
	int lower_bound{ 0 };
	int temp{ 0 };
	char side = 'L';;

	cout << "enter the number you want me to guess: ";
	cin >> the_number;

	//first question
	while (upper_bound - lower_bound > 1) {
//		keep_window_open();
		if (side == 'L')
		{
			temp = (upper_bound - lower_bound) / 2;
			upper_bound = upper_bound - temp;
		}
		else
		{
			temp = (upper_bound - lower_bound) / 2;
			lower_bound = upper_bound;
			upper_bound = lower_bound + temp;
		}

		if (side == 'L') {
			cout << "TL - Is the number less than  " << upper_bound << "?\n";
			if (the_number < upper_bound) {
				cout << "- Yes, it seems your number (" << the_number << ") is less than " <<
					upper_bound << '\n';
				side = 'L';
			}
			else {
				cout << "TR - No,  it seems your number (" << the_number << ") at least "<<
					upper_bound << '\n';

				side = 'R';
			}
		}
		else {
			cout << "RR - Is the number greater than " << upper_bound << "?\n";
			if (the_number > upper_bound) {
				cout << "- Yes, it seems your number (" << the_number << ") is greater than " <<
					upper_bound << '\n';
				side = 'R';
			}
			else {
				cout << "RL - No,  it seems your number (" << the_number << ") is less than " <<
					upper_bound << '\n';
				side = 'L';

			}
		}
	}
	cout << "Upper_bound is: " << upper_bound << '\n';
	cout << "Lower_bound is: " << lower_bound << '\n';
	if (upper_bound - lower_bound == 0) cout << "Your number (" << the_number << ") is: " <<upper_bound << "\n";
	else cout<<"Your number (" << the_number << ") is: " <<upper_bound -1 << "\n";

	keep_window_open();
}

