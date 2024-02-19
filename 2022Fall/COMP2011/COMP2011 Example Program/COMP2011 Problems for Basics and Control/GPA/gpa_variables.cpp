char grade;
/* Don't forget to initialize some of these variables */
int num_credits, total_num_credits = 0;
int total_grade_points = 0; // Is it a good idea to use integer type here?

// Think about the output
cout << "You have taken a total of " << total_num_credits 
     << " credits ..." << endl << "and your GPA is " 
     << total_grade_points / total_num_credits << endl;
