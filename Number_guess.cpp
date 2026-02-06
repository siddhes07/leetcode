#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));                 // Random seed
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber)
        {
            cout << "Too High!" << endl;
        }
        else if (guess < secretNumber)
        {
            cout << "Too Low!" << endl;
        }
        else
        {
            cout << "Correct!" << endl;
        }

    } while (guess != secretNumber);

    cout << "You guessed the number in ";
    cout << attempts << " attempts." << endl;

    cout << "Thanks for playing!" << endl;

    return 0;
}
