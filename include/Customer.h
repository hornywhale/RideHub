//
//  Customer.h
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#pragma once

#include "Vehicle.h"
#include <string>

class Customer {
public:
    Customer(const string& name, const string& customerID);

    void rentVehicle(Vehicle* vehicle);
    void returnVehicle();
    void displayRentedVehicle() const;

    string getName() const;
    string getCustomerID() const;
    Vehicle* getRentedVehicle() const;

private:
    
    string name;
    string customerID;
    Vehicle* rentedVehicle;
};

/* Customer_h */
