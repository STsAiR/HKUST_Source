// Similar idea as the previous lab6

const int   FRUIT_NUM = 5;
const int   TRAIT_NUM = 5;
const int   MAX_CUSTOMER_NUM = 5;
const int   MAX_LENGTH = 50;

struct Fruit {
   const char*  name;
   int          unit_price;
   int          total_count;
   int          sold_count; // implicit constraint, this amount shall not be larger than sold_count
};

struct Customer {
    const char*     name;
    int             id; // recorded customer id
    bool            vip; // true if the customer is an VIP of the shop
    int             need[FRUIT_NUM]; // need for each fruit
    const char*     address; // address of the customer (for delivery), can be empty
    const char*     traits; // personality traits of the customer
};

void print_store(const Fruit [], int);
void print_queue(const Customer* const [], int);
void prapare_fruit(Fruit []);
void welcome_customer(Customer* []);
void delete_customer_record(Customer* [], int);

// TODOs, implement them in lab7.cpp
void reorder_customer(Customer* [], int);
int check_out(Fruit [], const Customer* const [], int, int);