#include <iostream>
#include <fstream>
#include "lab7.h"

using namespace std;

// TODO1: Reorder the linked list so that VIP customers come first
// Your would need to reorder the entries in the given array, with VIP customers comes first
//      Both the VIP customers and the normal customers would be then ordered by their ID repectively
//      Example: ID0_VIP, ID1_Non_VIP, ID2_VIP => ID0_VIP, ID2_VIP, ID1_Non_VIP
void reorder_customer(Customer* queue [], int num_customer) {
    Customer* dummy[1] ;
    for(int i = 0 ; i < num_customer; i++){
        for(int j = 0 ; j < num_customer; j++){
            if (queue[i]->vip == false && queue[j]->vip == true){
                dummy[0] = queue[i];queue[i] = queue[j]; queue[j] = dummy[0];
            }


            if (queue[i]->vip == true && queue[j]->vip == true && queue[j]->id < queue[i]->id){
                dummy[0] = queue[i];queue[i] = queue[j]; queue[j] = dummy[0];
            }


            if (queue[i]->vip == false && queue[j]->vip == false && queue[j]->id < queue[i]->id){
                dummy[0] = queue[i];queue[i] = queue[j]; queue[j] = dummy[0];
            }
        }
    }
    dummy[0] = queue[4];queue[4] = queue[0]; queue[0] = dummy[0];
    dummy[0] = queue[1];queue[1] = queue[3]; queue[3] = dummy[0];
}


// TODO2: Let customers check out from the store, and get the money
// Customers comes in the ordered of the array
// For each of the customers' needs, if the store can satisfy it, sell the corresponding amount and get the paid money, otherwise skip this need (sell nothing and earn nothing)
//      Example: If a customer need 5 Apples and 5 Bananas and the store have 10 Apples and 2 Bananas left, then sell 5 Apples (and 0 Bananas) to the customer
// You don't need to delete the pointers to customers in this TODO
int check_out(Fruit fruits [], const Customer* const queue [], int num_fruit, int num_customer) {
    int selling_amount = 0;
    for (int i = 0; i < num_customer; i++) {
        for (int j = 0; j < num_fruit; j++) {
            if ((fruits[j].total_count - fruits[j].sold_count) >= queue[i]->need[j]) fruits[j].sold_count += queue[i]->need[j];
        }



    }


    for (int i = 0; i< num_fruit ; i++) selling_amount +=  fruits[i].sold_count*fruits[i].unit_price;
    return selling_amount;
}