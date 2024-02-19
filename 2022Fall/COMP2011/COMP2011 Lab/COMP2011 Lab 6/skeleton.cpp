// COMP2011 Fall 2022
// skeleton.cpp -- lab 6

#include <iostream>
using namespace std;
const unsigned int MAX_FRUIT_NUM = 5;
const int MAX_LENGTH = 50;

// A struct that contains all the information about a type of fruit.
struct Fruit
{
   char  name[MAX_LENGTH];
   float unit_price;
   int   total_count;
   int   sold_count;
};

// Print the name and count of each kind of fruit
void stock_checking(const Fruit fruits[], int max_fruit_num)
{   
    //todo: print (name, total_count) pairs of each kind of fruit.
    //For example the last printed line should be watermelon: 10
    for (int i = 0; i< max_fruit_num ; i++){
        cout << fruits[i].name << ": " << fruits[i].total_count;
    }


    return;
}

// Update stock info and print (name, total_count) pairs of each kind of fruit.
void stock_updating(Fruit fruits[], int fruit_id_to_sell, int number_to_sell){
    //todo: update total_count of the sold fruit
    fruits[fruit_id_to_sell].total_count -= number_to_sell;
    fruits[fruit_id_to_sell].sold_count += number_to_sell;
    
    return;
}

// Calculate selling amount
float selling_amount_calculating(const Fruit fruits[], int max_fruit_num){
    float selling_amount = 0;
    // todo: calculate selling amount of all fruits; for each fruit this number should be the multiplication of unit price and sold count
    for (int i = 0; i< max_fruit_num ; i++){
        selling_amount = selling_amount + fruits[i].sold_count*fruits[i].unit_price;
    }

    return selling_amount;
}
int main() {
    struct Fruit fruits[MAX_FRUIT_NUM] = {{"Apple", 5, 50, 0}, 
                                          {"Banana", 3, 30, 0},
                                          {"Strawberry", 10, 40, 0},
                                          {"Peach", 8, 30, 0},
                                          {"watermelon",30, 10, 0}};
    int number_of_each_fruits[MAX_FRUIT_NUM];
    unsigned int fruit_id_to_sell, number_to_sell, selling_amount;

    int reply;

    do {
        cout << "===========================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Check stock" << endl;
        cout << "2: Sell" << endl;
        cout << "3: Calculate selling amount" << endl;
        cout << "4: Quit" << endl;
        cin >> reply;

        switch(reply) {
        case 1:
            stock_checking(fruits, MAX_FRUIT_NUM);
            break;
        case 2:
            cout << "Please enter the id of a fruit bought by a customer: \n" ;
            cout << "0: Apple; 1: Banana; 2: Strawberry; 3: Peach; 4: watermelon \n";
            cin >> fruit_id_to_sell;
            cout << "How many are sold?\n";
            cin >> number_to_sell;
            stock_updating(fruits, fruit_id_to_sell, number_to_sell);
            stock_checking(fruits, MAX_FRUIT_NUM);
            break;
        case 3:
            selling_amount = selling_amount_calculating(fruits, MAX_FRUIT_NUM);
            cout << "Selling amout of the day is: " << selling_amount << " HKD!!!\n";
            break;
        default:
            break;
        }

    } while (reply != 4);

    return 0;
}


