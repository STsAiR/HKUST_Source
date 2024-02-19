#include<iostream>
using namespace std;



int main(){
    int x[3][4];
    int ** y = new int*[3];
    for (int j = 0; j<3 ; j++) y[j] = new int [4];
    cout << sizeof(x)/sizeof(int)  << endl;
    cout << sizeof(y[0][1])  << endl;


    return 0;

}