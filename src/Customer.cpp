//
//  Customer.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "Customer.h"
#include <iostream>

Customer::Customer(const string& name, const string& customerID)
    : name(name), customerID(customerID), rentedVehicle(nullptr) {}

void Customer::rentVehicle(Vehicle* vehicle) {
    if (rentedVehicle != nullptr) {
        cout << "Customer " << name << " already has a rented vehicle." << endl;
        return;
    }
    if (!vehicle->getIsAvailable()) {
        cout << "Vehicle is not available for rent." << endl;
        return;
    }
    rentedVehicle = vehicle;
    rentedVehicle->setIsAvailable(false);
    cout << "Vehicle rented successfully by " << name << "." << endl;
}

void Customer::returnVehicle() {
    if (rentedVehicle == nullptr) {
        cout << "No vehicle to return." << endl;
        return;
    }
    rentedVehicle->setIsAvailable(true);
    rentedVehicle = nullptr;
    cout << "Vehicle returned successfully by " << name << "." << endl;
}

void Customer::displayRentedVehicle() const {
    if (rentedVehicle == nullptr) {
        cout << name << " has no rented vehicle." << endl;
        return;
    }
    cout << name << "'s rented vehicle details:" << endl;
    rentedVehicle->displayDetails();
}

string Customer::getName() const {
    return name;
}

string Customer::getCustomerID() const {
    return customerID;
}

Vehicle* Customer::getRentedVehicle() const {
    return rentedVehicle;
}
