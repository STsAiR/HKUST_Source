#include "char-stack.h" /* File: char-stack-test.cpp */

void print_stack_info(const char_stack& s)
{
    cout << "No. of data currently on the stack = " << s.size( ) << "\t";
    if ( !s.empty( ) ) cout << "Top item = " << s.top( );
    cout << endl << "Empty: " << boolalpha << s.empty( );
    cout << "\t\t" << "Full: " << boolalpha << s.full( ) << endl;
}
    
int main(void)	
{
    char_stack a; print_stack_info(a);
    a.push('q'); print_stack_info(a);
    a.push('u'); print_stack_info(a);
    a.push('i'); print_stack_info(a);
    a.push('t'); print_stack_info(a);
    a.pop( ); print_stack_info(a);
    a.push('t'); print_stack_info(a);
    a.push('e'); print_stack_info(a);

    return 0; 
} /* compile: g++ -L. -o char-stack-test char-stack-test.cpp -lcharstack */
