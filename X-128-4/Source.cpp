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
	int upper_bound{ 0 };
	int lower_bound{ 0 };
	char side;

	cout << "enter the number you want me to guess: ";
	cin >> the_number;

	//first question
	cout << "Is the number less than 50? \n";
	if (the_number < 50) 
	{
		cout << "- Yes, it seems your number (" << the_number << ") is less than 50.\n";
		upper_bound = 49;
		side = 'L';

	}
	else {
		cout << "- No,  it seems your number (" << the_number << ") is at least 50.\n";
		upper_bound = 100;
		lower_bound = 50;
		side = 'R';
	}
	while (upper_bound - lower_bound > 1) {

		if (side == 'L') {
			cout << "Is the number less than " << upper_bound / 2 << "?\n";
			if (the_number < upper_bound / 2) {
				cout << "- Yes, it seems your number (" << the_number << ") is less than " <<
					upper_bound / 2 << '\n';
				upper_bound = upper_bound / 2;
				side = 'L';
			}
			else {
				cout << "- No,  it seems your number (" << the_number << ") is at least "<<
					upper_bound /2<< '\n';
				lower_bound = upper_bound / 2;
				side = 'R';
			}
		}
		else {
			cout << "Is the number greater than " << upper_bound / 2 << "?\n";
			if (the_number > upper_bound / 2) {
				cout << "- Yes, it seems your number (" << the_number << ") is greater than " <<
					upper_bound / 2 << '\n';
				lower_bound = upper_bound / 2;
				side = 'R';
			}
			else {
				cout << "- No,  it seems your number (" << the_number << ") is less than " <<
					upper_bound / 2 << '\n';
				upper_bound = upper_bound / 2;
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

