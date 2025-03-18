//
//  RentalSystem.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "RentalSystem.h"
#include <iostream>
#include <algorithm>

void RentalSystem::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void RentalSystem::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

void RentalSystem::rentVehicle(const string& customerID, const string& licensePlate) {
    Customer* customer = findCustomerByID(customerID);
    Vehicle* vehicle = findVehicleByLicensePlate(licensePlate);

    if (customer == nullptr) {
        cout << "Customer with ID " << customerID << " not found." << endl;
        return;
    }
    if (vehicle == nullptr) {
        cout << "Vehicle with license plate " << licensePlate << " not found." << endl;
        return;
    }

    customer->rentVehicle(vehicle);
}

void RentalSystem::returnVehicle(const string& customerID) {
    Customer* customer = findCustomerByID(customerID);

    if (customer == nullptr) {
        cout << "Customer with ID " << customerID << " not found." << endl;
        return;
    }

    customer->returnVehicle();
}

void RentalSystem::displayAllVehicles() const {
    cout << "All Vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->displayDetails();
    }
}

void RentalSystem::displayAllCustomers() const {
    cout << "All Customers:" << endl;
    for (const auto& customer : customers) {
        cout << "Name: " << customer->getName() << ", ID: " << customer->getCustomerID() << endl;
        customer->displayRentedVehicle();
    }
}

vector<Vehicle*> RentalSystem::getVehicles() const {
    return vehicles;
}

vector<Customer*> RentalSystem::getCustomers() const {
    return customers;
}

void RentalSystem::sortVehiclesByLicensePlate() {
    sort(vehicles.begin(), vehicles.end(), [](Vehicle* v1, Vehicle* v2) {
        return v1->getLicensePlate() < v2->getLicensePlate();
    });
}

int RentalSystem::countAvailableVehicles() const {
    return count_if(vehicles.begin(), vehicles.end(), [](Vehicle* vehicle) {
        return vehicle->getIsAvailable();
    });
}

Vehicle* RentalSystem::findVehicleByLicensePlate(const string& licensePlate) {
    auto it = find_if(vehicles.begin(), vehicles.end(), [&licensePlate](Vehicle* vehicle) {
        return vehicle->getLicensePlate() == licensePlate;
    });
    return (it != vehicles.end()) ? *it : nullptr;
}

Customer* RentalSystem::findCustomerByID(const string& customerID) {
    for (auto& customer : customers) {
        if (customer->getCustomerID() == customerID) {
            return customer;
        }
    }
    return nullptr;
}
