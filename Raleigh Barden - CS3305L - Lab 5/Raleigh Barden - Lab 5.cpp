/*
* Class: CS3305L
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Lab 5
*/



// Program 5.1
// Implement a C++ class for complete binary tree using the array representation.The C++ class contains a
// constructor that initializes the binary tree, a member function that adds a new node and another
// member function that removes the last node of the tree.Validate this C++ class with the main() function.


#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class BinaryTree {
public:
	BinaryTree(int);
	void fill();
	int get_treeLen();
	int get_last_parent();
	string get_node(int);
	void print_tree();
	int get_node_level(int);
	void print_children(int);
	void add_node(string, int, bool);
	void delete_node(int);
	void delete_last();
	void clear_tree();
	
private:
	string* tree;
	int length;
	int current_height;
	
};

BinaryTree::BinaryTree(int height) { // parameters in constructor are the height of the tree
	current_height = height;
	int array_size = 2; // Array_size is initially set to 2 to account for the unused 0 index and the root node at the 1 index
	while (height > 1) { // Number of possible nodes for a Full Binary Tree with the specified Height
		array_size += (int)pow(2, height - 1);
		height = height - 1;
	}

	length = array_size; // set the length of the array to obtain easily in the future
	tree = new string[array_size]; // initialize the tree
}

int BinaryTree::get_treeLen() {	return length; }
int BinaryTree::get_last_parent() { return (length - 2) / 2; }
string BinaryTree::get_node(int index) { return tree[index]; }

void BinaryTree::print_tree() { //Prints out the values of the tree array
	for (int i = 1; i < get_treeLen(); i++) {
		cout << get_node(i) << " | ";
	}
	cout << endl;
}

void BinaryTree::print_children(int parent) { // Prints a visualization of the selected node and its children
	if (parent > length) {
		cout << "This Node is outside of the range of the graph" << endl;
	} else if (parent > get_last_parent()) {
		cout << "This Node is not a Parent Node" << endl;
	}
	else {
		cout << "\n\t\t" << get_node(parent) << endl;
		cout << "\t      /\t  \\"  << endl;
		cout << "\t    " << get_node((2*parent)+1) << "\t    " << get_node((2 * parent)) << endl;
	}
}

void BinaryTree::fill() { //fills the tree with its corresponding node values
	for (int i = 1; i <= get_last_parent(); i++) {
		tree[i] = to_string(i);
		tree[2*i] = to_string(2 * i);
		tree[(2*i)+1] = to_string((2 * i) + 1);
	}
}

int BinaryTree::get_node_level(int node) { // returns the level of the selected node
	int array_size = 2; 
	int level = 1;
	while (node >= array_size) { // checks each level to see if the last node is greater than the node being searched for
		array_size += (int)pow(2, level);
		level = level + 1;
		//cout << "Height: " << level << "\tArray Size: " << array_size << endl;
	}
	return level;
}
void BinaryTree::add_node(string value, int parent, bool left) { // adds a node at as either the left or right child of the selected parent node
	if( parent >= length || get_node(parent).empty()) { // do not add child node if there is no parent node
		cout << "The parent node does not exist" << endl;
	} else {
		
		if (parent > get_last_parent()) { // if the attempted parent is not a current parent node (There are not indexs for child nodes)
			current_height = current_height + 1; // tree has to be recreated
			int height = current_height;
			int array_size = 2; // Array_size is initially set to 2 to account for the unused 0 index and the root node at the 1 index
			while (height > 1) { // Number of possible nodes for a Full Binary Tree with the specified Height
				array_size += (int)pow(2, height - 1);
				height = height - 1;
			}

			string* temp_tree = new string[length];
			//copy(begin(*tree), end(*tree), begin(*temp_tree));
			for (int i = 1; i < length; i++) {
				temp_tree[i] = tree[i];
			}
			cout << endl;
			tree = new string[array_size]; // initialize the tree with the new length
			for (int i = 1; i < length; i++) { // adds the previous values back into the tree
				tree[i] = temp_tree[i];
			}
			length = array_size;

		}
		if ((left && !get_node((2 * parent) + 1).empty()) || (!left && !get_node(2 * parent).empty())) { //checks to make sure a node is not being overridded
			cout << "There is already a node in the selected position" << endl;
		}
		else {
			if (left) { // checks if the node being added is the left child or right child
				tree[(2 * parent) + 1] = value; // set the left child to the value
			}
			else {
				tree[2 * parent] = value; //set the right child to the value
			}
		}
	}
}
void BinaryTree::delete_node(int node) {
	if ( node >= length || get_node(node).empty()) { // Make sure Node exists
		cout << "The target node does not exist" << endl;
	}
	else { // if the node exists...
		tree[node].clear(); // ...remove it
	}
}
void BinaryTree::delete_last() { //deletes the last node in the tree
	int last_node = 0; // 0 is the default value since there will never be a node at location 0
	for (int i = 1; i < get_treeLen(); i++) {
		if (!tree[i].empty()) { //if the node at index i is not empty, it becomes the last node
			last_node = i;
		}
	}
	if (last_node == 0) { // if the last_node is still the default, there was no nodes in the array
		cout << "\nNo Nodes in Tree" << endl;
	}
	else {
		tree[last_node].clear();
	}
}
void BinaryTree::clear_tree() { // clears all nodes from the tree
	for (int i = 1; i < get_treeLen(); i++) {
		tree[i].clear();
	}
}


int main() // Main Function
{
	cout << "Create a Tree with a height of 4." << endl;
	BinaryTree mainTree = BinaryTree(4);

	cout << "\nLength of Array: " << endl;
	cout << mainTree.get_treeLen() << endl;

	cout << "\nInitial Tree Values:" << endl;
	mainTree.print_tree();

	cout << "\nFill Tree with Node Values:" << endl;
	mainTree.fill();
	mainTree.print_tree();

	cout << "\nPrint the Children of Node 7:" << endl;
	mainTree.print_children(7);
	cout << endl;

	cout << "\nAdd Value 'a' as the left child of node 15." << endl;
	mainTree.add_node("a", 15, true);
	cout << "\nValues in Tree after adding child:" << endl;
	mainTree.print_tree();

	cout << "\nAdd Value 'b' as the right child of node 15." << endl;
	mainTree.add_node("b", 15, false);
	cout << "\nValues in Tree after adding child:" << endl;
	mainTree.print_tree();

	cout << "\nAdd Value 'c' as the right child of node 14." << endl;
	mainTree.add_node("c", 14, false);
	cout << "\nValues in Tree after adding child:" << endl;
	mainTree.print_tree();

	cout << "\nAttempt to add a node to a parent that does not exist: " << endl;
	mainTree.add_node("a", 125, true);

	cout << "\nAttempt to add a node where there already is a node: " << endl;
	mainTree.add_node("a", 4, true);

	cout << "\nDelete last node from tree: " << endl;
	mainTree.delete_last();
	mainTree.print_tree();

	cout << "\nDelete a node that does not exist: " << endl;
	mainTree.delete_node(17);

	cout << "\nDelete node 28 (The node we added c to earlier):" << endl;
	mainTree.delete_node(28);
	mainTree.print_tree();

	cout << "\nFinally, Delete all nodes from the tree:" << endl;
	mainTree.clear_tree();
	mainTree.print_tree();
}