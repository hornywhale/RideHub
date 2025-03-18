//
//  RentalSystem.h
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#pragma once

#include "Vehicle.h"
#include "Customer.h"
#include <vector>
#include <algorithm>

class RentalSystem {
public:
    void addVehicle(Vehicle* vehicle);
    void addCustomer(Customer* customer);
    void rentVehicle(const string& customerID, const string& licensePlate);
    void returnVehicle(const string& customerID);
    void displayAllVehicles() const;
    void displayAllCustomers() const;

    vector<Vehicle*> getVehicles() const;
    vector<Customer*> getCustomers() const;

    void sortVehiclesByLicensePlate();
    int countAvailableVehicles() const;

private:
    vector<Vehicle*> vehicles;
    vector<Customer*> customers;

    Vehicle* findVehicleByLicensePlate(const string& licensePlate);
    Customer* findCustomerByID(const string& customerID);
};

/* RentalSystem_h */
