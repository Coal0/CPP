// Edited according to Code Review SE answers

#include <chrono> // `std::chrono::high_resolution_clock`
#include <iostream> // `std::cin`, `std::cout`, `std::streamsize`
#include <limits> // `std::numeric_limits`
#include <random> // `std::mt19937`, `std::uniform_int_distribution`

bool askUserToPlayAgain() {
    char response;
    while (true) {
        std::cout << "Do you want to play again (y/n)? ";
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (response == 'y') {
            return true;
        } else if (response == 'n') {
            return false;
        }
    }
}

int getGuessFromUser(int tryCount) {
    int response;
    while (true) {
        std::cout << "Guess #" << tryCount << ": ";
        if (std::cin >> response) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return response;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int getRandomInt(int lowerBound, int upperBound) {
    using namespace std::chrono;
    high_resolution_clock::time_point now = high_resolution_clock::now();
    std::mt19937 generator = std::mt19937(now.time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
    return distribution(generator);
}

void playNumberGuessingGame(int min, int max, int maxTries) {
    std::cout << "Let's play a game of Guess The Number!\n";
    std::cout << "I'm thinking of a number between " 
        << min << " and " << max << ".\n";
    std::cout << "You have " << maxTries << " tries to guess it. Good luck!\n";
    int number = getRandomInt(min, max);
    for (int tryCount = 1; tryCount < maxTries + 1; ++tryCount) {
        int guess = getGuessFromUser(tryCount);
        if (guess == number) {
            std::cout << "You got it!\n";
            return;
        } else if (guess < number) {
            std::cout << "Try a little higher...\n";
        } else {
            std::cout << "Try a little lower...\n";
        }
    }
    // if we fall through, the user has lost
    std::cout << "Aw, you lost. The number was " << number << ".\n";
}

int main() {
    constexpr int MIN = 1;
    constexpr int MAX = 99;
    constexpr int MAX_TRIES = 7;

    do {
        playNumberGuessingGame(MIN, MAX, MAX_TRIES);
    } while (askUserToPlayAgain());
    
    std::cout << "Goodbye!\n";
}
