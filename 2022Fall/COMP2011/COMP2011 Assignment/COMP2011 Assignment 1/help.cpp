#include <iostream>     /* File: filecopy.cpp */
#include <fstream>
using namespace std;	
int main(){
    int boxes2[MAX_BOXES]; 
    int prisoners_position = 0;
    int num_loop = 0;
    boxes2[0] = 10000;
    for (int i =0; i < num_prisoners; i++){
        if (boxes[i] == i) {
            boxes2[prisoners_position] = i;
            prisoners_position++;
            num_loop++;
            continue;
        }
        for (int j =0; j <=prisoners_position; j++){
            if (i == boxes2[j]) break;
        }
        temp = boxes[i];
        boxes2[prisoners_position] = boxes[i];
        prisoners_position++;
        while (boxes[temp] != i){
            boxes2[prisoners_position] = boxes[temp];
            prisoners_position++;
            temp = boxes[temp];
        }
        num_loop++;
    }
}
