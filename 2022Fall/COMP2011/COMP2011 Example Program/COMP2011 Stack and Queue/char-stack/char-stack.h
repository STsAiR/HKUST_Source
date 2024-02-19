#include <iostream> /* File: char-stack.h */
#include <cstdlib>
using namespace std;
const int BUFFER_SIZE = 5;

class char_stack
{
  private:
    char data[BUFFER_SIZE]; // Use an array to store data
    int top_index; // Starts from 0; -1 when empty

  public:
    // CONSTRUCTOR member functions
    char_stack(void); // Default constructor

    // ACCESSOR member functions: const => won't modify data members
    bool empty(void) const; // Check if the stack is empty
    bool full(void) const; // Check if the stack is full
    int size(void) const; // Give the number of data currently stored
    char top(void) const; // Retrieve the value of the top item

    // MUTATOR member functions
    void push(char); // Add a new item to the top of the stack
    void pop(void); // Remove the top item from the stack
};
