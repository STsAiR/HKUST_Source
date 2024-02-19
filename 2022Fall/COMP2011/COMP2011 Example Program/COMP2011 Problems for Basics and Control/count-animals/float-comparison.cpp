#include <iostream>     /* File: float-comparison.cpp */
using namespace std;

int main() 
{
    float x = 0.1;
    float product = 10.0 * x;
    
    float sum = 0.0;
    for (int i = 0; i < 10; ++i)
        sum += x;
    
    // Set output precision to 10 significant figures 
    cout.precision(10);
    // Print boolean outputs as true or false instead of 1 and 0
    cout << boolalpha;  // boolean + alpha
    
    cout << "sum = " << sum << endl;
    cout << "product = " << product << endl;
    cout << "10.0 * x = " << 10.0 * x << endl;
    cout << (sum == product) << endl; 
    return 0;
}
