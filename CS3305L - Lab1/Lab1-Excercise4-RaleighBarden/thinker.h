/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.4
*/

class thinking_cap
{
public:
	void slots(char new_green[], char new_red[]);
	void push_green() const;
	void push_red() const;
private:
	char green_string[50];
	char red_string[50];
};
