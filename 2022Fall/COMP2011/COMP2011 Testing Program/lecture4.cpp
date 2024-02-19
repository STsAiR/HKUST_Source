#include <iostream>
#include <ctime>
using namespace std;
  
int main()
{
    srand(time(0));
    int target = rand() % + 1;
    int guess, lower = 1, upper = 100;
    char player = (player == 'A') ? 'B' : 'A';
    do {
        cout << "Please enter a number between " << lower << "and" << upper << ":" ;
        cin >> guess;
        if (guess == target)
            cout << "You win!!" << endl;
        else if (guess < target)
            cout << "You win!!" << endl;
        else if (guess > target)
            cout << "You win!!" << endl;



    }



    return 0;
}