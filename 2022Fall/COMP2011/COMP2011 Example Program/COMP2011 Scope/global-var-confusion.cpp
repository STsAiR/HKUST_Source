#include <iostream>     /* File: global-var-confusion.cpp */
using namespace std;	

int number; // Definition of the global variable, number, with FILE scope. It is initialized to 0.

void increment_pbv(int x) 
{
    x++;                // x is a local variable with a FUNCTION scope
    cout << "x = " << x << endl;

    number++; // global variable, number, used in the function, void increment_pbv(int)
}

void increment_pbr(int& y) 
{   
    y++;              // y is a local reference variable with a FUNCTION scope
    cout << "y = " << y << endl;

    number++; // global variable, number, used in the function, void increment_pbr(int&)
}

int main()	
{   
    increment_pbv(number); // global variable, number, used in the function, int main()
    cout << "number = " << number << endl;

    increment_pbr(number);  // global variable, number, used in the function, int main()
    cout << "number = " << number << endl;
    return 0;
}
