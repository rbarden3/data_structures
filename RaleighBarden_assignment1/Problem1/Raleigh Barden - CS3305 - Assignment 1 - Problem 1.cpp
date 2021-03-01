/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 1 - Problem 1
*/

// Section 1.1 (Text page 15) - #5:
// One of the libraries is the <cmath> facility, which contains a function
// with this prototype:
//		double sqrt(double x);
// The function returns the square root of x. Write a reasonable precondition
// and postcondition for this function, and compare your answer to the
// solution at the end of the chapter.

#include <iostream>
#include <string>
#include <cassert>  
#include <math.h>
using namespace std;
double sqrt(double x) {
	assert(x >= 0); // Precondition:
	double ans = pow(x, 0.5); // the square root is x to the power of (1/2)
	assert(fabs(x - (ans * ans)) < 0.0001); // Post condition: x is the square of Ans (use absolute difference to account for lossy function)
	return ans;
}


int main()
{
    cout << "Enter your number: ";
	double in_num;
	cin >> in_num;
	cout << "\nThe square of " << to_string(in_num) << " is " << to_string(sqrt(in_num)) << "\n" << endl;
}

