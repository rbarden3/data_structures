/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 2 - Problem 4
*/


// Section 7.3 #16 - Page 374 in Text
// Give the full implementation of a constant member function that returns the second element 
// from the top of the stack without actually changing the stack. 
// Write separate solutions for the two different stack versions.

#include <iostream>
using namespace std;
class Stack {
private:
	int stack_list[100] = { NULL }; // create default list
public:
	Stack() { } // Constructor
	int display_second_element();
	void insert(int);
	
};
int Stack::display_second_element() { // displays the second element of the stack
	if (stack_list[1] == NULL) { //prints NULL if the value is null
		cout << "NULL" << endl; 
	}
	else {
		cout << stack_list[1]; // Else prints the value
	}
	return stack_list[1];
}
void Stack::insert(int item) { //inserts a value to the stack
	int counter = 0;

	while (stack_list[counter] != NULL) { //looks for the first open spot in the stack
		counter += 1;
	}
	stack_list[counter] = item; // adds the value to the first open spot in the stack.
}
int main()
{
	cout << "Second Element with Empty List" << endl;
	Stack my_stack = Stack();
	my_stack.display_second_element();
    
	cout << "Second Element After adding elements:" << endl;
	my_stack.insert(1);
	my_stack.insert(2);
	my_stack.insert(3);
	my_stack.display_second_element();
}


