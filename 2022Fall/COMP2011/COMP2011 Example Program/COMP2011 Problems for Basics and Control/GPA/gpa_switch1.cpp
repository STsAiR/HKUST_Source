/*
 * Codes for variables definition and initialization, and inputs
 */

switch (grade)          // Convert letter grade to grade point
{
    case 'A':
        total_grade_points += num_credits * 4; break;
    case 'B':
        total_grade_points += num_credits * 3; break;
    case 'C':
        total_grade_points += num_credits * 2; break;
    case 'D':
        total_grade_points += num_credits * 1; break;
    case 'F':
        total_grade_points += num_credits * 0; break;
    default:
        total_num_credits -= num_credits;
}
