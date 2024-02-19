#include "int-stack.h" /* File: int-stack-test.cpp */

void print_stack_info(const int_stack& s)
{
    cout << "No. of data currently on the stack = " << s.size() << "\t";
    if (!s.empty())
        cout << "Top item = " << s.top();
    cout << endl << "Empty: " << boolalpha << s.empty()
         << "\t\t" << "Full: " << boolalpha << s.full() << endl << endl;
}
    
int main()	
{
    int_stack a; print_stack_info(a);
    a.push(4);   print_stack_info(a);
    a.push(15);  print_stack_info(a);
    a.push(26);  print_stack_info(a);
    a.push(37);  print_stack_info(a);
    a.pop();     print_stack_info(a);
    a.push(48);  print_stack_info(a);
    a.push(59);  print_stack_info(a);

    return 0; 
} /* compile: g++ -L. -o int-stack-test int-stack-test.cpp -lintstack */
