#include <iostream> // `std::cin`, `std::cout`, `std::streamsize`
#include <limits> // `std::numeric_limits`

int getNumberBetween(int min, int max) {
    int response;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        if (std::cin >> response) {
            if (response > min && response < max) {
                return response;
            } else {
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void printArray(int array[], int arrayLength) {
    std::cout << "{";
    for (int i = 0; i < arrayLength - 1; ++i) {
        // avoid outputting an extraneous comma
        std::cout << array[i] << ", ";
    }
    std::cout << array[arrayLength - 1] << "}\n";
}

void printArrayElementIndex(int array[], int arrayLength, int element) {
    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] == element) {
            std::cout << "Found element " << element << " at index "
                << i << ".\n";
            return;
        }
    }
    std::cout << "No matching elements found.\n";
}

int main() {
    int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};
    constexpr int arrayLength = sizeof(array) / sizeof(array[0]);
    int number = getNumberBetween(0, 10);
    printArray(array, arrayLength);
    printArrayElementIndex(array, arrayLength, number);
}
