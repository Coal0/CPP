#include <iostream>
#include "constants.h"

float heightAfter(int seconds) {
    // Using s = u * t + (a * t^2) / 2
    // NOTE u = 0
    return physics::gravity * (seconds * seconds) / 2;
}

int main() {
    std::cout << "Enter the initial height of the tower in meters: ";
    float initialHeight;
    std::cin >> initialHeight;

    int secs = 0;
    while (true) {
        float height = initialHeight - heightAfter(secs);
        if (height <= 0) {
            std::cout << "At " << secs << " seconds, the ball is on the "
                << "ground.\n";
            break;
        } else {
            std::cout << "At " << secs << " seconds, the ball is at height: "
                << height << " meters.\n";
        }
        secs++;
    }
}
