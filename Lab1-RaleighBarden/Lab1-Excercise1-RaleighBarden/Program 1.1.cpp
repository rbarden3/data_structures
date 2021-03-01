/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.1
*/


#include <iostream>
using namespace std;

//function prototype for printArray
void printArray(int list[], int arraySize);

//reverse creates a new list of length size in reverse order as teh original list
void reverse(const int list[], int newList[], int size)
{
	for (int i = 0, j = size - 1; i < size; i++, j--) // loops through the array from both sides
	{
		newList[j] = list[i]; //sets the new list index equal to the opposite index of the original list
	}
}

//function is intended to change the first value of the array to 100
// To allow this, we remove the const restraint from before int
void p(int list[], int arraySize)
{
	list[0] = 100; // sets the first value of list to 100
}

//main function. Declares an array of numbers and then turns it into a pallendrome
int main()
{
	//Constant Declaration was missing a "=", moved from line 7 to replace SIZE declaration in line 25
	const int SIZE = 4;
	int newList[SIZE]; //creates a new list of length SIZE
	int numbers[] = { 1, 4, 3, 6, 8 }; //creates a new array of numbers
	p(numbers, 5); // sets the first value of numbers to be 100
	printArray(numbers, 5); //prints the array so far
	reverse(numbers, newList, SIZE); //creates a new array that is the reverse of the original array, -1 length
	printArray(newList, SIZE); // prints the new array

	return 0;
}

//moved printArray definition to be with the declaration and other function definitions
//function prints the array
void printArray(int list[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) //loops through the array
	{
		cout << list[i] << " "; // prints the index value followed by a space to console
	}
}

/*	Summary:	This program takes an array of size n, prints this orriginal array, creates a new array that is a reverse of the original array with size n-1, 
 *				so that it leaves out the last value in the original array, then prints the new array so the output in the console is a pallendrome of the 
 *				original array
 */
