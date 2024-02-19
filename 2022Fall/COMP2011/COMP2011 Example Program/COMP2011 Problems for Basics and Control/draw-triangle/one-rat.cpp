#include <iostream>     /* File: one-rat.cpp */
using namespace std;

int main() 
{
    cout << "Size of a RAT: " << endl;
    int size;                           // height = width = size
    cin >> size;

    for (int width = 1; width <= size; width++) // #iters=height
    {
        // Draw one row of a RAT
        for (int j = 0; j < width ; j++)       // width of a row
            cout << '*';

        cout << endl;   
    }

    return 0;
}


