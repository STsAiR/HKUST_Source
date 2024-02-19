#include <iostream>     /* File: gpa.cpp */
using namespace std;

const double A = 4.0;   // Definition of Constants
const double B = 3.0;
const double C = 2.0;
const double D = 1.0;
const double F = 0.0;

int main() 
{   // Variables definition and initialization
    char grade;
    int num_credits, total_num_credits = 0;
    double total_grade_points = 0;

    do 
    {
        cout << "No. of credits of your course (0 to stop): ";
        cin >> num_credits;

        if (num_credits <= 0) // What does this do?
            break;

        cout << "Your letter grade (A, B, C, D or F): ";
        cin >> grade;
        total_num_credits += num_credits; // Update total no. of credits

        switch (grade)  // Convert letter grade to grade point
        {
            case 'A':   // No break here; execute code in case 'a'
            case 'a':
                total_grade_points += num_credits * A; break;  
            case 'B':
            case 'b':
                total_grade_points += num_credits * B; break;
            case 'C':
            case 'c':
                total_grade_points += num_credits * C; break;
            case 'D':
            case 'd':
                total_grade_points += num_credits * D; break;
            case 'F':
            case 'f':
                total_grade_points += num_credits * F; break;
            default :
                cout << "Invalid input, please enter your grade again!\n";
                total_num_credits -= num_credits;
        }
    } while (true);     // Why is this not an infinite loop?


    cout << "You have taken a total of " << total_num_credits 
         << " credits ..." << endl << "and your GPA is " 
         << total_grade_points / total_num_credits << endl;

    return 0;
}
