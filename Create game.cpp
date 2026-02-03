#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess;

    srand(time(0));              // Seed random number
    secret = rand() % 10 + 1;    // Random number 1 to 10

    cout << "🎮 Guess the Number Game!" << endl;
    cout << "Guess a number between 1 and 10: ";
    cin >> guess;

    if (guess == secret) {
        cout << "🎉 Congratulations! You guessed right." << endl;
    }
    else if (guess > secret) {
        cout << "Too high! The number was " << secret << endl;
    }
    else {
        cout << "Too low! The number was " << secret << endl;
    }

    return 0;
}
