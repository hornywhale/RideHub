//
//  Vehicle.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "Vehicle.h"

Vehicle::Vehicle(const string& model, const string& licensePlate)
    : model(model), licensePlate(licensePlate), available(true) {}

string Vehicle::getModel() const {
    return model;
}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}

bool Vehicle::getIsAvailable() const {
    return available;
}

void Vehicle::setIsAvailable(bool availability) {
    available = availability;
}
