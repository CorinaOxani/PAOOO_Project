#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "ParkingArea.h"

class ParkingSpot : public ParkingArea {
private:
    std::string* spotID;         // Identificator unic pentru loc
    bool isOccupied;             // Status ocupare
    std::string* vehicleNumber;  // Numărul vehiculului

public:
    ParkingSpot(const std::string& areaName, const std::string& id);
    ~ParkingSpot();

    // Copy constructor
    ParkingSpot(const ParkingSpot& other);

    // Copy assignment operator
    ParkingSpot& operator=(const ParkingSpot& other);

    // Move constructor
    ParkingSpot(ParkingSpot&& other) noexcept;

    // Move assignment operator
    ParkingSpot& operator=(ParkingSpot&& other) noexcept;

    void reserve(const std::string& vehicle);
    void release();

    void displayInfo() const override;

    
};

#endif // PARKINGSPOT_H
