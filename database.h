#ifndef database_h
#define database_h

// include custom headers
#include "vehicle.h"
#include "user.h"
#include "trip.h"
#include "table.cpp"
#include "error.cpp"

using namespace std;

// this is a db class and acts as a middleware, so we can hide low-level details like file handling, add, update records, etc.
class Database {
        // Database have multiple tables
        
        Table<Vehicle> *vehicleTable;       // vehicle table
        Table<User> *userTable;             // user table
        Table<Trip> *tripTable;             // trip table

        // fetch all data from files 
        void fetchAllVehicles();
        void fetchAllUsers();
        void fetchAllTrips();

        void cleanUp();
    
    public:
        // constructor
        Database ();
        ~Database();

        // get references to db tables
        // all are constant pointers to constant objects. So, user can neither change pointer nor the data
        const Table<Vehicle> * const getVehicleRef() const;
        const Table<User> * const getUserRef() const;
        const Table<Trip> * const getTripRef() const;

        // query vehicle by 'registrationNo'
        const Vehicle * const getVehicle(string registrationNo) const;

        // query user by contact no.
        const User * const getUser(string contactNo) const;

        // find a vehicle of given type, which is available in a given duration 
        const vector<const Vehicle*> getVehicle(Date startDate, Date endDate, VehicleType type) const;

        // add new record of type T in database
        template <class T> void addNewRecord (T * record);

        // update record in database
        template <class T> void updateRecord (T * record);
};

#endif