#include <iostream>

int main() {
    int scores[] = {84, 92, 76, 81, 56};
    constexpr int numStudents = sizeof(scores) / sizeof(scores[0]);

    int maxScoreIndex = 0;

    for (int student = 1; student < numStudents; ++student) {
        if (scores[student] > scores[maxScoreIndex]) {
            maxScoreIndex = student;
        }
    }

    std::cout << "The best score was at index " << maxScoreIndex << ".\n";
}
