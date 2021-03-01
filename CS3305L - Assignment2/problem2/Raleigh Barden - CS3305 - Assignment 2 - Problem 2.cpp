/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 2 - Problem 2
*/


// Programming Projects #2 - Page 287 in Text
// Write a function that takes a linked list of items and deletes all repetitions from the list. 
// In your implementation, assume that items can be compared for equality using ==.


#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int in_data) { 
		data = in_data; 
		next = NULL;
	}
};
class Linked_List {
public: 
	Node* root;
	Linked_List() { root = NULL; }
	Linked_List(Node* in_node) { root = in_node; }
	void delete_dupes();
	void insert_node(Node*);
	void print_list();
};
void Linked_List::delete_dupes() {
	vector<int> list_items = {0};
	list_items.push_back(root->data);
	Node* current_node = root;
	while (current_node->next != NULL) {
		bool already_found = false;
		for (int item : list_items) {
			if (item == current_node->next->data) {
				already_found = true;
			}
		}
		if (already_found) {
			Node* temp = current_node->next->next;
			current_node->next = temp;
		}
		else {
			list_items.push_back(current_node->next->data);
			current_node = current_node->next;
		}
	}
}
void Linked_List::insert_node(Node* in_node) {
	Node* current_node = root;
	while (current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = in_node;
}
void Linked_List::print_list() {
	Node* current_node = root;
	string out = "| ";
	while (current_node != NULL) {
		out = out + to_string(current_node->data) + " | ";
		current_node = current_node->next;
	}
	cout << out << endl;
}
int main()
{
	Linked_List my_list = Linked_List(new Node(0));
	my_list.insert_node(new Node(1));
	my_list.insert_node(new Node(1));
	my_list.insert_node(new Node(2));
	my_list.insert_node(new Node(3));
	my_list.insert_node(new Node(3));
	my_list.insert_node(new Node(2));
	my_list.insert_node(new Node(3));
	my_list.insert_node(new Node(4));
	my_list.insert_node(new Node(5));

	cout << "List with duplicates: " << endl;
	my_list.print_list();

	cout << "List after removing duplicates: " << endl;
	my_list.delete_dupes();
	my_list.print_list();
}	
	
