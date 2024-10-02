#include <iostream>
#include <cstdlib>  
#include <ctime>
#include<limits>
using namespace std;

int selectDifficulty();
const int easyMaxAttempts = 10;
const int mediumMaxAttempts = 6;
const int hardMaxAttempts = 4;

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

void playGuessingGame(int lowerBound, int upperBound, int maxAttempts) {
    int randomNumber = generateRandomNumber(lowerBound, upperBound);

    int guess = -1;
    int attempts = 0;
    int guesses[100];

    while (guess != randomNumber && attempts < maxAttempts) {
        guess = getUserGuess();
        guesses[attempts] = guess;
        checkGuess(guess, randomNumber);
        attempts++;
    }

    if (guess == randomNumber) {
        cout << "You guessed the number in " << attempts << " attempts!" << endl;
    }
    else {
        cout << " Sorry, you've used all your attempts. The correct number was " << randomNumber << "." << endl;
    }

    cout << "Your guesses were: ";
    for (int i = 0; i < attempts; i++) {
        cout << guesses[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  

    int lowerBound, upperBound, maxAttempts;

    cout << "Welcome to the Random Number Guessing Game!" << endl;
    int difficulty = selectDifficulty();

    
    if (difficulty == 1) { 
        lowerBound = getValidatedInput("Enter the minimum number of the range: ");
        upperBound = getValidatedInput("Enter the maximum number of the range: ");

        
        while (lowerBound >= upperBound) {
            cout << "Invalid range! The maximum number must be greater than the minimum number." << endl;
            lowerBound = getValidatedInput("Enter the minimum number of the range: ");
            upperBound = getValidatedInput("Enter the maximum number of the range: ");
        }

        maxAttempts = easyMaxAttempts;
    }
    else if (difficulty == 2) { 
        lowerBound = 1;
        upperBound = 50;
        maxAttempts = mediumMaxAttempts;
    }
    else {  
        lowerBound = 1;
        upperBound = 20;
        maxAttempts = hardMaxAttempts;
    }

    cout << "I have picked a number between " << lowerBound << " and " << upperBound << ". Can you guess what it is?" << endl;
    cout << "You have " << maxAttempts << " attempts to guess the number." << endl;

    playGuessingGame(lowerBound, upperBound, maxAttempts);

    return 0;
}

int selectDifficulty() {
    cout << "Select Difficulty Level:" << endl;
    cout << "1. Easy (User-defined range, 10 attempts)" << endl;
    cout << "2. Medium (1-50, 6 attempts)" << endl;
    cout << "3. Hard (1-20, 4 attempts)" << endl;

    int choice;
    choice = getValidatedInput("Enter your choice (1-3): ");

    while (choice < 1 || choice > 3) {
        cout << "Invalid choice! Please select a valid difficulty level (1-3)." << endl;
        choice = getValidatedInput("Enter your choice (1-3): ");
    }

    return choice;
}
