#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include <string>
#include <iostream>

class ParkingArea {
protected:
    std::string areaName; // Numele zonei

public:
    ParkingArea(const std::string& name) : areaName(name) {
        std::cout << "ParkingArea constructor called for : Area " << areaName << ".\n";
    }

    virtual ~ParkingArea() {
        std::cout << "ParkingArea destructor called for : Area " << areaName << " destroyed.\n";
    }

    virtual void displayInfo() const {
        std::cout << "Parking Area: " << areaName << "\n";
    }

    // Move assignment operator
    ParkingArea& operator=(ParkingArea&& other) noexcept {
        if (this != &other) {
            areaName = std::move(other.areaName);
            std::cout << "ParkingArea move assignment operator called.\n";
        }
        return *this;
    }

    // Copy assignment operator
    ParkingArea& operator=(const ParkingArea& other) {
        if (this != &other) {
            areaName = other.areaName;
            std::cout << "ParkingArea copy assignment operator called.\n";
        }
        return *this;
    }

    // Copy constructor
    ParkingArea(const ParkingArea& other) : areaName(other.areaName) {
        std::cout << "ParkingArea copy constructor called.\n";
    }

    // Move constructor
    ParkingArea(ParkingArea&& other) noexcept : areaName(std::move(other.areaName)) {
        std::cout << "ParkingArea move constructor called.\n";
    }
};

#endif // PARKINGAREA_H
