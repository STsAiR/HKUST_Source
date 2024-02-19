#include<iostream>
using namespace std;
int main(){
    int x = 10, y = 11;
    int array[x*y];
    for (int i = 0; i<10; i++) cout << array[i] << endl;
    cout << sizeof(array)/sizeof(int) << endl;

}

    // construct the branch
    for (int count1 =0; count1 < NUM_ROWS*NUM_COLS*8; count1++) {
        count1 = 0;
        for (int i =0; i < NUM_ROWS*NUM_COLS*8; i++) {
            if (tempScore[i][0] == -100) continue;
            if (tempScore[count1][3] == tempScore[i][3] &&tempScore[count1][4] == tempScore[i][4] && tempScore[count1][0] > tempScore[i][0] ){
                tempScore[count1][0] = tempScore[i][0];
            }
        }
    }   

    // default case for max score
    if (maxScore == 0){
        for (int i =0; i < NUM_ROWS*NUM_COLS*8; i++) {
            if (tempScore[i][0] == -100) continue;
            if (tempScore[i][0] == 0){
                maxDistinationCol = tempScore[i][1];
                maxDistinationRow = tempScore[i][2];
                maxStartCol = tempScore[i][3];
                maxStartRow = tempScore[i][4];
                break;
            }
        }
    }
