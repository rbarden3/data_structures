/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 1 - Problem 2
*/


// Section 1.1 (Text page 15) - #8:
// Write a program to print a conversion table from feet to meters.Use the
// temperature conversion program as the starting point(available online at
// www.cs.colorado.edu / ~main / chapter1 / temperature.cxx).


// *** Program Adapted from code prvided at above loaction ***
#include <iostream>    // Provides cout
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
using namespace std;   // Allows all standard library items to be used
double celsius_to_fahrenheit(double c)
// Precondition: c is a Celsius temperature no less than absolute
// zero (-273.16).
// Postcondition: The return value is the temperature c converted to Fahrenheit
// degrees.
{
	const double MINIMUM_CELSIUS = -273.16; // Absolute zero in Celsius degrees
	assert(c >= MINIMUM_CELSIUS);
	return (9.0 / 5.0) * c + 32;
}
double feet_to_meters(double ft) {
	// Precondition: ft is a distance in feet no less than zero.
	// Postcondition: The return value is the distance converted to meters
	assert(ft > 0); 
	// According to: https://www.unitconverters.net/length/feet-to-meters.htm , "A foot was defined as exactly 0.3048 meters in 1959."
	return ft * 0.3048; // convert feet to meters 

}
void setup_cout_fractions(int fraction_digits)
// Precondition: fraction_digits is not negative.
// Postcondition: All double or float numbers printed to cout will now be
// rounded to the specified digits on the right of the decimal.
{
	assert(fraction_digits > 0);
	cout.precision(fraction_digits);
	cout.setf(ios::fixed, ios::floatfield);
	if (fraction_digits == 0)
		cout.unsetf(ios::showpoint);
	else
		cout.setf(ios::showpoint);
}

int main()
{
	const char   HEADING1[] = "   Feet"; // Heading for table's 1st column
	const char   HEADING2[] = "Meters"; // Heading for table's 2nd column
	const char   LABEL1[] = "ft"; // Label for numbers in 1st column
	const char   LABEL2 = 'm'; // Label for numbers in 2nd column
	const double TABLE_BEGIN = 10; // The table's first Distance in Feet.
	const double TABLE_END = 100.0; // The table's final Distance in Feet.
	const double TABLE_STEP = 10.0; // Increment between distances
	const int    WIDTH = 9; // Number chars in output numbers
	const int    DIGITS = 3; // Number digits right of decimal pt

	double value1;  // A value from the table's first column
	double value2;  // A value from the table's second column

	// Set up the output for fractions and print the table headings.
	setup_cout_fractions(DIGITS);
	cout << "CONVERSIONS from " << TABLE_BEGIN << " to " << TABLE_END << endl;
	cout << HEADING1 << "  " << HEADING2 << endl;

	// Each iteration of the loop prints one line of the table.
	for (value1 = TABLE_BEGIN; value1 <= TABLE_END; value1 += TABLE_STEP)
	{
		value2 = feet_to_meters(value1);
		cout << setw(WIDTH) << value1 << LABEL1 << "  ";
		cout << setw(WIDTH) << value2 << LABEL2 << endl;
	}

	return EXIT_SUCCESS;
}
