//
//  Vehicle.h
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Vehicle {
public:
    Vehicle(const string& model, const string& licensePlate);

    virtual void displayDetails() const = 0;

    string getModel() const;
    string getLicensePlate() const;
    bool getIsAvailable() const;
    void setIsAvailable(bool availability);

    virtual ~Vehicle() = default;

protected:
    string model;
    string licensePlate;
    bool available;
};

/* Vehicle_h */
