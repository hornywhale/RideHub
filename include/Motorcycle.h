//
//  Motorcycle.h
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#pragma once

#include "Vehicle.h"
#include <string>

class Motorcycle : public Vehicle {
public:
    Motorcycle(const string& model, const string& licensePlate, int engineCapacity, const string& type);

    void displayDetails() const override;

    int getEngineCapacity() const;
    string getType() const;

private:
    int engineCapacity;
    string type;
};

/* Motorcycle_h */
