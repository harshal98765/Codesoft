// Create a program that generates a random number and asks the
// user to guess it. Provide feedback on whether the guess is too
// high or too low until the user guesses the correct number.

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(std::time(0)); // Seed the random number generator

    int secretNumber = std::rand() % 100 + 1;  // Generate a random number between 1 and 100

    int userGuess;

    while (true) {
        // Ask the user to guess the number
        std::cout << "Guess the number between 1 and 100: ";
        std::cin >> userGuess;

        // Check if the guess is correct
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Too high. Try again." << std::endl;
        }
    }

    return 0;
}
