//
//  Utils.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "Utils.h"
#include "Motorcycle.h"
#include <iostream>
#include <stdexcept>

void Utils::saveVehiclesToFile(const vector<Vehicle*>& vehicles, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for writing: " + filename);
    }

    for (const auto& vehicle : vehicles) {
        Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle);
        if (motorcycle) {
            file << motorcycle->getModel() << ","
                 << motorcycle->getLicensePlate() << ","
                 << motorcycle->getEngineCapacity() << ","
                 << motorcycle->getType() << ","
                 << motorcycle->getIsAvailable() << "\n";
        }
    }
    file.close();
}

vector<Vehicle*> Utils::loadVehiclesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for reading: " + filename);
    }

    vector<Vehicle*> vehicles;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string model, licensePlate, type;
        int engineCapacity;
        bool isAvailable;

        getline(ss, model, ',');
        getline(ss, licensePlate, ',');
        ss >> engineCapacity;
        ss.ignore();
        getline(ss, type, ',');
        ss >> isAvailable;

        Motorcycle* motorcycle = new Motorcycle(model, licensePlate, engineCapacity, type);
        motorcycle->setIsAvailable(isAvailable);
        vehicles.push_back(motorcycle);
    }
    file.close();
    return vehicles;
}

void Utils::saveCustomersToFile(const vector<Customer*>& customers, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for writing: " + filename);
    }

    for (const auto& customer : customers) {
        file << customer->getName() << ","
             << customer->getCustomerID() << "\n";
    }
    file.close();
}

vector<Customer*> Utils::loadCustomersFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for reading: " + filename);
    }

    vector<Customer*> customers;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, customerID;

        getline(ss, name, ',');
        getline(ss, customerID);

        customers.push_back(new Customer(name, customerID));
    }
    file.close();
    return customers;
}

void Utils::saveRentalSystemToFile(const RentalSystem& system, const string& vehicleFile, const string& customerFile) {
    saveVehiclesToFile(system.getVehicles(), vehicleFile);
    saveCustomersToFile(system.getCustomers(), customerFile);
}

RentalSystem Utils::loadRentalSystemFromFile(const string& vehicleFile, const string& customerFile) {
    RentalSystem system;

    vector<Vehicle*> vehicles = loadVehiclesFromFile(vehicleFile);
    for (auto vehicle : vehicles) {
        system.addVehicle(vehicle);
    }

    vector<Customer*> customers = loadCustomersFromFile(customerFile);
    for (auto customer : customers) {
        system.addCustomer(customer);
    }

    return system;
}
