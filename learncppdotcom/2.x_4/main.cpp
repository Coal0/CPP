#include <iostream>
#include "constants.h"

float getDistanceTravelled(int seconds) {
    return myConstants::gravity * (seconds * seconds) / 2;
}

int main() {
    std::cout << "Enter the initial height of the tower in meters: ";
    int initialHeight;
    std::cin >> initialHeight;

    for (int i = 0;; i++) {
        float height = initialHeight - getDistanceTravelled(i);
        if (height <= 0) {
            std::cout << "At " << i << " seconds, the ball is on the ground.\n";
            break;
        } else {
            std::cout << "At " << i << " seconds, the ball is at height: "
                << height << " meters.\n";
        }
    }
}
