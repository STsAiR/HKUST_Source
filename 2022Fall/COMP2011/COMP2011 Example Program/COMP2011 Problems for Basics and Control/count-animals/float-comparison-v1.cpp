#include <iostream>     /* File: float-comparison-v1.cpp */
using namespace std;

int main() 
{
    float x = 0.1;
    float product = 10.0 * x;
    
    float sum = 0.0;
    for (int i = 0; i < 10; ++i)
        sum += x;
    
    cout << "sum = " << sum << endl;
    cout << "product = " << product << endl;
    cout << "10.0 * x = " << 10.0 * x << endl;
    cout << (sum == product) << endl;

    return 0;
}
