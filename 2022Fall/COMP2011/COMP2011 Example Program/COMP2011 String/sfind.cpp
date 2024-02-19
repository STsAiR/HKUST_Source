#include <iostream>     /* File: sfind.cpp */
using namespace std;

int main()
{
    //index:  01234567890123456789012345678901234567890123
    string s("The rain in Spain stays mainly in the plain.");
    cout << s.length() << endl;

    int p1 = s.find("ain");     // Find the first "ain"
    int p2 = s.find("ain", 10); // First "ain" from the 10th char
    int p3 = s.find("ain", 20); // First "ain" from the 20th char
    int p4 = s.find("ain", 30); // First "ain" from the 30th char
    int p5 = s.find("ain", 50); // First "ain" from the 50th char
    cout << p1 << ' ' << p2 << ' ' << p3 << ' ' << p4 << ' ' << p5 << endl;

    s.replace(p1, 3, "hino"); cout << s << endl;
    cout << s.find("ain", 10) << endl; // First "ain" from the 10th char again
    return 0;
}
// 44
// 5 14 25 40 -1
// The rhino in Spain stays mainly in the plain.
// 15
