#include <iostream>                       //gpa.cpp
using namespace std;

const int A = 4;
const int B = 3;
const int C = 2;
const int D = 1;
const int F = 0;

int main() 
{
    char grade;
    int grade_point = 0;
    int credit = 0, total_credit = 0;
    do 
    {
        cout << "Credit of your course (0 to stop):";
        cin >> credit;
        if (credit <= 0)
            break;
        total_credit += credit;
        cout << "Your letter grade: A B C D F:";
        cin >> grade;
        switch (grade) 
        {
            case 'A':  //no break here, execute code in case 'a'
            case 'a':  grade_point += credit * A;
                       break;  
            case 'B':
            case 'b':  grade_point += credit * B;
                       break;
            case 'C':
            case 'c':  grade_point += credit * C;
                       break;
            case 'D':
            case 'd':  grade_point += credit * D;
                       break;
            case 'F':
            case 'f':  grade_point += credit * F;
                       break;
            default :  cout << "Invalid input" << endl;
                       total_credit -= credit;
        }
    } while (true);   //why this is not an infinite loop?

    cout << "Your have totally taken " << total_credit 
         << " credits." << endl << "Your GPA is " 
         << grade_point / total_credit << endl;

    return 0;
}
