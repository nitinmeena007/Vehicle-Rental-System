#ifndef table_h
#define table_h

// including custom headers
#include "storable.cpp"
#include "error.cpp"

// including standard cpp headers
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// This is templated (generic) class. It represents in-memory database table
// Table can be of type 'Vehicle', 'User', 'Trip'

template <class T> class Table {

        string fileName;        // name of database file
        fstream fileStream;     // file stream used to read and write data from db file

        // original data is stored here
        vector<Storable *> *records = NULL;

        // this is a private method
        // we will share pointer of record with recordId = 'recordId' 
        // this is intentional, hence it is kept as private method
        T * getReferenceOfRecordForId (long recordId) const;

        // this is a private function. It is called after inserting new record or updating data
        // this function writes data to a file
        void writeToFile();

        // add new record to db
        const T* const addNewRecord(T data);

        // update record in db
        void updateRecord(T updatedRecord);

    public:
        // constructor
        Table(string fileName);
        ~Table();

        // get 'recordId' for next record
        long getNextRecordId() const;

        // get record for particular 'recordId' 
        // it will return const T* const (constant pointer to constant record), so user cannot modify that record accidently
        const T* const getRecordForId(long recordId) const;

        // class db can use this class private methods and variables
        // we will use 'getReferenceRecordForId' to get actual record reference
        friend class Database;
};      


#endif