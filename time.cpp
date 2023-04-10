#include "time.h"

// Default constructor sets time to 0 minutes since midnight
Time::Time() {
    minutes_since_midnight = 0;
}

// Constructor sets time to 'min' minutes since midnight
// Makes sure the resulting time is between 00:00 and 23:59,
// inclusive
Time::Time(int min) {
	if (min >= 0 && min <= 1439) {
		minutes_since_midnight = min;
	}
	else
	{
		minutes_since_midnight = 0;
	}
}

// Constructor sets time to 'hour' hours and 'min' minutes
// since midnight.

Time::Time(int hour, int min) {
    minutes_since_midnight = hour * 60 + min;
}

// Accessor. You don't need to edit this.
// The 'const' lets it be applied to an object of
// type 'const Time'
int Time::getHours() const {
	return (int)((minutes_since_midnight)/60);
}

// Accessor. You don't need to edit this.
// The 'const' lets it be applied to an object of
// type 'const Time'
int Time::getMinutes() const {
	int hours = getHours();
	int minutes=((minutes_since_midnight)- hours*60);
	return minutes;
}

// Mutator. If the time is currently hour:min,
// changes it to new_hour:min without changing
// the number of minutes past the hour
void Time::setHours(int new_hour) {
	int minutes = getMinutes();
	minutes_since_midnight = new_hour * 60 + minutes;
}

// Mutator. If the time is currently hour:min,
// changes it to hour:new_min without changing
// the number of hours, just the minutes portion
void Time::setMinutes(int new_min) {
	int hours=getHours();
	minutes_since_midnight = hours * 60 + new_min;
}

// Returns true if this time is the same as or  
// earlier in the day compared to the time in 't'
bool Time::isBefore(const Time& t) {
    return minutes_since_midnight <= t.minutes_since_midnight;
}

// Return the amount of time from this time to the
// time in 't'.  If the time in 't' is earlier than this
// time, then 't' is interpreted as a time the next day
Time Time::timeUntil(const Time& t) {
	Time new_time= t.minutes_since_midnight-minutes_since_midnight;
	if (!isBefore(t)) {
		new_time = 1440-(minutes_since_midnight - t.minutes_since_midnight);
	}
	return new_time;
}
// Return the earliest time from the times in the vector
Time earliest(std::vector<Time>& times) {
	Time earliest_time =times[0];
	for (int i = 1; i < times.size(); i++) {
		if (times[i].isBefore(earliest_time)) {
			earliest_time = times[i];
		}
	}
	return earliest_time;
}
