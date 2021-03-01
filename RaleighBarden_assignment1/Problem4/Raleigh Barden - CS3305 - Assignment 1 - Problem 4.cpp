/*
* Class: CS3305
* Term: Summer 2020
* Name:  Raleigh Barden
* Instructor: Ephina Thendral S
* Assignment: Assignment 1 - Problem 4
*/


// Section 2.3 (Text page 62) - #19:
// Design and implement a class called clock. A clock object holds one 
// instance of a time value such as 9 :48 P.M. Have at least these public member functions :
//		• A default constructor that sets the time to midnight
//		• A function to explicitly assign a given time(you will have to give
//		  some thought to appropriate parameters for this function)
//		• Functions to retrieve information : the current hour, the current
//		  minute, and a boolean function to determine whether the time is at or
//		  before noon
//		• A function to advance the time forward by a given number of minutes

#include <iostream>
#include <string>
#include <cassert>
#include <regex>
using namespace std;
class Clock {
private: 
	string time; // time in 24 hour format as a string (HH:MM)
public:
	Clock() { time = "00:00"; };
	string get_time() { return time; }
	string get_time_12hr();
	bool valid_time(string); //returns whether an entered time is valid
	void set_time(string);
	string get_hours();
	string get_minutes();
	bool before_noon();
	void add_minutes(int);
	
	
};
bool Clock::before_noon() {
	if (stoi(get_hours()) >= 12) {
		return false;
	}
	else {
		return true;
	}
}
string Clock::get_time_12hr() {
	int hrs = stoi(get_hours()); 
	string period;
	if (before_noon()){
		period = " A.M.";
	}
	else {
		hrs = hrs - 12;
		period = " P.M.";
	}
	if (hrs == 0) {// 00:00 is always 12:00 in 12 hour format
		hrs = 12;
	}

	return (to_string(hrs) + ":" + get_minutes() + period +"\n");
}
bool Clock::valid_time(string in_time) { // Checks that time is given in HH:MM Format
	bool rtn = true; // declare default return as true
	regex reg("^[0-9]{2}[:][0-9]{2}$"); //Regex Expression checking for form ##:##
	if (!regex_match(in_time, reg)) {
		rtn = false;
	}

	int hrs = stoi(get_hours()); // stoi converts from string to int
	int mins = stoi(get_minutes());
	if (!(hrs >= 0 && hrs <= 23)) { // hrs must be greater than or equal to 0 and less than or equal to 23
		rtn = false;
	}
	if (!(hrs >= 0 && hrs <= 60)) { // mins must be greater than or equal to 0 and less than or equal to 60
		rtn = false;
	}
	return rtn;
}
string Clock::get_hours() {
	return time.substr(0, 2);	// since time is a string in 24 hour, HH:MM format, indexs 1 and 2 are the hour value. 
}
string Clock::get_minutes() {
	return time.substr(3, 5); // since time is a string in 24 hour, HH:MM format, indexs 3 and 4 are the minute value.
	//return stoi(time.substr(3,5)); // stoi converts from string to int
}
void Clock::set_time(string in_time) {
	assert(valid_time(in_time)); // Precondition: time must be a valid time in HH:MM Format
	time = in_time; // set the clock time to the input
}
void Clock::add_minutes(int add_mins) {
	assert(add_mins > 0); //Precondition: mins to add is greater than 0; 
	int hrs = stoi(get_hours());
	int mins = stoi(get_minutes());
	int days = 0; //will hold values, but wont be used for anything as of now
	mins += add_mins;
	while (mins > 59) { // convert 60 minute groups into 1 hour
		hrs += 1;
		mins -= 60;
	}
	while (hrs > 23) {// convert 24 hour groups into 1 day
		days += 1;
		hrs -= 24;
	}
	string new_hrs = to_string(hrs); // convert values back to strings
	string new_mins = to_string(mins);

	if (hrs < 10) { // if the new strings are single digits, they need to be converted to double digit format
		new_hrs = "0" + new_hrs;
	}
	if (mins < 10) {
		new_mins = "0" + new_mins;
	}
	time = new_hrs + ":" + new_mins;
}

int main()
{
	// demonstrate ability to create a clock
	cout << "Create clock and output default time:" << endl;
	Clock main_clock = Clock();
	cout << "Time in 24-hour format: " << main_clock.get_time() << endl;
	cout << "Time in 12-hour format: " << main_clock.get_time_12hr() << "\n" << endl;

	//demonstrate ability to set time
	cout << "Set time to (05:31) and output time:" << endl;
	main_clock.set_time("05:31");
	cout << "Time in 24-hour format: " << main_clock.get_time() << endl;
	cout << "Time in 12-hour format: " << main_clock.get_time_12hr() << "\n" << endl;

	// demonstrate ability to get hours and minuites and check if after noon
	cout << "Get the current hour: " << main_clock.get_hours() << endl;
	cout << "Get the current minutes: " << main_clock.get_minutes() << endl;
	
	string noon; // convert bool to string for output
	if (main_clock.before_noon()) { noon = "Yes"; } else { noon = "No"; }
	cout << "Is it Before Noon?: " << noon << endl;

	// demonstrate ability to advance time by a set amount of minutes
	cout << "Add 60 Minutes to Clock:" << endl;
	main_clock.add_minutes(60);
	cout << "Time in 24-hour format: " << main_clock.get_time() << endl;
	cout << "Time in 12-hour format: " << main_clock.get_time_12hr() << "\n" << endl;

	cout << "Add 137 Minutes to Clock:" << endl;
	main_clock.add_minutes(137);
	cout << "Time in 24-hour format: " << main_clock.get_time() << endl;
	cout << "Time in 12-hour format: " << main_clock.get_time_12hr() << "\n" << endl;

	cout << "Add 1024 Minutes to Clock:" << endl;
	main_clock.add_minutes(860a);
	cout << "Time in 24-hour format: " << main_clock.get_time() << endl;
	cout << "Time in 12-hour format: " << main_clock.get_time_12hr() << "\n" << endl;
}

