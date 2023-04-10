// YOUR NAME HERE
// CIT 163 Fall 2020
//
// This program creates a class to store a time from 00:00 to 23:59
// The time is stored internally as the number of minutes since midnight
//
// The program inputs two times, tells how long it is from the first
// time to the second time, and then tell how long it is from the second
// time to the first time
//
// Then the program inputs five times and tells which of the five
// was the earliest

#include <iostream>
#include "time.h"  

// This function is implemented in time.cc
// Given a vector of times, return the earliest one
Time earliest(std::vector<Time>& times);

// This will let us send this class to cout with << . 
// You don't need to edit this function
std::ostream& operator << (std::ostream& os, const Time& t) {
    os << std::fixed << std::setfill('0') << std::setw(2);
    os << t.getHours() << ":";
    os << std::fixed << std::setfill('0') << std::setw(2);
    os << t.getMinutes();
    return os;
}

// Please don't edit this "main" function
// You can use it to see how the class "Time" should work.

int main() {

    int h;
    int m;
    std::cout << "Enter a number of hours from 0 to 23, inclusive: ";
    std::cout << std::endl;
    std::cin >> h;
    std::cout << "Enter a number of minutes from 0 to 59, inclusive: ";
    std::cout << std::endl;
    std::cin >> m;

    Time c1; // Calls the Time() constructor
    c1.setHours(h);
    c1.setMinutes(m);

    std::cout << "Enter a second number of hours from 0 to 23, inclusive: ";
    std::cout << std::endl;
    std::cin >> h;
    std::cout << "Enter a second number of minutes from 0 to 59, inclusive: ";
    std::cout << std::endl;
    std::cin >> m;

    Time c2(h, m);  // Calls the Time(h.m) constructor

    std::cout << "Time 1: " << c1 << std::endl;
    std::cout << "Time 2: " << c2 << std::endl;

    Time c3 = c1.timeUntil(c2);

    std::cout << "Duration from time 1 to time 2: " << c3 << std::endl;

    c3 = c2.timeUntil(c1);

    std::cout << "Duration from time 2 to time 1: " << c3 << std::endl;

    std::vector<Time> myTimes;

    std::cout << "Enter five times by entering the hour and minute"
        << std::endl
        << "for each time." << std::endl;
    for (int i = 0; i <=5; i++) {
        std::cin >> h;
        std::cin >> m;
        myTimes.push_back({ h,m }); // Calls the constuctor Time(h,m)
    }
    for (int i = 0; i < 5; i++) {
        std::cout << "Time " << i << " " << myTimes.at(i) << std::endl;
    }

    std::cout << "Earliest time: " << earliest(myTimes) << std::endl;
}