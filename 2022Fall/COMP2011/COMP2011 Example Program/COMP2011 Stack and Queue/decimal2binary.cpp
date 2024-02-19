#include "int-stack/int-stack.h" /* File: decimal2binary.cpp */
 
int main()  // Convert +ve decimal number to binary number using an stack
{
    int_stack a;
    int x, number;
    
    while (cin >> number)
    {   // Conversion: decimal to binary
        for (x = number; x > 0; x /= 2) 
            a.push(x % 2);

        // Print a binary that is stored on a stack
        cout << number << "(base 10) = "; 
        while (!a.empty())
        {
            cout << a.top(); 
            a.pop();
        }
        cout << "(base 2)" << endl;
    }
    
    return 0; 
} // Compile: g++ -o decimal2binary -Lint-stack decimal2binary.cpp -lintstack
