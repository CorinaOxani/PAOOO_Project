#include "ParkingSpot.h"
#include <iostream>

ParkingSpot::ParkingSpot(const std::string& id)
    : spotID(new std::string(id)), isOccupied(false), vehicleNumber(new std::string("")) {
    std::cout << "Parking spot " << *spotID << " has been created." << std::endl;
}

ParkingSpot::~ParkingSpot() {
    std::cout << "Parking spot " << *spotID << " is being released from memory." << std::endl;
    delete spotID;           // eliberarea memoriei spotID
    delete vehicleNumber;     // eliberarea memoriei vehicleNumber
}

// Suprascrierea operatorului de asignare (=) deep copy
ParkingSpot& ParkingSpot::operator=(const ParkingSpot& other) {
    if (this == &other) {    // verificare daca deja sunt aceleasi obiecte
        return *this;
    }

    // elibererarea memorie alocata anterior
    delete spotID;
    delete vehicleNumber;

    // alocare mem nouă, copiem valorile
    spotID = new std::string(*other.spotID);
    isOccupied = other.isOccupied;
    vehicleNumber = new std::string(*other.vehicleNumber);

    std::cout << "Assignment operator: Parking spot " << *spotID << " has been assigned." << std::endl;
    return *this;
}

void ParkingSpot::reserve(const std::string& vehicle) {
    if (!isOccupied) {
        *vehicleNumber = vehicle;
        isOccupied = true;
        std::cout << "Reservation successful: Spot " << *spotID 
                  << " is now occupied by vehicle " << *vehicleNumber << "." << std::endl;
    } else {
        std::cout << "Error: Spot " << *spotID << " is already occupied by another vehicle." << std::endl;
    }
}

void ParkingSpot::release() {
    if (isOccupied) {
        std::cout << "Release: Spot " << *spotID << " has been freed from vehicle " 
                  << *vehicleNumber << "." << std::endl;
        vehicleNumber->clear();
        isOccupied = false;
    } else {
        std::cout << "Spot " << *spotID << " is already free, no action needed." << std::endl;
    }
}
