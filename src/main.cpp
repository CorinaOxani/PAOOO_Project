#include "ParkingSpot.h"
#include <iostream>

int main() {
    ParkingSpot spot1("A");
    ParkingSpot spot2("B");

    spot1.reserve("TM13ZAR");
    spot2 = spot1;  // folosesc atribuirea

    ParkingSpot spot3("C"); // doar l-am creat fara sa fac rezervare


    spot1.release();
    spot2.release();
    spot3.release();

    return 0;
}
