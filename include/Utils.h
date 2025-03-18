//
//  Utils.h
//  RideHub
//
//  Created by Егор Тыщук on 17.3.25..
//

#pragma once

#include "Vehicle.h"
#include "Customer.h"
#include "RentalSystem.h"
#include <fstream>
#include <sstream>

class Utils {
public:
    static void saveVehiclesToFile(const vector<Vehicle*>& vehicles, const string& filename);
    static vector<Vehicle*> loadVehiclesFromFile(const string& filename);

    static void saveCustomersToFile(const vector<Customer*>& customers, const string& filename);
    static vector<Customer*> loadCustomersFromFile(const string& filename);

    static void saveRentalSystemToFile(const RentalSystem& system, const string& vehicleFile, const string& customerFile);
    static RentalSystem loadRentalSystemFromFile(const string& vehicleFile, const string& customerFile);
};

/* Utils_h */
