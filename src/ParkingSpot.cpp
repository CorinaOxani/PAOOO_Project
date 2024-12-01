#include "ParkingSpot.h"
#include <chrono>
#include <thread>

// ==================== Constructori și Destructor ====================

// Constructor normal
ParkingSpot::ParkingSpot(const std::string& areaName, const std::string& id)
    : ParkingArea(areaName), 
      spotID(std::make_unique<std::string>(id)), 
      vehicleNumber(std::make_shared<std::string>("")),
      isOccupied(false) {
    std::cout << "ParkingSpot constructor called for : Spot " << *spotID << " from area " << areaName << ".\n";
}

// Destructor
ParkingSpot::~ParkingSpot() {
    std::cout << "ParkingSpot destructor: Spot " 
              << (spotID ? *spotID : "[empty]") 
              << " destroyed.\n";
}

// ==================== Move ====================

// Move constructor
ParkingSpot::ParkingSpot(ParkingSpot&& other) noexcept
    : ParkingArea(std::move(other)),
      spotID(std::move(other.spotID)),
      vehicleNumber(std::move(other.vehicleNumber)),
      isOccupied(other.isOccupied) {
    other.isOccupied = false;
    std::cout << "ParkingSpot move constructor: Moved spot.\n";
}

// Move assignment operator
ParkingSpot& ParkingSpot::operator=(ParkingSpot&& other) noexcept {
    if (this != &other) {
        ParkingArea::operator=(std::move(other));
        spotID = std::move(other.spotID);
        vehicleNumber = std::move(other.vehicleNumber);
        isOccupied = other.isOccupied;
        other.isOccupied = false;
        std::cout << "ParkingSpot move assignment operator: Moved spot.\n";
    }
    return *this;
}

// ==================== Funcționalități ====================

// Rezervă locul
void ParkingSpot::reserve(const std::string& vehicle) {
    if (spotMutex.try_lock()) { // blocare mutex
        std::cout << "Spot " << *spotID << " is now locked by thread for reservation.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulare proces lung
        if (!isOccupied) {
            *vehicleNumber = vehicle;
            isOccupied = true;
            std::cout << "Spot " << *spotID << " reserved for vehicle " << *vehicleNumber << ".\n";
        } else {
            std::cout << "Spot " << *spotID << " is already occupied.\n";
        }
        spotMutex.unlock(); // Deblocare mutex
        std::cout << "Spot " << *spotID << " is now unlocked after reservation.\n";
    } else {
        std::cout << "Spot " << *spotID << " is currently locked by another thread. Reservation failed.\n";
    }
}

// Eliberează locul
void ParkingSpot::release() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulare intarziere
    if (spotMutex.try_lock()) { // blocare mutex
        std::cout << "Spot " << *spotID << " is now locked by thread for release.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulare proces lung
        if (isOccupied) {
            std::cout << "Spot " << *spotID << " released from vehicle " << *vehicleNumber << ".\n";
            vehicleNumber->clear();
            isOccupied = false;
        } else {
            std::cout << "Spot " << *spotID << " is already free.\n";
        }
        spotMutex.unlock(); // Deblocare mutex
        std::cout << "Spot " << *spotID << " is now unlocked after release.\n";
    } else {
        std::cout << "Spot " << *spotID << " is currently locked by another thread. Release failed.\n";
    }
}

// Afișează informațiile
void ParkingSpot::displayInfo() const {
    std::lock_guard<std::mutex> lock(spotMutex); // Blocăm accesul
    std::cout << "Spot ID: " << *spotID << " | Area: " << areaName
              << " | Occupied: " << (isOccupied ? "Yes" : "No") << "\n";
}
