#ifndef vehicle_h
#define vehicle_h

// including custom headers
#include "date.h"
#include "storable.cpp"

// including standard cpp headers
#include <string>

using namespace std;

// Support for different kinds of vehicles for different purposes

typedef enum { bike = 1, car = 2, truck = 3 } VehicleType;

// vehicle class which helps to manage vehicle-related data

class Vehicle : public Storable {

        string registrationNumber;  // registration number given by RTO
        VehicleType type;           // type of vehicle given by 'VehicleType' enum
        int seats;                  // no. of seats this vehicle has
        string companyName;         // name of vehicle manufacturer
        double pricePerKm;          // each vehicle has different price per km (this will be required to calculate fare when trip ends)
        Date PUCExpirationDate;     // this is the date when PUC will expire

    public:
        // constructor
        Vehicle (string registrationNumber, VehicleType type, int seats, 
        string companyName, double pricePerKm, Date PUCExpirationDate, long recordId = 0);

        // Getter methods with const attribute i.e. This method is not changing any data of the current object
        // If this method is not marked as constant, then it cannot be called from constant object of this class
        // Following snippet will give an error if 'getRegistrationNumber' is not marked with const keyword
        /*
            const Vehicle *object = new Vehicle(...);
            auto registrationNo = object->getRegistrationNumber();
        */

        string getRegistrationNumber() const;
        VehicleType getVehicleType() const;
        string getVehicleTypeName() const;
        int getSeats() const;
        string getCompanyName() const;
        double getPricePerKm() const;
        Date getPUCExpirationDate() const;

        // Function which sets new price of the vehicle 
        void setPricePerKm(double newPrice);

        // display record on screen
        void display() const;

        // overriden virtual method
        string toString() const;

        void setDataFrom (Storable *s);
};

#endif