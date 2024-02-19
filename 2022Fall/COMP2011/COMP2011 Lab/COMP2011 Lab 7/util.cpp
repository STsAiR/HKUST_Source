#include <iostream>
#include <fstream>
#include "lab7.h"

using namespace std;

const char* FRUIT_NAME[FRUIT_NUM] = {"Apple", "Banana", "Strawberry", "Peach", "Watermelon"};

void print_store(const Fruit fruits[], int num_fruit) {
    for (int i=0; i<num_fruit; ++i) {
        cout << "Fruit: " << fruits[i].name << ", price: " << fruits[i].unit_price;
        cout << ", " << fruits[i].sold_count << "/" << fruits[i].total_count << " sold." << endl;
    }
}

void print_queue(const Customer* const queue[], int num_customer) {
    for (int i=0; i<num_customer; ++i) {
        const Customer* cur_customer = queue[i];
        cout << "Customer: "  << cur_customer->name << ", ID: " << queue[i]->id;
        cout << ", " << ((cur_customer->vip)?"VIP customer":"normal customer") << ", Need: ";
        for (int i=0; i<FRUIT_NUM; ++i) {
            cout << cur_customer->need[i] << " " << FRUIT_NAME[i]<< ", ";
        }
        cout << "lives at " << cur_customer->address << ", has trait " << cur_customer->traits << "." << endl;
    }
}

void prapare_fruit(Fruit fruits[]) {
    fruits[0] = {"Apple",       5,  50, 0};
    fruits[1] = {"Banana",      3,  30, 0};
    fruits[2] = {"Strawberry",  10, 40, 0};
    fruits[3] = {"Peach",       8,  30, 0};
    fruits[4] = {"watermelon",  30, 10, 0};
}

void welcome_customer(Customer* queue[]) {
    for (int i=0; i<MAX_CUSTOMER_NUM; ++i) {
        if (queue[i]!=nullptr) {
            delete queue[i];
            queue[i] = nullptr;
        }
    }
    queue[0] = new Customer{"AA", 1, true, {0, 12, 0, 10, 0}, "A1", "T1"};
    queue[1] = new Customer{"BB", 2, false, {0, 18, 0, 19, 4}, "A1", "T2"};
    queue[2] = new Customer{"CC", 3, false, {14, 13, 8, 13, 1}, "B2", "T3"};
    queue[3] = new Customer{"DD", 4, true, {13, 0, 0, 0, 6}, "B3", "T1"};
    queue[4] = new Customer{"EE", 5, false, {0, 0, 10, 0, 13}, "A3", "T2"};
}

void delete_customer_record(Customer* queue[], int num_customer) {
    for (int i=0; i<num_customer; ++i) {
        delete queue[i];
        queue[i] = nullptr;
    }
}