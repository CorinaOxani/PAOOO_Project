#include "ParkingSpot.h"
#include <thread>
#include <chrono>

// Funcție pentru rezervarea locului de parcare (thread example)
void reserveSpotWithDelay(ParkingSpot& spot, const std::string& vehicle, int delayMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs)); // Simulează întârziere
    spot.reserve(vehicle);
}

int main() {
    // Instanțierea locurilor de parcare
    ParkingSpot spot1("Zone A", "A1");
    ParkingSpot spot2("Zone B", "B1");

    // Demonstrare Move Constructor
    ParkingSpot spotCopy = std::move(spot1);

    // Demonstrare Move Assignment Operator
    spot2 = std::move(spotCopy);

    // Demonstrare funcționalități
    spot2.reserve("TM13ZAR");
    spot2.displayInfo();
    spot2.release();

    // Upcasting: Instantierea clasei derivate pe baza unui pointer de tipul clasei de bază
    ParkingArea* basePointer = new ParkingSpot("Zone C", "C1");
    basePointer->displayInfo();
    delete basePointer; // Destructorul trebuie să fie virtual

    // Downcasting: Conversia unui pointer de bază la unul derivat
    ParkingArea* basePointer2 = new ParkingSpot("Zone D", "D1");

    // Încearcă un downcasting
    ParkingSpot* derivedPointer = dynamic_cast<ParkingSpot*>(basePointer2);
    if (derivedPointer) {
        derivedPointer->displayInfo();
        derivedPointer->reserve("AB123CD");
        derivedPointer->release();
    } else {
        std::cout << "Downcasting failed.\n";
    }
    delete basePointer2;

    // Testare cu thread-uri
   ParkingSpot spotThread("Zone E", "E1");

    // Testare cu 2 thread-uri care vor sa faca rezervare pe acelasi loc
    std::thread t1(reserveSpotWithDelay, std::ref(spotThread), "TM12XYZ", 50);
    std::thread t2(reserveSpotWithDelay, std::ref(spotThread), "CJ07ABC", 100);

    t1.join();
    t2.join();

    spotThread.displayInfo();
    spotThread.release();
    spotThread.displayInfo();

    return 0;
}
