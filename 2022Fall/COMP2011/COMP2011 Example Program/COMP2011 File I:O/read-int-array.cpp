#include <iostream>     /* File: read-int-array.cpp */
#include <fstream>
using namespace std;	

/* Expected input file format: 
 * array size on the first line, followed by the array elements.
 */
int main()
{
    const int MAX_SIZE = 128;
    int x[MAX_SIZE];    // An integer array
    char ip_file[32];   // Input filename
    
	// Open the file to read
    cout << "Enter the input filename: "; cin >> ip_file;
    ifstream ifs(ip_file); // One way to create a fstream object

    if (!ifs) 
    { cerr << "Error: Can't open \"" << ip_file << "\"\n"; return -1; }
    
    int array_size; ifs >> array_size;
    if (array_size > MAX_SIZE)
    { 
        cerr << "Error: array size (" << array_size 
             << ") > max size of array (" << MAX_SIZE << ")\n"; 
        return -1;
    }

    // Read in the array
    for (int j = 0; j < array_size; j++)
        ifs >> x[j];
    
    // Print the array to screen
    for (int j = 0; j < array_size; j++)
        cout << x[j] << endl;
    
    ifs.close( ); // Close input file stream
    return 0;
}
