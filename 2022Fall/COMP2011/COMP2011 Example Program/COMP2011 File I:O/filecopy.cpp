#include <iostream>     /* File: filecopy.cpp */
#include <fstream>
using namespace std;	
int main()
{
    char ip_file[32], op_file[32]; // Input and output filename

    cout << "Enter the input filename: "; cin >> ip_file;
    ifstream ifs(ip_file); // One way to create a fstream object
    if (!ifs)
    { cerr << "Error: Can't open \"" << ip_file << "\"\n"; return -1; }
    
    cout << "Enter the output filename: "; cin >> op_file;
    ofstream ofs; ofs.open(op_file); // Another way to create a fstream object
    if (!ofs)
    { cerr << "Error: Can't open \"" << op_file << "\"\n"; return -1; }

    char c; ifs.get(c); // Try to get the first char
    while (!ifs.eof())  // Check if EOF is reached
    {
        ofs.put(c);     // Copy one char at a time
        ifs.get(c);     // Try to get the next char
    }
    ifs.close(); ofs.close(); return 0; // Close input/output file streams
}
