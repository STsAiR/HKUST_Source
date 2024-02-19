#include <iostream>     /* File: guess2.cpp */ 
using namespace std;

int main()              // 2nd attempt: 1 player, multiple rounds
{
    int number = 10;    // The answer is fixed beforehand
    int guess;

    do                  // Add a loop to implement multiple rounds
    {            
        cout << "Player 1, please enter your guess:" << endl;
        cin >> guess;

        if (guess == number)
            cout << "Player 1, you win!!!" << endl;

        else if (guess < number)
            cout << "Sorry, the number is bigger than "
                 << guess << endl;
        else 
            cout << "Sorry, the number is smaller than "
                 << guess << endl; 
    } while (guess != number);  

    return 0;
}
