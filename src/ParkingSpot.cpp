#include "ParkingSpot.h"

// ==================== Constructori si Destructor ====================

// Constructor normal
ParkingSpot::ParkingSpot(const std::string& areaName, const std::string& id)
    : ParkingArea(areaName), spotID(new std::string(id)), isOccupied(false), vehicleNumber(new std::string("")) {
    std::cout << "ParkingSpot constructor called for : Spot " << *spotID << " from area " << areaName << ".\n";
}

// Destructor
ParkingSpot::~ParkingSpot() {
    std::cout << "ParkingSpot destructor: Spot " 
              << (spotID ? *spotID : "[empty]") 
              << " destroyed.\n";
    delete spotID;
    delete vehicleNumber;
}

// ==================== Copy ====================

// Copy constructor
ParkingSpot::ParkingSpot(const ParkingSpot& other)
    : ParkingArea(other.areaName), // Copierea manuală a zonei
      spotID(new std::string(*other.spotID)),
      isOccupied(other.isOccupied),
      vehicleNumber(new std::string(*other.vehicleNumber)) {
    std::cout << "ParkingSpot copy constructor: Copied spot " << *spotID << ".\n";
}


// Copy assignment operator
ParkingSpot& ParkingSpot::operator=(const ParkingSpot& other) {
    if (this != &other) {
        // Copiere manuală a zonei în locul operatorului dezactivat
        areaName = other.areaName;

        delete spotID;
        delete vehicleNumber;

        spotID = new std::string(*other.spotID);
        isOccupied = other.isOccupied;
        vehicleNumber = new std::string(*other.vehicleNumber);

        std::cout << "ParkingSpot copy assignment operator: Assigned spot " << *spotID << ".\n";
    }
    return *this;
}


// ==================== Move ====================

// Move constructor
ParkingSpot::ParkingSpot(ParkingSpot&& other) noexcept
    : ParkingArea(std::move(other)), spotID(other.spotID),
      isOccupied(other.isOccupied), vehicleNumber(other.vehicleNumber) {
    other.spotID = nullptr;
    other.vehicleNumber = nullptr;
    std::cout << "ParkingSpot move constructor: Moved spot.\n";
}


// Move assignment operator
ParkingSpot& ParkingSpot::operator=(ParkingSpot&& other) noexcept {
    if (this != &other) {
        ParkingArea::operator=(std::move(other)); // Mutam partea de baza

        if (spotID) delete spotID; // Eliberam memoria existenta
        if (vehicleNumber) delete vehicleNumber;

        spotID = other.spotID;
        vehicleNumber = other.vehicleNumber;
        isOccupied = other.isOccupied;

        other.spotID = nullptr;
        other.vehicleNumber = nullptr;

        std::cout << "ParkingSpot move assignment operator: Moved spot.\n";
    }
    return *this;
}

// ==================== Functionalitati ====================

// Rezerva locul
void ParkingSpot::reserve(const std::string& vehicle) {
    if (!isOccupied) {
        *vehicleNumber = vehicle;
        isOccupied = true;
        std::cout << "Spot " << *spotID << " reserved for vehicle " << *vehicleNumber << ".\n";
    } else {
        std::cout << "Spot " << *spotID << " is already occupied.\n";
    }
}

// Elibereaza locul
void ParkingSpot::release() {
    if (isOccupied) {
        std::cout << "Spot " << *spotID << " released from vehicle " << *vehicleNumber << ".\n";
        vehicleNumber->clear();
        isOccupied = false;
    } else {
        std::cout << "Spot " << *spotID << " is already free.\n";
    }
}

// Afișeaza informațiile
void ParkingSpot::displayInfo() const {
    std::cout << "Spot ID: " << *spotID << " | Area: " << areaName
              << " | Occupied: " << (isOccupied ? "Yes" : "No") << "\n";




}