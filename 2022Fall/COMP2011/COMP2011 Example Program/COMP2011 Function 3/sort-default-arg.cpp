#include <iostream>     /* File: sort-default-arg.cpp */
using namespace std;	

enum sort_order {ASCENDING, DESCENDING};

void swap(int& a, int& b) { int temp = a; a = b; b = temp; }

void sort(int& x, int& y, sort_order order = ASCENDING)
{
    if (order == ASCENDING) { if (x > y) swap(x, y); }
    else { if (x < y) swap(x, y); }
}

int main()	
{
    int a = 24, b = 8;
    sort(a, b); cout << a << '\t' << b << endl;
    sort(a, b, DESCENDING); cout << a << '\t' << b << endl;
    return 0;
}
