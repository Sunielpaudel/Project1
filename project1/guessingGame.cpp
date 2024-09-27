#include <iostream>
#include <cstdlib>  
#include <ctime>
#include<limits>
using namespace std;

// Function to generate a random number between the specified range
int generateRandomNumber(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;  
}

// Function to get and validate integer input from the user
int getValidatedInput(const string& prompt) {
    int input;
    cout << prompt;

    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid number: ";
    }
    return input;
}

// Function to get the user's guess
int getUserGuess() {
    int guess;
        cout << "Enter your guess: ";
        while(!(cin >> guess)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! please enter a valid guess: ";
    }
        return guess;
}

// Function to check the user's guess against the generated random number
void checkGuess(int guess, int target) {
    if (guess > target) {
        cout << "Too high! Try again." << endl;
    }
    else if (guess < target) {
        cout << "Too low! Try again." << endl;
    }
    else {
        cout << "Congratulations! You guessed the correct number." << endl;
    }
}

// Function to start the game
void playGuessingGame(int lowerBound, int upperBound) {
    // Generate random number
    int randomNumber = generateRandomNumber(lowerBound, upperBound);

    int guess = -1;
    int attempts = 0;

    // Loop until the user guesses the correct number
    while (guess != randomNumber) {
        guess = getUserGuess();
        checkGuess(guess, randomNumber);
        attempts++;
    }

    cout << "You guessed the number in " << attempts << " attempts!" << endl;
}

int main() {
    srand(time(0));  

    int lowerBound, upperBound;

    cout << "Welcome to the Random Number Guessing Game!" << endl;
    cout << "Choose a range for the random number." << endl;

    lowerBound = getValidatedInput("Enter the minimum number of the range: ");

    upperBound = getValidatedInput("Enter the maximum number of the range: ");
  

    // Validation of the range:
    while (lowerBound >= upperBound) {
        cout << "Invalid range! The maximum number must be greater than the minimum number." << endl;
        cout << "Enter the minimum number: ";
        cin >> lowerBound;
        cout << "Enter the maximum number: ";
        cin >> upperBound;
    }

    cout << "I have picked a number between " << lowerBound << " and " << upperBound << ". Can you guess what it is?" << endl;

    playGuessingGame(lowerBound, upperBound);

    return 0;
}
