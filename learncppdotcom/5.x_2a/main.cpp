#include <iostream> // `std::cin`, `std::cout`
#include <cstdlib>  // `rand()`, `srand()`
#include <ctime>    // `time()`

bool playAgain() {
    while (true) {
        std::cout << "Would you like to play again (y/n)? ";
        char response;
        std::cin >> response;
        if (response == 'y') {
            return true;
        } else if (response == 'n') {
            return false;
        }
    }
}

int randInt(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

void playHiLo() {
    int randomNumber = randInt(0, 99);
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 "
        << "tries to guess what it is.\n";
    for (int guessCount = 1; guessCount < 8; guessCount++) {
        std::cout << "Guess#" << guessCount << ": ";
        int guess;
        std::cin >> guess;
        if (guess == randomNumber) {
            std::cout << "Correct! You win!\n";
            return;
        } else if (guess < randomNumber) {
            std::cout << "Your guess is too low.\n";
        } else {
            std::cout << "Your guess is too high.\n";
        }
    }
    // if we fall through, we have lost
    std::cout << "Sorry, you lose. The correct number was " << randomNumber
        << '\n';
}

int main() {
    srand(time(0));
    rand();
    do {
        playHiLo();
    } while (playAgain());
    std::cout << "Thank you for playing.\n";
}
