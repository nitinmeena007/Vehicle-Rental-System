#ifndef storable_cpp
#define storable_cpp

// Including custom headers
#include "serializable.cpp"

// Including standard cpp headers
#include<string>
#include<iostream>

using namespace std;

class Storable : public Serializable {
    protected:
        // unique recordID which acts as a primary key to find data
        // only derived class can access it directly
        long recordId;

    public:
        Storable(long recordId){
            this->recordId = recordId;
        }

        long getRecordId() const {
            return this->recordId;
        }

        // pure virtual function 
        // also it is similar to copy constructor
        virtual void setDataFrom(Storable *s) = 0;

        // friend class means if all the member function of a class is friend of the another class
        // table and database can access to private member of this class 
        template<class T> friend class Table;

        friend class Database;
};

#endif