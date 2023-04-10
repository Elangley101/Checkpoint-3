
// YOUR NAME
// CIT 163 Checkpoint 3
// Time.h

#ifndef TIME
#define TIME 1

#include <iostream>
#include <iomanip>
#include <vector>

class Time {
private:
	// This stores the time as the number of minutes
	// since midnight. For example, 2:30 is stored
	// as 150, and  12:00 is stored as 720.
	int minutes_since_midnight;

	// Don't add any additional member variables. The goal
	// is to keep everything in one variable, and translate
	// to hours and minutes when the class methods are called

public:

	// Default constructor sets time to 0 minutes since midnight       
	Time();

	// Constructor sets time to 'min' minutes since midnight       
	// Makes sure the resulting time is between 00:00 and 23:59,             
	// inclusive  
	Time(int min);

	// Constructor sets time to 'hour' hours and 'min' minutes        
	// since midnight. 
	Time(int new_h, int new_m);

	// Accessors
	int getHours() const;
	int getMinutes() const;

	// Mutators --

	// YOUR CODE HERE - add declarations for setHours and setMinutes 
	void setMinutes(int new_min);
	void setHours(int new_hour);

	// Returns true if this time is the same as or
	// earlier in the day compared to the time in 't'
	bool isBefore(const Time& t);

	// Return the amount of time from this time to the
	// time in 't'.  If the time in 't' is earlier than this 
	//  time, then 't' is interpreted as a time the next day

	// YOUR CODE HERE - add the declaratoion for timeUntil
	Time timeUntil(const Time& t);

};

// Defined in main.cc
std::ostream& operator << (std::ostream& os, const Time& t);

// Defined in time.cc
Time earliest(std::vector<Time>& times);

#endif