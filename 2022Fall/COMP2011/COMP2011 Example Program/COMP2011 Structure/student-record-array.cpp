#include <iostream>     /* File: student-record-array.cpp */
using namespace std;
#include "student-record-functions.cpp"

int main() 
{
    Student_Record sr[] = {
        { "Adam",  12000, 'M', CSE,  { 2006, 1, 10 } },
        { "Bob",   11000, 'M', MATH, { 2005, 9, 1  } },
        { "Cathy", 10000, 'F', ECE,  { 2006, 8, 20 } }
    };
    
    for (int j = 0; j < sizeof(sr)/sizeof(Student_Record); ++j)
        print_student_record(sr[j]);

    return 0;
}
