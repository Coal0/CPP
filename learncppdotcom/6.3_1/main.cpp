#include <iostream>

void printArray(int array[], int arrayLength) {
    std::cout << "{";
    for (int i = 0; i < arrayLength - 1; ++i) {
        // avoid outputting an extraneous comma
        std::cout << array[i] << ", ";
    }
    std::cout << array[arrayLength - 1]  << "}\n";
}

int main() {
    int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};
    constexpr int arrayLength = sizeof(array) / sizeof(array[0]);
    printArray(array, arrayLength);
}
