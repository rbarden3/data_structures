/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.2
*/

#include <iostream>
using namespace std;

void m(int, int[]); // Function Prototype for m
void p(int list[], int arraySize) // function p sets the first value of list to 100
{
	list[0] = 100; // sets the first value of list to 100
}

int main()
{
	int x = 1; // initislize int x as 1
	int y[10]; // initialize list y
	y[0] = 1; // set y[0] to 1

	m(x, y);	//runs function m with x and y as parameters; 
				//y[0] is changed by m since arrays are passed by reference; however, x is passed as value so it does not change

	cout << "x is " << x << endl; // prints the value of x to the console with the initial phrase "x is"
	cout << "y[0] is " << y[0] << endl; // prints the value of y[0] to the console with the initial phrase "y[0] is"

	return 0;
}

void m(int number, int numbers[]) // function m gives number parameter a new value and changes the value for the first index of numbers parameter
{
	number = 1001; // sets number to 1001
	numbers[0] = 5555; // sets the first index of numbers to 5555
}

/*	Summary:	This function sets an int variable to 1001 and the first value of a list to 5555. Then prints the values to console.
 */
