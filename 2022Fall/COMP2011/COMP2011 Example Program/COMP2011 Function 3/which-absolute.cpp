#include <iostream>     /* File: which absolute.cpp */
using namespace std;

int absolute(int a) { cout << "version 1: "; return (a < 0) ? -a : a; }
int absolute(int& a) { cout << "version 2: "; return (a = (a < 0) ? -a : a); }

int main()
{
    int x = -456;

    cout << absolute(-234) << endl; // Which absolute function is called?
    cout << absolute(x) << endl;    // Which absolute function is called?

    return 0;
}
