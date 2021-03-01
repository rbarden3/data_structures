/*
* Class: CS 3305L/02
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Lab 4
*/

#include <iostream>
#include <list> 
#include <algorithm>
#include <string>
#include <conio.h>
using namespace std;

list <char> get_default_delimiters() { // function returns basic word end delimeters
	list <char> delimiters({ ' ','.',',','!','?' });
	return delimiters;
}

list <string> split(string in_string, list <char> delimeters = get_default_delimiters()) { // function Takes a list of delimiters and a string and splits the string into a list based off of those deliniators
	bool more_breaks = true;
	list <string> sentance;
	while(more_breaks){ // loop will continue while there are more places to break the in_string

		size_t closest_delim_pos = in_string.find(delimeters.front()); //declare the closest delimiter position as the position in the in_string of the first delimiter in the list
		size_t delim_pos;
		for (char delim : delimeters) { //finds the nearest delimiter out of the list provided
			delim_pos = in_string.find(delim);
			if (delim_pos < closest_delim_pos) {
				closest_delim_pos = delim_pos;
			}
		}


		if (closest_delim_pos != std::string::npos) { //checks to make sure a delimiter was found in the in_string
			string found_word = in_string.substr(0, closest_delim_pos);
			size_t word_pos = in_string.find(found_word);
			if (found_word != "") { //prevents blank strings from being added
				sentance.push_back(found_word); // push the word to the sentance list
			}
			in_string.erase(word_pos, found_word.length()+1); //remove the word from the in_string, 1 is added to the word length to also remove the delimiter

		}
		else {
			if (in_string.length() > 0) { //if the in_string does not end in a delimiter, the final word needs to be added
				sentance.push_back(in_string);
			}
			more_breaks = false; // break the loop
		}
	}

	return sentance;
}

bool is_wbw_palindrome(string sentance) {
	
	list <string> split_sentance = split(sentance);
	list <string> reversed_sentance;
	std::for_each(split_sentance.begin(), split_sentance.end(), [](string & word) { // loops through each word and then each letter converting all to lower
		std::for_each(word.begin(), word.end(), [](char & c) {
			c = ::tolower(c);
			});
		});
	int length = 0; // get length of lists while creating new list
	for (string word : split_sentance) { // adds each item in reverse order to a new list
		reversed_sentance.push_front(word);
		length += 1;
	}
	
	bool rtn = true; // default return to true
	std::list<std::string>::iterator split_it = split_sentance.begin(); //create iterators to compare lists
	std::list<std::string>::iterator rev_it = reversed_sentance.begin();
	for (int i = 0; i < length; i++) { // do for every word in the list

		if (*split_it == *rev_it) {
			// the return variable is defaulted to true
			// true should never be reset, since if one set of words do not match, the sentance is not a word by word palindrome
		}
		else {
			rtn = false; // the return variable must be set to false if the words do not match eachother
		}
		if (i != length - 1) { //prevents loop from removing last item in list
			std::advance(split_it, 1); //advance the iterator
			std::advance(rev_it, 1);
		}
	}
	return rtn;
}

int main()
{
	string exit_con = "";
	cout << "Hello, welcome to the word-by-word palindrome tester!" << endl;
	
	while (exit_con.compare("q") != 0){
		cout << "Please enter a sentance string you would like to test." << endl;
		string input;
		std::getline(std::cin, input); // Get user input
		cout << input << endl;

		bool is_pal = is_wbw_palindrome(input);// test whether sentence is a palindrome

		if (is_pal) {// output whether sentence is a palindrome
			cout << "Sentence is a palindrome " << endl;
		}
		else {
			cout << "Sentence is not a palindrome " << endl;
		}
		cout << "Press 'Q' to quit, or any other key to test a new sentance" << endl;// end process if user inputs a q
		std::getline(std::cin, exit_con);
	} 
	
}

