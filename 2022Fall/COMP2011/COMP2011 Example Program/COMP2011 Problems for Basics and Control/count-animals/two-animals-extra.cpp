#include <iostream>                     //two_animals_extra.cpp
using namespace std;
//Assume there are not more than 10 animals in the farm.
int main() 
{
    double w1 = 4.5;
    double w2 = 3;
    double total = 36;
    int not_more_than = 10;    
    for (int i = 0; i * w1 < total; i++) 
    {
        double remaining = total - i * w1;
        int j = 0;
        for (; remaining > 0; j++) 
            remaining -= w2;
        if (remaining == 0 && (i + j) <= not_more_than) 
            cout << i << " * " << w1 << " + " 
                 << j << " * " << w2 << " = "
                 << total << endl;
    }
}
