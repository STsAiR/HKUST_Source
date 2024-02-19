#include<iostream>
#include "lab7.h"

using namespace std;

int main() {
    Fruit fruits[FRUIT_NUM] = {};
    Customer* queue[MAX_CUSTOMER_NUM] = {nullptr};

    int reply = 0;

    // store opening
    do {
        cout << "===========================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Prepare fruits" << endl;
        cout << "2: Welcome customers" << endl;
        cout << "3: Give VIP priorities" << endl;
        cout << "4: Let all customers check out" << endl;
        cout << "5: Quit" << endl;
        cin >> reply;

        switch(reply) {
        case 1:
            prapare_fruit(fruits);
            break;
        case 2:
            welcome_customer(queue);
            print_queue(queue, MAX_CUSTOMER_NUM);
            break;
        case 3:
            reorder_customer(queue, MAX_CUSTOMER_NUM);
            print_queue(queue, MAX_CUSTOMER_NUM);
            break;
        case 4:
            cout << "Revenue: " << check_out(fruits, queue, FRUIT_NUM, MAX_CUSTOMER_NUM) << endl;
            print_store(fruits, FRUIT_NUM);
            break;
        default:
            delete_customer_record(queue, MAX_CUSTOMER_NUM);
            break;
        }

    } while (reply != 5);
}