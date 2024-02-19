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

void stock_checking(const Fruit fruits[], int max_fruit_num);
void stock_updating(Fruit fruits[], int fruit_id_to_sell, int number_to_sell);
float selling_amount_calculating(const Fruit fruits[], int max_fruit_num);
