/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.4
*/



#include <iostream> // I chanfed this from <iostream.h> and added the namespace to fix an import error
using namespace std;

#include <stdlib.h>
#include <assert.h> 
#include "thinker.h"

void thinking_cap::slots(char new_green[], char new_red[])
{
	assert(strlen(new_green) < 50);
	assert(strlen(new_red) < 50);
	strcpy_s(green_string, new_green); //converted strcpy to strcpy_s
	strcpy_s(red_string, new_red);	//converted strcpy to strcpy_s
}
void thinking_cap::push_green() const // I had to add parentheses and const to fix the declaration for this function
{
	 cout << green_string << endl; //prints  green_string followed by a newline
}
void thinking_cap::push_red() const // I had to add parentheses and const to fix the declaration for this function
{
	 cout << red_string << endl;
}
