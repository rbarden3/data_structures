/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 2 - Problem 3
*/


// Section 6.1 (Text page 301) - #1-6:


#include <iostream>
#include <string>
using namespace std;

template <class T, class U>
string compare(T a, U b) {
	string out;
	if (a == b) {
		out = "Those are the same";
		cout << out << endl;
	}
	else {
		out = "Those are different";
		cout << out << endl;
	}
	return out;
}
int main()
{
	cout << "Section 2.1 (Text page 45) - #1-6:\n" << endl;

	//Question and Answer for Problem #1
	cout << "Q #1: \tDescribe the main purpose of a template function" << endl;
	cout << "A #1: \tTo be able handle differnt datatypes and to avoid duplicate code." << "\n" << endl;

	//Question and Answer for Problem #2
	cout << "Q #2: \tWhat is the disadvantage of the typedef approach of generalizing a data type compared to the template approach? Is there any advantage to the typedef approach?" << endl;
	cout << "A #2: \tThe typedef approach only allows one datatype to be used for the program as opposed to the template approach which allows multiple datatypes to be used. The benefit of typedef is that it has a simpler syntax." << endl;
	cout << "\tThe benefit of typedef is that it has a simpler syntax." << "\n" << endl;
	//Question and Answer for Problem #3
	cout << "Q #3: \tWhat is the template prefix, and where is it used in a template function?" << endl;
	cout << "A #3: \tThe template prefix is '<>' and it is used when the class is defined and before each function is implemented" << "\n" << endl;

	//Question and Answer for Problem #4
	cout << "Q #4: \tWhat is meant by unification?" << endl;
	cout << "A #4: \tProcess done by the compiler in order to determine how to instantiate the template function" << "\n" << endl;

	//Question and Answer for Problem #5
	cout << "Q #5: \tWhich data types are allowed for the template Item parameter in the maximal function?" << endl;
	cout << "A #5: \tAny built in datatypes, or a class with a copy constructor and an assignment operator." << "\n" << endl;

	//Question and Answer for Problem #6
	string Q6 = "\tWrite a template function that compares two items. If the items are equal, then the message “Those are the same” is printed. \n";
	Q6 = Q6 +   "\tOtherwise the message “Those are different” is printed. The function has two parameters. \n";
	Q6 = Q6 +   "\tThe parameter type may be any type that has a copy constructor and has the == operator defined.";

	cout << "Q #6: " << Q6 << endl;
	cout << "A #6: \tComparison Template Function Created in Code above; Demonstrated Below:" << "\n" << endl;
	cout << "Item a = (int) 1 --- Item b = (int) 1" << endl;
	int a = 1;
	int b = 1;
	compare(a, b);

	cout << "Item a = (int) 1 --- Item b = (int) 2" << endl;
	a = 1;
	b = 2;
	compare(a, b);
	cout << "Item a = (char) 'a' --- Item b = (char) 'a'" << endl;
	char a_char = 'a';
	char b_char = 'a';
	compare(a_char, b_char);
}
