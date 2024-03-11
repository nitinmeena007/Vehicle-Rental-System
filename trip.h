#ifndef trip_h
#define trip_h

// including custom headers
#include "date.h"
#include "storable.cpp"
#include "user.h"
#include "vehicle.h"

// including standard cpp headers
#include <string>

using namespace std;

// Trip class which helps to manage trip-related data
class Trip : public Storable {
    
        // const pointer to constant vehicle in memory
        // we will create vehicle in memory and assign address of that vehicle to 'vehicle'
        // this is a constant pointer so it cannot point to other vehicle object
        const Vehicle* vehicle;
        const User* user;

        // we need to track record of start and end date of the trip so that at the time
        // of booking a trip we can find vehicles that are free in that specific duration
        Date startDate;
        Date endDate;

        // we also need to keep track of reading of Odometer so that fare can be calculated
        long startReading;
        long endReading;

        // fare of this trip
        double fare;

        // trip is completed or not
        bool completed;

    public:
        // constructor
        Trip(const Vehicle *vehicle, const User* user, Date startDate, Date endDate, long recordId = 0, long startReading = 0, long endReading = 0, double fare = 0.0, bool isCompleted = false);

        // getter methods
        const User & getUser() const;
        const Vehicle & getVehicle() const;
        Date getStartDate() const;
        Date getEndDate() const;
        long getStartReading() const;
        long getEndReading() const;
        long getFare() const;
        bool isCompleted() const;

        // start trip
        void startTrip(long startReading);

        // complete trip
        double completeTrip(long endReading);

        // display record on screen 
        void display() const;

        // overriden virtual method
        string toString() const;
        void setDataFrom(Storable *s);
};

#endif