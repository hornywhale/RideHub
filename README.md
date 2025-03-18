# Motorcycle Rental System RideHub

A C++ project simulating a motorcycle rental system. This project demonstrates object-oriented programming concepts such as inheritance, polymorphism, virtual functions, operator overloading, and file I/O.

---

## Table of Contents
1. [Features](#features)
2. [Project Structure](#project-structure)
3. [Requirements](#requirements)
4. [Building the Project](#building-the-project)
5. [Running the Project](#running-the-project)
6. [File I/O](#file-io)

---

## Features
- **6 Classes**: Includes an abstract base class (`Vehicle`) and derived classes (`Motorcycle`).
- **Inheritance**: `Motorcycle` inherits from `Vehicle`.
- **Polymorphism**: Demonstrates runtime polymorphism using virtual functions.
- **Operator Overloading**: Overloads `==` and `<<` operators.
- **Algorithms**: Uses `std::sort`, `std::find_if`, and `std::count_if` from the `<algorithm>` library.
- **File I/O**: Saves and loads data to/from `motorcycle.txt` and `customers.txt`.
- **Exception Handling**: Throws exceptions for invalid operations (e.g., renting an unavailable motorcycle).

---

## Project Structure
```
RideHub/
├── data/                  # Directory for data files
│   ├── customers.txt      # Customer data
│   └── motorcycle.txt     # Motorcycle data
├── include/               # Header files
│   ├── Customer.h
│   ├── Motorcycle.h
│   ├── RentalSystem.h
│   ├── Utils.h
│   └── Vehicle.h
├── main.cpp               # Main program entry point
└── src/                   # Source files
    ├── Customer.cpp
    ├── Motorcycle.cpp
    ├── RentalSystem.cpp
    ├── Utils.cpp
    └── Vehicle.cpp
```

---

## Requirements
- **C++ Compiler**: Supports C++17 (e.g., `g++` 9.0 or later).
- **Build Tools**: `make` (optional, for using the `Makefile`).

---

## Building the Project

### Using `g++`
1. Navigate to the project directory:
   ```bash
   cd /path/to/RideHub
   ```
2. Compile the project:
   ```bash
   g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o RideHub
   ```

### Using `Makefile`
1. Navigate to the project directory:
   ```bash
   cd /path/to/RideHub
   ```
2. Compile the project:
   ```bash
   make
   ```

---

## Running the Project
1. Run the executable:
   ```bash
   ./RideHub
   ```
2. The program will:
   - Create a `data/` directory (if it doesn’t exist).
   - Save data to `motorcycle.txt` and `customers.txt`.
   - Load data from the files and display the system state.

---

## File I/O
- **`motorcycle.txt`**: Stores motorcycle data in CSV format:
  ```
  Model,License Plate,Engine Capacity,Type,Available
  Yamaha R1,ABC123,1000,Sport,1
  Ducati Panigale,XYZ789,1200,Superbike,0
  ```
- **`customers.txt`**: Stores customer data in CSV format:
  ```
  Name,Customer ID
  John Doe,C001
  Jane Smith,C002
  ```

---
