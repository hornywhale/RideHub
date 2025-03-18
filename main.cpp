//
//  main.cpp
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#include "RentalSystem.h"
#include "Motorcycle.h"
#include "Utils.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    RentalSystem system;

    // Hardcode the project directory path
    fs::path projectDir = "/Users/hornywhale/Projects/RideHub/RideHub/data";
    cout << "Project directory: " << projectDir << endl;

    // Define file paths in the project directory
    fs::path motorcycleFile = projectDir / "motorcycle.txt";
    fs::path customersFile = projectDir / "customers.txt";

    // Create motorcycles
    Motorcycle* bike1 = new Motorcycle("Yamaha R1", "ABC123", 1000, "Sport");
    Motorcycle* bike2 = new Motorcycle("Ducati Panigale", "XYZ789", 1200, "Superbike");

    // Create customers
    Customer* customer1 = new Customer("John Doe", "C001");
    Customer* customer2 = new Customer("Jane Smith", "C002");

    // Add vehicles and customers to the system
    system.addVehicle(bike1);
    system.addVehicle(bike2);
    system.addCustomer(customer1);
    system.addCustomer(customer2);

    // Rent vehicles
    system.rentVehicle("C001", "ABC123");
    system.rentVehicle("C002", "XYZ789");

    // Display all vehicles and customers
    cout << "Initial System State:" << endl;
    system.displayAllVehicles();
    system.displayAllCustomers();

    // Save the system to files in the project directory
    Utils::saveRentalSystemToFile(system, motorcycleFile.string(), customersFile.string());
    cout << "\nSystem data saved to files:" << endl;
    cout << "Motorcycle data: " << motorcycleFile << endl;
    cout << "Customer data: " << customersFile << endl;

    // Load the system from files in the project directory
    RentalSystem loadedSystem = Utils::loadRentalSystemFromFile(motorcycleFile.string(), customersFile.string());
    cout << "\nSystem data loaded from files." << endl;

    // Display all vehicles and customers in the loaded system
    cout << "\nLoaded System State:" << endl;
    loadedSystem.displayAllVehicles();
    loadedSystem.displayAllCustomers();

    // Clean up
    delete bike1;
    delete bike2;
    delete customer1;
    delete customer2;

    return 0;
}
