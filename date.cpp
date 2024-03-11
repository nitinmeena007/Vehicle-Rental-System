// including custom headers
#include "date.h"
#include "string_helper.h"

const char DELIMITER = '/';

// mktime() ----> converts the broken-down time into a calender time value
// time() ------> determines the current calender time
// localtime() -> converts the calender time into a broken down time, returns a pointer to that object

Date :: Date () {
    // create date from current time
    time_t now = time(NULL);  
    this->empty = false;
    this->date = *localtime(&now);
}

Date :: Date(string date /* date must be in d/m/yyyy */) {

    if(date.length()<8){
        this->empty = true;
        return;
    }
    this->empty = false;

    // split string with given delimiter
    vector<string> dateComponents = split(date,DELIMITER);

    // separate out components

    int day = stoi(dateComponents[0]);
    int month = stoi(dateComponents[1]);
    int year = stoi(dateComponents[2]);

    time_t now = time(NULL);
    this->date = *localtime(&now);

    this->date.tm_year = year - 1900;
    this->date.tm_mon = month - 1;
    this->date.tm_mday = day;

    mktime(&this->date);
}

bool Date :: isEmpty () const {
    return this->empty;
}

string Date :: toString () const {
    if(this->empty){
        return "";
    }

    stringstream ss;
    ss << this->date.tm_mday << "/" << this->date.tm_mon + 1 << "/" << this->date.tm_year + 1900;

    return ss.str();
}

Date Date :: operator+ (int days) {
    // Create a new date
    Date newDate = *this;

    if(newDate.isEmpty()){
        return newDate;
    }

    // Modify days
    newDate.date.tm_mday += days;

    // Create modified date
    time_t adjustedDate = mktime(&newDate.date);

    // convert time to struct
    newDate.date = *localtime(&adjustedDate);    // returns a type of struct tm

    return newDate;
}

bool Date :: operator> (Date date) const {
    if(this->isEmpty() || date.isEmpty()){
        false;
    }
    
    int yearDiff = this->date.tm_year - date.date.tm_year;
    int monthDiff = this->date.tm_mon - date.date.tm_mon;
    int dayDiff = this->date.tm_mday - date.date.tm_mday;

    if(yearDiff!=0){
        return yearDiff > 0;
    }else if(monthDiff!=0){
        return monthDiff > 0;
    }else{
        return dayDiff > 0;
    }
}

bool Date :: operator>= (Date date) const {
    return !(*this < date);
}

bool Date :: operator< (Date date) const {
    if(this->isEmpty() || date.isEmpty()){
        false;
    }
    
    int yearDiff = this->date.tm_year - date.date.tm_year;
    int monthDiff = this->date.tm_mon - date.date.tm_mon;
    int dayDiff = this->date.tm_mday - date.date.tm_mday;

    if(yearDiff!=0){
        return yearDiff < 0;
    }else if(monthDiff!=0){
        return monthDiff < 0;
    }else{
        return dayDiff < 0;
    }
}

bool Date :: operator<= (Date date) const {
    return !(*this > date);
}