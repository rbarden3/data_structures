/*
* Class: CS3305L
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Lab 6
*/

#include <iostream>
#include <string>
using namespace std;
struct Person {
	string name;
	int phone_no;
	string email;
	Person* lchild;
	Person* rchild;
	string get_data();
	Person() {}
	Person(string name, int phone_no, string email){
		this->name = name;
		this->phone_no = phone_no;
		this->email = email;
		this->lchild = NULL;
		this->rchild = NULL;
		
	}
};
class BST {
private:
	Person* root;
	void insert(Person* in_person, Person*);
	void delet(string name, Person* leaf);
public:
	BST() { root = new Person; }
	BST(string name, int phone_no, string email);
	Person* get_root() { return root; }
	int count_children(Person*);
	void insert_node(Person*);
	void delete_node(string);
	void display(Person*, bool);
};

// Constructor initializes the BST
BST::BST(string name, int phone_no, string email) {
	root = new Person;
	root->name = name;
	root->phone_no = phone_no;
	root->email = email;
	root->lchild = NULL;
	root->rchild = NULL;
}
string Person::get_data() {
	string data = "Name:\t\t" + name + "\nPhone Number:\t" + to_string(phone_no) + "\nEmail:\t\t" + email;
	return data;
}
int BST::count_children(Person* in_person) {
	int rtn = 0;
	if (in_person != NULL) {
		if (in_person->lchild != NULL)
			rtn += 1 + count_children(in_person->lchild);
		else {
			rtn += 0;
		}
		if (in_person->rchild != NULL)
			rtn += 1 + count_children(in_person->rchild);
		else {
			rtn += 0;
		}
		return rtn;
	}
	else {
		return 0;
	}
}

void BST::insert(Person* in_person, Person* leaf) {
	string key = in_person->name; // set the key to be the persons name so that we sort in alphabetical order
	if (key < leaf->name) { // if the person is lower in alphabetical order
		if (leaf->lchild != NULL)
			insert(in_person, leaf->lchild);
		else {
			leaf->lchild = new Person; // insert the person into its place on the tree
			leaf->lchild->name = in_person->name;
			leaf->lchild->phone_no = in_person->phone_no;
			leaf->lchild->email = in_person->email;
			leaf->lchild->lchild = in_person->lchild;
			leaf->lchild->rchild = in_person->rchild;
		}
	}
	else if (key > leaf->name) { //else if the person is higher in alphabetical order
		if (leaf->rchild != NULL)
			insert(in_person, leaf->rchild); 
		else {
			leaf->rchild = new Person; // insert the person into its place on the tree
			leaf->rchild->name = in_person->name;
			leaf->rchild->phone_no = in_person->phone_no;
			leaf->rchild->email = in_person->email;
			leaf->rchild->lchild = in_person->lchild;
			leaf->rchild->rchild = in_person->rchild;
		}
	}
}

void BST::insert_node(Person* in_person) {
	if (root != NULL) {
		insert(in_person, root);
	}
	else {
		root = new Person;
		root->name = in_person->name;
		root->phone_no = in_person->phone_no;
		root->email = in_person->email;
		root->lchild = in_person->lchild;
		root->rchild = in_person->rchild;
	}
}

void BST::delet(string key, Person* leaf) {

	if (key < leaf->name) { // if the person is lower in alphabetical order
		if (leaf->lchild->name == key) {
			Person* parent_lchild = leaf->lchild->lchild;
			Person* parent_rchild = leaf->lchild->rchild;

			// Need to make sure not to insert null pointers
			if (parent_lchild != NULL || parent_rchild != NULL) {
				if (count_children(parent_lchild) > count_children(parent_rchild)) { // if the left child has more children, make it the new root
					//leaf->lchild = NULL;
					leaf->lchild = parent_lchild;
					if (parent_rchild != NULL) {
						insert_node(parent_rchild);// the right child needs to be reinserted into the tree
					}
				}
				else {
					//leaf->rchild = NULL;
					leaf->lchild = parent_rchild; // otherwise, replace the deleted value with the right child.
					if (parent_lchild != NULL) {
						insert_node(parent_lchild);// the left child needs to be reinserted into the tree
					}
				}
			}
			else {
				leaf->lchild = NULL;// if both children are null, place null in the location of the deleted node
			}
		} else if (leaf->lchild != NULL) {
			delet(key, leaf->lchild);
		} else {
			cout << "Selected Key Not Found" << endl;
			return;
		}
	}
	else if (key > leaf->name) { //else if the person is higher in alphabetical order
		if (leaf->rchild->name == key) {
			Person* parent_lchild = leaf->rchild->lchild;
			Person* parent_rchild = leaf->rchild->rchild;

			// Need to make sure not to insert null pointers
			if (parent_lchild != NULL || parent_rchild != NULL) {
				if (count_children(parent_lchild) > count_children(parent_rchild)) { // if the left child has more children, make it the new root
					//leaf->rchild = NULL;
					leaf->rchild = parent_lchild;
					if (parent_rchild != NULL) {
						insert_node(parent_rchild);// the right child needs to be reinserted into the tree
					}
				}
				else {
					//leaf->rchild = NULL;
					leaf->rchild = parent_rchild; // otherwise, replace the deleted value with the right child.
					if (parent_lchild != NULL) {
						insert_node(parent_lchild);// the left child needs to be reinserted into the tree
					}
				}
			}
			else {
				leaf->rchild = NULL; // if both children are null, place null in the location of the deleted node
			}
		} else if (leaf->rchild != NULL) {
			delet(key, leaf->rchild);
		} else {
			cout << "Selected Key Not Found" << endl;
			return;
		}
	}
}

void BST::delete_node(string key) {
	if (root == NULL) {
		cout << "The Tree Is Empty: Nothing to Delete." << endl; // Output message stating tree is empty if the root is null
	} else if (root->name != key) {
		delet(key, root); // if the root is not a match, begin the recursive process
	} else { // if the root is a match: reinsert all into array
		Person* root_lchild = root->lchild;
		Person* root_rchild = root->rchild;

		// Need to make sure not to insert null pointers
		if (root_lchild != NULL || root_rchild != NULL) { 
			if (count_children(root_lchild) > count_children(root_rchild)) { // if the left child has more children, make it the new root
				root = root_lchild;
				if (root_rchild != NULL) {
					insert_node(root_rchild);// the right child needs to be reinserted into the tree
				}
			}
			else {
				root = root_rchild; // otherwise, make the right child the new tree root.
				if (root_lchild != NULL) {
					insert_node(root_lchild);// the left child needs to be reinserted into the tree
				}
			}
		}
		else {
			root = NULL;
		}
	}
}

void BST::display(Person* par, bool children = false) { // children boolean allows the user to see the children and parents of nodes in the tree
	if (par == NULL) return;
	cout << "-------+-------+-------+-------+" << "\n";
	cout << par->get_data() << endl;
	if (children) {
		cout << "\nLeft Child:" << endl;
	}
	display(par->lchild, children);
	if (children) {
		cout << "\nRight Child:" << endl;
	}
	display(par->rchild, children);
	return;
}


int main() {

	if ("Mary" < "Sue") {
		cout << "Mary is Less than Sue" << endl;
	}
	else if ("Mary" > "Sue") {
		cout << "Mary is Greater than than Sue" << endl;
	}
	else {
		cout << "Mary is Equal to Sue" << endl;
	}

	cout << "Create Tree with Person 'John' and display:" << endl; // demonstrate Tree Creation
	BST tree = BST("John", 0001113333, "j@j.com");
	tree.display(tree.get_root());

	cout << "\nInsert Person 'Bill' and display:" << endl; // Demonstrate ability to add nodes
	tree.insert_node(new Person("Bill", 0001114444, "b@email.com"));
	tree.display(tree.get_root());

	cout << "\nInsert Persons 'Jim', 'Mary', 'Sue', 'Al', and Zack and display:" << endl; // Demonstrate adding multiple new nodes
	tree.insert_node(new Person("Jim", 0001115555, "Jimmy@email.com"));
	tree.insert_node(new Person("Mary", 0001116666, "Lamb@email.com"));
	tree.insert_node(new Person("Sue", 0001117777, "Sue@email.com"));
	tree.insert_node(new Person("Al", 0002221111, "Al@email.com"));
	tree.insert_node(new Person("Zack", 0002221111, "Zman@email.com"));
	tree.display(tree.get_root(), false);

	cout << "\nCount Children of John: " << to_string(tree.count_children(tree.get_root())) << endl; //demonstrate counting all children of an object

	cout << "\nCurrent Root: " << tree.get_root()->name << endl;// demonstrate deleting the root node
	cout << "\nDelete Current Root:" << endl;
	tree.delete_node(tree.get_root()->name);
	cout << "\nNew Root: " << tree.get_root()->name << endl;

	cout << "\nDelete 'Sue' and display:" << endl; // Demonstrate deleting nodes
	tree.delete_node("Sue");
	tree.display(tree.get_root(), true);
}
