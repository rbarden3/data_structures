/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Program 3.1
*/

#include <iostream>
using namespace std;
struct student {
	string name;
	int id;
	string course[3]; // or pointer could be defined
	float gpa[3]; //or pointer could be defined
	student* next = NULL;
	student* prev = NULL;
};

class SRec {
private:
	
public:
	student* head; // first student in the list
	student* last; // last record added to reduce need for iteration
	SRec(student* new_stu) {
		// when this doubly linked list initializes, the original student is both the first and last student
		head = new_stu;
		last = new_stu; 
	}

	void insert(student* new_stu) {
		new_stu->prev = this->last; // set the prev reference in the new student to the last item in the list
		this->last->next = new_stu; // set the next reference in the last student to the new student
		this->last = new_stu; // set the last item in the list as the new student
	}
	void delet(student* new_stu) { // deletes the record of the student
		bool more_students = true;
		student* current_stu = this->head;
		if (this->head == new_stu) { // check to see if the head is the student we are looking to delete
			this->head = this->head->next; // head needs to be checked individually because the head for the list needs to be reset.
			//delete current_stu;
		}
		else {
			current_stu = current_stu->next; // if the head is not the problem, continue

			while (more_students) {
				if (current_stu == new_stu) {
					if (this->last == new_stu) {
						this->last = this->last->prev;
					}
					current_stu->prev->next = current_stu->next;
					//delete current_stu;
					more_students = false;
				}
				else if (current_stu->next) {
					current_stu->prev = current_stu;
					current_stu = current_stu->next;
				}
				else {
					more_students = false;
					cout << "Student Record Not Found";

				}
			}
		}
	};
	void display() {
		//create bool for while loop and initialize the current student
		bool more_students = true;
		student* current_stu = this->head;
		while (more_students) {
			if (current_stu) {
				//printout for each individual student record:
				std::cout << "Name: " << current_stu->name << "\t ID: " << current_stu->id << endl; //prints students name and id
				std::cout << "Courses: \t|\t GPA: " << endl; //this statement along with the following for loop should provide a nice looking table for reference
				for (int i = 0; i < 3; i++) {
					std::cout << "" << current_stu->course[i]<<"\t\t|\t " << current_stu->gpa[i] << endl;
				}
				std::cout << endl << endl; // Adds a spacer between student references
				if (current_stu->next) {
					current_stu = current_stu->next;
				}
				else {
					more_students = false;
				}
				//end print out for this student
			}
			else {
				more_students = false;
			}
		}
	};
};

int main() {
	//student structures are created
	student jim{ "Jim Smith  ", 01, { "Math", "History", "English" }, {4.0, 3.0, 3.0}};
	student doug{ "Doug Jones", 02, { "Math", "History", "Physics" }, {4.0, 4.0, 2.0} };
	student bret{ "Bret Miller", 03, { "Lit", "History", "Physics" }, {3.0, 4.0, 3.0} };
	student mary{ "Mary Brown", 05, { "Lit", "Math", "English" }, {2.0, 3.0, 1.0} };
	student sally{ "Sally Homes", 04, { "Lit", "History", "Spanish" }, {3.0, 4.0, 2.0} };
	

	//The student record object is declared and initialized
	cout << "The First Student Here is Jim Smith" << endl;
	cout << "Printing student records:" << endl;
	SRec records = SRec(&jim);
	records.display(); //display records inserted thus far

	// insert the rest of the student structures to the linked list
	cout << "The other students need to be added to the records," << endl;
	cout << "Reprinting student records:" << endl;
	records.insert(&doug);
	records.insert(&bret);
	records.insert(&sally);
	records.insert(&mary);
	records.display(); //display records inserted thus far

	//remove mary from the list
	cout << "Mary had to drop out, " << endl;
	cout << "Reprinting student records:" << endl;
	records.delet(&mary);
	records.display();//display records inserted thus far

}
