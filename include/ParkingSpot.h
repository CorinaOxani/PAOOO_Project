#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <string>

class ParkingSpot {
private:
    std::string* spotID;         // pointer pentru alocare dinamică
    bool isOccupied;
    std::string* vehicleNumber;   // pointer pentru alocare dinamică

public:
    ParkingSpot(const std::string& id);
    ~ParkingSpot();

    ParkingSpot& operator=(const ParkingSpot& other); // Suprascrierea operatorului de asignare

    void reserve(const std::string& vehicle);
    void release();
};

#endif // PARKINGSPOT_H
