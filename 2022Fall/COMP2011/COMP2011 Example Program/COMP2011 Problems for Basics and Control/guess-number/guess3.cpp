#include <iostream>     /* File: guess3.cpp */ 
using namespace std;

int main()    // 3rd attempt: 1 player, multiple rounds, fixed range
{
    int number = 10;               // The answer is fixed beforehand
    int guess;
    int low = 1, high = 100;  // Add 2 variables to record the range

    do // Add a loop to implement multiple rounds 
    {
        cout << "Player 1, please enter your guess:" << endl;
        cin >> guess;

        while (guess < low || guess > high) // Input validation loop
        {
            cout << "Invalid input, please enter a number between " 
                 << low << " and " << high << endl;
            cin >> guess;
        }   // Can this loop be replaced with do-while?

        if (guess == number)
            cout << "Player 1, you win!!!" << endl;

        else if (guess < number)
        {
            cout << "Sorry, the number is bigger than "
                 << guess << endl;
            low = guess + 1; // Update the lower bound of the range
        } 
        else 
        {
            cout << "Sorry, the number is smaller than " 
                 << guess << endl; 
            high = guess - 1; // Update the upper bound of the range
        }
    } while (guess != number);  

    return 0;
}
