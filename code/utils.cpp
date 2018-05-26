/* ============================================================================
 * Program:  utils.cpp
 * Author: 	mzc
 * 
 * Description:  Implementations for the utils functions.
 *               Functions created to handle input validations
 *				Functionality enhanced via discussion on StackOverflow
 *				and study group members and Canvas discussion
 *  ============================================================================
 */

#include <iostream>
#include <string>
#include <cstdlib> //to convert string to an integer
#include <limits.h>
#include <sstream>
#include <istream>
#include "list.hpp"
#include "utils.hpp"

using namespace std;

//validating user input - use of a generic function with different values
// depending on what input has to be validated

int readInteger(const string & prompt, int min, int max) {

	string input;
	bool goodInput;
	int numValue;

	do {
		cout << prompt << " ";
		cout << endl;
		getline(cin, input);

		goodInput = true;

		//loop through the entire length of the input from user
		// if any value entered is not an integer, print error message

		for (unsigned i = 0; i < input.length(); ++i) {
			if (!(isdigit(input.at(i)))) {
				cout << "That is not a positive integer.  Please re-enter"
						<< endl;
				goodInput = false;
				break;
			}
		}
		numValue = atoi(input.c_str());   //converts string to integer
		//if any zeroes are entered, print error message and allow for correct input

		if (goodInput && (numValue < min || numValue > max)) {
			goodInput = false;
			cout << "Out of bounds. Please re-enter. " << endl;
		}
	} while (!goodInput);

	return numValue;
}

//to read in doubles as input from the user
//functionality added as a result of test plan results

double readDouble(const string & prompt, double minD, double maxD) {

	bool goodInput;
	double numValue;

	do {
		cout << prompt << " ";
		cout << endl;
		cin >> numValue;

		goodInput = true;

		//loop through the entire length of the input from user
		// if any value entered is not a double, print error message
		if (!cin || !validateWhitespaceToEol(cin)) {

//test to see that the validateWhitespaceToEol(cin) function give correct output

//			cout << "cin is " << ((bool) cin) << " and eof is " << cin.eof()
//					<< " and cin.fail() is " << cin.fail() << endl;
//			cout << "Current numValue: " << numValue << endl;

			cout << "Invalid characters detected. " << "Please re-enter"
					<< endl;
			cin.clear();

			//probably not needed but here due to justifiable and deeply ingrained paranoia ;-)
			if (!cin.eof())
				cin.ignore(20, '\n');


			goodInput = false;
		}

		//if any zeroes are entered, print error message and allow for correct input

		if (goodInput && (numValue < minD || numValue > maxD)) {
			goodInput = false;
			cout << "Out of bounds. Please re-enter. " << endl;
		}
	} while (!goodInput);

	return numValue;
}

bool validateWhitespaceToEol(istream& in) {
	string line;
	getline(in, line);
	return line.find_first_not_of(" \t\r\n") == string::npos;
}
