//
//  Motorcycle.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(const string& model, const string& licensePlate, int engineCapacity, const string& type)
    : Vehicle(model, licensePlate), engineCapacity(engineCapacity), type(type) {}

void Motorcycle::displayDetails() const {
    cout << "Model: " << getModel() << ", License Plate: " << getLicensePlate()
         << ", Engine Capacity: " << engineCapacity << "cc, Type: " << type
         << ", Available: " << (getIsAvailable() ? "Yes" : "No") << endl;
}

int Motorcycle::getEngineCapacity() const {
    return engineCapacity;
}

string Motorcycle::getType() const {
    return type;
}
