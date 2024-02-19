#include <iostream>     /* File: various-rats.cpp */
using namespace std;

int main() 
{
    cout << "Size of a RAT: " << endl;
    int size;                              // height = width = size
    cin >> size;

    cout << "A fat RAT" << endl;
    for (int i = 1; i <= size; i++)        // #iterations = height
    {
        for (int j = 0; j < i*2 - 1 ; j++) // width of a row
            cout << '*';
        cout << endl;   
    }

    cout << "A hollow RAT" << endl;
    for (int i = 1; i <= size; i++) 
    {
        for (int j = 0; j < i ; j++)
            cout << ((j == 0 || j == i - 1 || i == size) ? '*' : ' ');
        cout << endl;   
    }


    cout << "An upside-down RAT" << endl;
    for (int i = size; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << endl;
    }

    return 0;
}


