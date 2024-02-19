#include "char-stack.h" /* File: char-stack1.cpp */

          /***** Default CONSTRUCTOR member function *****/
char_stack::char_stack(void) { top_index = -1; } // Create an empty stack

          /***** ACCESSOR member functions *****/
// Check if the char_stack is empty
bool char_stack::empty(void) const { return (top_index == -1); }

// Check if the char_stack is full
bool char_stack::full(void) const { return (top_index == BUFFER_SIZE-1); }

// Give the number of data currently stored
int char_stack::size(void) const { return top_index+1; }

// Retrieve the value of the top item
char char_stack::top(void) const
{
    if ( !empty( ) )
        return data[top_index];

    cerr << "Warning: Stack is empty; can't retrieve any data!" << endl;
    exit(-1);
}
