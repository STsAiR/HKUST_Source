#include <iostream>
using namespace std;
 
int main()
{
    /*
        There are 6 errors in total. Can you catch them all? :)
 
        See the expected output section on the lab page to see what is expected from the corrected program.
    */
 
    int number; // error1: missing ;
    cout << "Welcome to the exciting, fun, and awesome programming world! "
         << "Enter an odd number, and I can tell something about you! " << endl; // error2: missing <<
    cin >> number; // error3: >> should be used for cin
 
    if (number % 2 == 0) // error4: == should be used to compare, = is used for assignment
        cout << "Hmm... this is not an odd number..." << endl;
    else
    {
        if (number < 0) // error5: number (instead of num) should be used
            cout << "You seem to be a bit negative... :( Cheer up! " << endl;
        else
            cout << "You must be very excited! Me too! :)" << endl;
    } // error6: missing } in the code
 
    return 0;
}