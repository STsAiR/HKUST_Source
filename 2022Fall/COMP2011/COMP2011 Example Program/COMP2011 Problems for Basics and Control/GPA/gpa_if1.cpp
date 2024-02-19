char grade;
int num_credits, total_num_credits = 0;
double total_grade_points = 0;

cout << "No. of credits of your course (0 to stop): ";
cin >> num_credits;
cout << "Your letter grade (A, B, C, D or F): ";
cin >> grade;
total_num_credits += num_credits; // Update total no. of credits

if (grade == 'A')       // Convert letter grade to grade point
    total_grade_points += num_credits * 4;
else if (grade == 'B')
    total_grade_points += num_credits * 3;
else if (grade == 'C')
    total_grade_points += num_credits * 2;
else if (grade == 'D')
    total_grade_points += num_credits * 1;
else if (grade == 'F')
    total_grade_points += num_credits * 0;
else
    total_num_credits -= num_credits;

