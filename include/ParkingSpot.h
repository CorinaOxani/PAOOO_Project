#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "ParkingArea.h"
#include <memory>
#include <mutex>

class ParkingSpot : public ParkingArea {
private:
    std::unique_ptr<std::string> spotID;    // Identificator unic pentru loc
    std::shared_ptr<std::string> vehicleNumber; // Numărul vehiculului
    bool isOccupied;                        // Status ocupare
    mutable std::mutex spotMutex;          // Mutex pentru acces sincronizat

public:
    ParkingSpot(const std::string& areaName, const std::string& id);
    ~ParkingSpot();

    ParkingSpot(const ParkingSpot& other) = delete;              // Dezactivăm copierea
    ParkingSpot& operator=(const ParkingSpot& other) = delete;

    ParkingSpot(ParkingSpot&& other) noexcept;                   // Mutare
    ParkingSpot& operator=(ParkingSpot&& other) noexcept;

    void reserve(const std::string& vehicle);
    void release();
    void displayInfo() const override;
};

#endif // PARKINGSPOT_H
