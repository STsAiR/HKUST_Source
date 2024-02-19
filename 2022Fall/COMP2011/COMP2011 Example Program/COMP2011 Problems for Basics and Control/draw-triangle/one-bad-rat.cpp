#include <iostream>     /* File: one-bad-rat.cpp */
using namespace std;

int main() 
{
    cout << "Size of a RAT: " << endl;
    int size;
    cin >> size;

    cout << "A simple RAT:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << '*';
        cout << endl;   
    }
    
    cout << "Is this a RAT?" << endl;
    for (int i = 1; i <= size; i++) 
        for (int j = 0; j < i * 2 - 1 ; j++)
        {
            cout << '*';
            cout << endl;
        }

    return 0;
}


