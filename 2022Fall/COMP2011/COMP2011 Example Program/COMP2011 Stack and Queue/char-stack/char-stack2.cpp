#include "char-stack.h" /* File: char-stack2.cpp */

        /***** MUTATOR member functions *****/
void char_stack::push(char x) // Add a new item to the top of the stack
{
    if ( !full( ) )
        data[++top_index] = x;
    else
    {
        cerr << "Error: Stack is full; can't add (" << x << ")!" << endl;
        exit(-1);
    }
}

void char_stack::pop(void) // Remove the top item from the stack
{
    if ( !empty( ) )
        --top_index;
    else
    {
        cerr << "Error: Stack is empty; can't remove any data!" << endl;
        exit(-1);
    }
}
