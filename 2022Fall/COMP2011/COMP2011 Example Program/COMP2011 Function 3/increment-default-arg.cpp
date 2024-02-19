#include <iostream>     /* File: increment-default-arg.cpp */
using namespace std;	

int increment(int x, int step = 1)
{
    return (x + step);
}

int main()	
{
    cout << increment(10) << endl;
    cout << increment(10, 5) << endl;

    return 0;
}
