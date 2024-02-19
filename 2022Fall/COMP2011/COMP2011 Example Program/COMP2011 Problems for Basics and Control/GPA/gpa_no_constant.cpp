#include <iostream>                       //gpa.cpp
using namespace std;

int main() 
{
    char grade;
    double total_grade_points = 0;
    int credits = 0, total_credits = 0;
    do 
    {
        cout << "Credits of your course (0 to stop):";
        cin >> credits;
        if (credits <= 0)
            break;
        total_credits += credits;
        cout << "Your letter grade: A B C D F:";
        cin >> grade;
        switch (grade) 
        {
            case 'A':  //no break here, execute code in case 'a'
            case 'a':  total_grade_points += credits * 4.0;
                       break;  
            case 'B':
            case 'b':  total_grade_points += credits * 3.0;
                       break;
            case 'C':
            case 'c':  total_grade_points += credits * 2.0;
                       break;
            case 'D':
            case 'd':  total_grade_points += credits * 1.0;
                       break;
            case 'F':
            case 'f':  total_grade_points += credits * 0.0;
                       break;
            default :  cout << "Invalid input" << endl;
                       total_credits -= credits;
        }
    } while (true);   //why this is not an infinite loop?

    cout << "You have totally taken " << total_credits 
         << " credits." << endl << "Your GPA is " 
         << total_grade_points / total_credits << endl;

    return 0;
}
