// COMP2011 Fall 2022
// skeleton.cpp -- lab 6

#include "stock_management.h"

int main() {
    Fruit fruits[MAX_FRUIT_NUM] = {{"Apple", 5, 50, 0}, 
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


