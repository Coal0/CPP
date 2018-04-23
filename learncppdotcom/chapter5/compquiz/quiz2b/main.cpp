#include <ios> // `std::streamsize`
#include <iostream> // `std::cin`, `std::cout`
#include <limits> // `std::numeric_limits`
#include <cstdlib> // `rand()`, `srand()`
#include <ctime> // `time()`

/* Get a random int in the range [min, max] (max inclusive). */
int getRandomInt(int min, int max) {
    // credit:
    // http://www.learncpp.com/cpp-tutorial/59-random-number-generation/
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

/* Get the user's next guess. `try_` is the try count. */
int getUserGuess(int try_) {
    int guess;
    while (true) {
        std::cout << "Guess # " << try_ << ": ";
        std::cin >> guess;
        if (std::cin.fail()) {
            // extraction failure
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return guess;
        }
    }
}

/* Play the number guessing game. Return WON_GAME if the user wins the
game, LOST_GAME otherwise. `min` and `max` are the lower and upper
bounds for the randomly generated number, respectively. `tries` is the
amount of tries the user gets before having lost the game. */
void playNumberGuessingGame(int min, int max, int tries) {
    std::cout << "Let's play a game. I'm thinking of a number. ";
    std::cout << "You have " << tries << " tries to guess what it is.\n";
    int number = getRandomInt(min, max);
    for (int try_ = 0; try_ < tries; try_++) {
        int guess = getUserGuess(try_);
        if (guess == number) {
            std::cout << "Correct! You win!\n";
            return;
        } else if (guess < number) {
            std::cout << "Your guess is too low.\n";
        } else {
            std::cout << "Your guess is too high.\n";
        }
    }
    // if we fall through, the user has lost :(
    std::cout << "Sorry, you lose. The correct number was " << number << '\n';
}

/* Ask the user if they want to play again. */
bool playAgain() {
    char response;
    while (true) {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (response == 'y') {
            return true;
        } else if (response == 'n') {
            return false;
        }
    }
}

int main() {
    constexpr int MIN = 0;
    constexpr int MAX = 99;
    constexpr int TRIES = 7;

    srand(time(0));
    rand();

    do {
        playNumberGuessingGame(MIN, MAX, TRIES);
    } while (playAgain());

    std::cout << "Thank you for playing.\n";
}
