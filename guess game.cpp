#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int secretNumber, guess, tries = 0;
    srand(time(0));
    secretNumber = rand() % 50 + 1;
    cout << "Welcome to the number guessing game!\n";
    cout << "Guess a number between 1 and 50: ";
    do {
        cin >> guess;
        tries++;
        if (guess > secretNumber) {
            cout << "Too high! Try again: ";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "\nCongratulations! You guessed the secret number in " << tries << " tries.\n";
        }
    } while (guess != secretNumber);
    return 0;
}

