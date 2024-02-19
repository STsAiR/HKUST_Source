// COMP2011 Fall 2022
// skeleton.cpp -- lab 8
#include <iostream>
using namespace std;
const int MAX_LENGTH = 50;
#include <string.h>

class Fruit
{
private:
    int id;
    char name[MAX_LENGTH];
    float unit_price;
    int   total_count;
    int   sold_count;
    Fruit* next;
public:
    Fruit(int id_, const char* name_, float unit_price_, int total_count_, int sold_count_, Fruit* next_);
    void print() const;
    int get_id()  const { return id; }
    const char* get_name() const { return name; }
    float get_unit_price() const { return unit_price; }
    int get_total_count() const { return total_count; }
    int get_sold_count() const { return sold_count; }
    Fruit* get_next() const { return next; }
    void set_total_count(int x){total_count = x;}
    void set_sold_count(int x){sold_count = x;}
    void set_next(Fruit* x){next = x;}

};
Fruit::Fruit(int id_, const char* name_, float unit_price_, int total_count_, int sold_count_, Fruit* next_){
    id = id_;
    strcpy(name, name_);
    unit_price = unit_price_;
    total_count = total_count_;
    sold_count = sold_count_;
    next = next_;
}
void Fruit::print() const {
    cout << name << ": " << total_count << "\n";
}


class FruitStore
{
private:
    Fruit* all_fruits=nullptr;
public:
    void warehousing(Fruit* fruit);
    void stock_checking() const;
    void stock_updating(int fruit_id_to_sell, int number_to_sell);
    float selling_amount_calculating() const;

};


// Append each fruit class to the pointer
void FruitStore::warehousing(Fruit* fruit){
    if (all_fruits == nullptr){
        all_fruits = fruit;
    }
    else {
        Fruit* cur_fruit = all_fruits;
        while(cur_fruit -> get_next() != nullptr){
            cur_fruit = cur_fruit->get_next();
        }
        cur_fruit->set_next(fruit);
    }
}

// Print (name, total_count) pairs of each kind of fruit.
void FruitStore::stock_checking() const {
    Fruit* cur_fruit = all_fruits;
    while(cur_fruit != nullptr){
        cur_fruit -> print();
        cur_fruit = cur_fruit->get_next();
    }

}
// Print the name and count of each kind of fruit
void FruitStore::stock_updating(int fruit_id_to_sell, int number_to_sell){
    Fruit* cur_fruit = all_fruits;
    while(cur_fruit != nullptr){
        if (cur_fruit -> get_id() == fruit_id_to_sell){
            cur_fruit -> set_total_count(cur_fruit -> get_total_count() - number_to_sell);
            cur_fruit -> set_sold_count(cur_fruit -> get_sold_count() + number_to_sell);
            break;
        }
        cur_fruit = cur_fruit->get_next();
    }
    return;
}

// Calculate selling amount
float FruitStore::selling_amount_calculating() const{
    float selling_amount = 0;
    Fruit* cur_fruit = all_fruits;
    while(cur_fruit != nullptr){
        selling_amount += cur_fruit -> get_sold_count() * cur_fruit -> get_unit_price();
        cur_fruit = cur_fruit->get_next();
    }
    return selling_amount;
}
int main() {

    // init FruitStore
    FruitStore fruitStore;
    // add frunts to fruitStore
    char  name1[MAX_LENGTH] = "Apple";
    Fruit fruit1(0,name1, 5, 50, 0, nullptr);
    fruitStore.warehousing(&fruit1);
    char  name2[MAX_LENGTH] = "Banana";
    Fruit fruit2(1, name2, 3, 30, 0, nullptr);
    fruitStore.warehousing(&fruit2);
    char  name3[MAX_LENGTH] = "Strawberry";
    Fruit fruit3(2, name3, 10, 40, 0, nullptr);
    fruitStore.warehousing(&fruit3);
    char  name4[MAX_LENGTH] = "Peach";
    Fruit fruit4(3, name4, 8, 30, 0, nullptr);
    fruitStore.warehousing(&fruit4);
    char  name5[MAX_LENGTH] = "watermelon";
    Fruit fruit5(4, name5, 30, 10, 0, nullptr);
    fruitStore.warehousing(&fruit5);


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
            fruitStore.stock_checking();
            break;
        case 2:
            cout << "Please enter the id of a fruit bought by a customer: \n" ;
            cout << "0: Apple; 1: Banana; 2: Strawberry; 3: Peach; 4: watermelon \n";
            cin >> fruit_id_to_sell;
            cout << "How many are sold?\n";
            cin >> number_to_sell;
            fruitStore.stock_updating(fruit_id_to_sell, number_to_sell);
            fruitStore.stock_checking();
            break;
        case 3:
            selling_amount = fruitStore.selling_amount_calculating();
            cout << "Selling amount of the day is: " << selling_amount << " HKD!!!\n";
            break;
        default:
            break;
        }

    } while (reply != 4);

    return 0;
}

