/*
 * Codes for variables definition and initialization, and inputs
 */

if ((grade == 'A') || (grade == 'a'))
    total_grade_points += num_credits * 4;

else if ((grade == 'B') || (grade == 'b'))
    total_grade_points += num_credits * 3;

else if ((grade == 'C') || (grade == 'c'))
    total_grade_points += num_credits * 2;

else if ((grade == 'D') || (grade == 'd'))
    total_grade_points += num_credits * 1;

else if ((grade == 'F') || (grade == 'f'))
    total_grade_points += num_credits * 0;

else
    total_num_credits -= num_credits;
