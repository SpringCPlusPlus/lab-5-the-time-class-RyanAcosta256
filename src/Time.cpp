#include <iostream>
#include "../include/Time.h"
using namespace std;


/*
// Constructor
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // Getter functions (for testing)
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    


*/
/*
how to add: convert both to minutes and add them AND then convert the minutes to hours, min


*/

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalMinutes = (hours * 60 + minutes) + (other.hours * 60 + other.minutes);

    // Properly construct the Time object
    Time total(totalMinutes / 60, totalMinutes % 60);
    return total;
}



// Overload the += operator
Time& Time::operator+=(const Time &other) //this focuses on the left hand side of the equation
{   
    // Convert current object and other object to total minutes
    int totalMinutes = (hours * 60 + minutes) + (other.hours * 60 + other.minutes);
    
    // Update current object's hours and minutes
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;
    
    return *this;  // Return the modified object
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
   return (hours * 60 + minutes) < (other.getHours() * 60 + other.getMinutes());
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return (hours * 60 + minutes) > (other.getHours() * 60 + other.getMinutes());
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (hours * 60 + minutes) == (other.getHours() * 60 + other.getMinutes());

}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.getHours() << " hours " << tm.getMinutes() << " minutes";
    return os;
}
