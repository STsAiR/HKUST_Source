#include<iostream>
using namespace std;

void f(int x2, int& y2) // int& means pass by reference and linking the variables
{
    cout << endl << "Inside f(int, int&)" << endl;
    cout << "x2 = " << x2 << '\t' << "address of x2 = " << &x2 << endl;
    cout << "y2 = " << y2 << '\t' << "address of y2 = " << &y2 << endl;

}

int f()	
{
    int x1 = 10, x2 = 20;  
    int *p1 = &x1;      // p1 now points to x1
    int *p2 = &x2;      // p2 now points to x2
    cout << "x1 = " << x1 << '\t' << "&x1 = " << &x1 << endl;
    cout << "x2 = " << x2 << '\t' << "&x2 = " << &x2 << endl;
    cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;
    *p1 = 5;            // now x1 = 5
    *p2 += 1000;        // now x2 = 1020
    *p1 = *p2;          // now *p1 = *p2 = x1 = x2 = 1020, but p1 != p2
    p1 = p2;            // now p1 and p2 both point to x2
    
    cout << "x1 = " << x1 << '\t' << "&x1 = " << &x1 << endl;
    cout << "x2 = " << x2 << '\t' << "&x2 = " << &x2 << endl;
    cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;

    return 0;
}




int* create(){ // return the pointer by value(address)
    int* temp = nullptr; temp = new int;
    return temp; // end of scope of temp, but then it return the pointer to ptr.
}


void destroy(int*& p){
    delete p;
    p = nullptr;
}


struct 11_cnode{ // node of a linked list, store char
    char data;
    11_cnode* next;

};


11_cnode* create_note(char c){
    11_cnote* temp = new 11_cnode; temp -> data = c; temp -> next = nullptr;
    return temp;
}


void print_list(11_cnode* head){ // head means the first of the the link
    for (11_cnode* p = node1; p != nullptr; p = p-> next)
        cout << p -> data << ",";
}



int main(){
    // x++++ cant be compiled
    // ++++x can be compiled
    int x = 10; int* y = &x; // y now contains the address of x
    cout << "x = " << x << '\t' << "address of x = " << &x << endl; // means getting the address of x
    cout << "y = " << y << '\t' << "address of y = " << &y << endl; // now y is storin the address of x but y also have a different address

    // if variiable y stores the address of variable x, we say y points to x
    // y is a pointer variable


    // *<pointer variable> means get the content through a pointer variable

    int z = *y ; // means get the content from the address stored in y, put it into z
    cout << "z = " << z << '\t' << "address of z = " << &z << endl; 

    f();

    // pointer can point to different char, int, short, array, struct, another pointer and even a function, which is functino pointer
    // pointer to a constant object:
    // const <type>* <pointer variable>;
    // channel is locked, can point to other variable, but cant change value throught the pointer. value can change directly from the variable

    // constant pointer:
    // <type>* const <pointer variable> = &<another variable>;
    // can change the pointing value, but the point is always pointing to the same variable and cannot be changed.



    //////

    // most variables are static memory allocation 
    // when go out of their scope, the memory will be released to RAM autometically

    // dynamic object -- on-the-fly at runtime
    // the dynamic objects will persist will be there forever if we didnt deleted them
    // therefore we need to deleted them when we dont need it anymore
    // static objects are managed using a data structure called stack.
    // Dynamic objects are managed using a data structure called heap.


    // stack goes from higher address to lower address
    // heap goes from lower address to higher address

    // syntax for dybamic memory allocation using "new"
    // <type>*<pointer-variable> = new <type>;
    //e.g.
    int* ip = new int;
    *ip = 5;

    int x2 = 0;
    char c = '\0'; // initiallization
    int *ptr = nullptr; // it means ptr point to nothing // it is still a static object
                        // NULL, 0




    // ptr = new int; // dynamic memory allocation
    // another version:

    ptr = create();

    *ptr = 10; // now *ptr is a integer variable

    cout << ptr << "\t" << &ptr << "\t" << *ptr;


    //delete ptr; //dynamic memory deallocation
    // ptr = nullptr; // the memory of ptr will only be deleted when it reached the end of rhe scope
    // another version:
    destroy(ptr);

    //////

    11_cnode* node1 = create_node('c');

    node1 -> next = create_node('s');
    node1 -> next -> next = create_node('e');
    // link the 3 nodes







    cout << node1->data << "\t" << node1 -> next -> data << "\t" // ''c

        << node1 -> next -> next -> data << endl; //'e'
        // still need to add 











    return 0;
}