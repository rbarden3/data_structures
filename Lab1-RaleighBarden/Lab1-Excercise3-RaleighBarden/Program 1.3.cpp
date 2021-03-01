/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 1.3
*/

#include <iostream>
using namespace std;

void swap1(int n1, int n2) //function swaps the value of n1 and n2; however, does not change the parameters as they are not pointers
{
	int temp = n1; // declare a new int as n1
	n1 = n2; // set n1 as n2
	n2 = temp; // set n2 as temp
}

void swap2(int& n1, int& n2) //function swaps the value of n1 and n2; changes the value of the passed variables in main
{
	int temp = n1; // sets temp as n1
	n1 = n2; // sets n1 as n2
	n2 = temp; // sets n2 as temp
}

void swap3(int* p1, int* p2) //function swaps the value of n1 and n2; changes the value of the passed variables in main
{
	int temp = *p1; // sets temp as p1
	*p1 = *p2; // sets p1 as p2
	*p2 = temp; // sets p2 as temp
}

void swap4(int*& p1, int*& p2)
{
	int* temp = p1; //sets temp as a pointer to p1
	p1 = p2; // sets p1 as a pointer to p2's object
	p2 = temp; // sets p2 as temp
}

int main()
{
	int num1 = 1; // declare num1
	int num2 = 2; //declare num2

	cout << "Before invoking the swap1 function, num1 is "
		<< num1 << " and num2 is " << num2 << endl; // print og values for num1 and num2

	swap1(num1, num2); 

	cout << "After invoking the swap1 function, num1 is " << num1 <<
		" and num2 is " << num2 << endl; //print values for num1 and num2 after swap1

	cout << "Before invoking the swap2 function, num1 is "
		<< num1 << " and num2 is " << num2 << endl; //print values for num1 and num2 before running swap2

	swap2(num1, num2);

	cout << "After invoking the swap2 function, num1 is " << num1 <<
		" and num2 is " << num2 << endl; //print values for num1 and num2 after swap2

	cout << "Before invoking the swap3 function, num1 is "
		<< num1 << " and num2 is " << num2 << endl; //print values for num1 and num2 before running swap3

	swap3(&num1, &num2);

	cout << "After invoking the swap3 function, num1 is " << num1 <<
		" and num2 is " << num2 << endl;//print values for num1 and num2 after swap3

	int* p1 = &num1;
	int* p2 = &num2;
	cout << "Before invoking the swap4 function, p1 is "
		<< p1 << " and p2 is " << p2 << endl; //print values for p1 and p2 before swap4

	swap4(p1, p2);

	cout << "After invoking the swap4 function, p1 is " << p1 <<
		" and p2 is " << p2 << endl; //print values for p1 and p2 after swap4
	return 0;
}

