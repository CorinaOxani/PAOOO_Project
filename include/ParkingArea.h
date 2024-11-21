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

   // Dezactivăm copierea
    ParkingArea(const ParkingArea&) = delete; // Copy constructor
    ParkingArea& operator=(const ParkingArea&) = delete; // Copy assignment operator

    // mutarea
    ParkingArea(ParkingArea&& other) noexcept : areaName(std::move(other.areaName)) {
        std::cout << "ParkingArea move constructor called.\n";
    }

    ParkingArea& operator=(ParkingArea&& other) noexcept {
        if (this != &other) {
            areaName = std::move(other.areaName);
            std::cout << "ParkingArea move assignment operator called.\n";
        }
        return *this;
    }

    
};

#endif // PARKINGAREA_H
