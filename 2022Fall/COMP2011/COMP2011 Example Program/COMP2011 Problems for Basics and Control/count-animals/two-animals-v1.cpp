#include <iostream>     /* File: two_animals-v1.cpp */
using namespace std;

int main() 
{
    float wt_pig = 4.5;
    float wt_sheep = 3.0;
    float total_wt = 36;
    
    for (int num_pigs = 0; num_pigs * wt_pig <= total_wt; num_pigs++) 
    {
        float remain_wt = total_wt - num_pigs * wt_pig;
        int num_sheeps = remain_wt / wt_sheep;
        remain_wt = remain_wt % wt_sheep;
        
        if (remain_wt == 0) 
            cout << num_pigs << " * " << wt_pig << " + " 
                 << num_sheeps << " * " << wt_sheep << " = "
                 << total_wt << endl;
    }
    return 0;
}
