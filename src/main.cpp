#include "ParkingSpot.h"

int main() {
    // Instanțierea locurilor de parcare
    ParkingSpot spot1("Zone A", "A1");
    ParkingSpot spot2("Zone B", "B1");

    //pentru punctul 6 urmatoarele linii pentru demostrarea functionarii copy constructorului va trebui sa fie comentate, vor genera erori

    // Demonstrare Copy Constructor
    ParkingSpot spotCopy = spot1; // Apelare Copy Constructor

    // Demonstrare Copy Assignment Operator
    spot2 = spot1; // Copiere prin assignment

    // Demonstrare Move Constructor
    ParkingSpot spotMove = std::move(spot1); // Apelare Move Constructor

    // Demonstrare Move Assignment Operator
    spot2 = std::move(spotMove); // Mutare prin assignment

    // Demonstrare utilizare
    spot2.reserve("TM13ZAR");
    spot2.displayInfo();
    spot2.release();

    // Upcasting: Instanțierea clasei derivate pe baza unui pointer de tipul clasei de bază
    ParkingArea* basePointer = new ParkingSpot("Zone C", "C1");
    basePointer->displayInfo();
    delete basePointer; // Destructorul trebuie să fie virtual

    // Downcasting: Conversia unui pointer de bază la unul derivat
    ParkingArea* basePointer2 = new ParkingSpot("Zone D", "D1");

    // Încercăm să facem downcasting
    ParkingSpot* derivedPointer = dynamic_cast<ParkingSpot*>(basePointer2);
    if (derivedPointer) {
        derivedPointer->displayInfo();
        derivedPointer->reserve("AB123CD");
        derivedPointer->release();
    } else {
        std::cout << "Downcasting failed.\n";
    }
    delete basePointer2;

    return 0;
}
