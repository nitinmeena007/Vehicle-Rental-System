#ifndef error_cpp
#define error_cpp

// including standard cpp headers
#include<string>

using namespace std;

class Error {
        string message;
    public:
        Error(string message) {
            this->message = message;
        }

        string getMessage() const {
            return this->message;
        }
};

class NoSuchRecordError : public Error {
    public:
        // if the base class constructor requires one or more arguement, then it becomes necessary for
        // the derived class to have a constructor and pass the arguement to the base class constructor

        /*
            constructor (arglist) : initialization-section {
                assignment-section
            }
        */
        NoSuchRecordError() : Error ("No such record found") {};
};

class IOError : public Error {
    public:
        IOError() : Error("I/O Error could not open or process file make sure 'vehicles.txt', 'trips.txt' and 'users.txt' file exists in this directory") {}
};

class MemoryError : public Error {
    public:
        MemoryError() : Error("System out of Memory") {};
};

#endif