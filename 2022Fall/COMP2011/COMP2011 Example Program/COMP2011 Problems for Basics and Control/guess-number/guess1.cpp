#include <iostream>     /* File: guess1.cpp */ 
using namespace std;

int main()              // 1st attempt: 1 player, 1 round 
{
    int number = 10;    // The answer is fixed beforehand
    int guess;

    cout << "Player 1, please enter your guess:" << endl;
    cin >> guess;

    if (guess == number)
        cout << "Player 1, you win!!!" << endl;

    else if (guess < number)
        cout << "Sorry, the number is bigger than " << guess << endl;

    else 
        cout << "Sorry, the number is smaller than " << guess << endl; 

    return 0;
}
