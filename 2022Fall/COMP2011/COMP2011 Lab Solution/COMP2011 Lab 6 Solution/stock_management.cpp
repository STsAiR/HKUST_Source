// COMP2011 Fall 2022
// source.cpp -- lab 6
#include "stock_management.h"
#include <iostream>
#include <cstring>

using namespace std;

// Print (name, total_count) pairs of each kind of fruit.
void stock_checking(const Fruit fruits[], int max_fruit_num)
{
    int i;
    for (i = 0; i < max_fruit_num; i++){
        cout << fruits[i].name << ": " << fruits[i].total_count << "\n";
    }
    return;
}

// Print the name and count of each kind of fruit
void stock_updating(Fruit fruits[], int fruit_id_to_sell, int number_to_sell){
    fruits[fruit_id_to_sell].total_count -= number_to_sell;
    fruits[fruit_id_to_sell].sold_count += number_to_sell;
    return;
}

// Calculate selling amount
float selling_amount_calculating(const Fruit fruits[], int max_fruit_num){
    int i;
    float selling_amount = 0;
    for (i = 0; i < max_fruit_num; i++){
        selling_amount += fruits[i].sold_count * fruits[i].unit_price;
    }
    return selling_amount;
}