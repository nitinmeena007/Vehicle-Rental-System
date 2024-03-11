#ifndef date_h
#define date_h

// including custom headers
#include "storable.cpp"

// including standard cpp headers
#include <ctime>
#include <string>

using namespace std;

typedef struct Date : Serializable {
    private:
        // struct tm is a structure defined in the time.h in C language
        // It contains the time and date stored on a machine
        struct tm date;
        bool empty;
    public:
        // create date from string
        Date(string date);

        //create date from current time
        Date();

        // Add given number of days in this date
        Date operator + (int days);

        // If this date is greater than given date
        bool operator > (Date date) const;

        // If this date is greater than or equal to given date
        bool operator >= (Date date) const;

        // If this date is less than given date
        bool operator < (Date date) const;

        // If this date is less than or equal to given date
        bool operator <= (Date date) const;

        bool isEmpty() const;

        string toString() const;
} Date;

#endif