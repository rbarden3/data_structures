/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.4
*/


#include "thinker.h" //imports thinker.h
int main()
{
	thinking_cap student; // creates a thinking_cap object student
	thinking_cap fan; // creates a thinking_cap object student
	
	//I had to move string to variables to fit with argument parameters
	char a1[] = "Hello";  
	char a2[] = "Goodbye";
	char b1[] = "Go Cougars!";
	char b2[] = "Boo!";

	student.slots(a1, a2);
	fan.slots(b1, b2);
	student.push_green();
	fan.push_green();
	student.push_red();

	return 0;
}
