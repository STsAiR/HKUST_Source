#include <iostream>             //three_animals.cpp
using namespace std;
//assume the weight of the three types of animals are 4.5, 3, and 2.5 units
int main()
{
    double w1 = 4.5, w2 = 3, w3 = 2.5;
    double total = 36;
    for (int k = 0; k * w3 < total; k++) //an extra loop k is added
    {
        double remaining1 = total - k * w3; //total $\rightarrow$ remaining1
        for (int i = 0; i * w1 < remaining1; i++) 
        {
            double remaining = remaining1 - i * w1;
            int j = 0;
            for (; remaining > 0; j++) 
                remaining -= w2;
            if (remaining == 0) 
                cout << i << " * " << w1 << " + " 
                    << j << " * " << w2 << " + "
                    << k << " * " << w3 << " = "
                    << total << endl;
        }
    }
}
