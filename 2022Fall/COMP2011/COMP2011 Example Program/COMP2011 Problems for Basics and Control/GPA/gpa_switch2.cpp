switch (grade)          // Convert letter grade to grade point
{
    case 'A':
    case 'a':
        total_grade_points += num_credits * 4; break;
    case 'B':
    case 'b':
        total_grade_points += num_credits * 3; break;
    case 'C':
    case 'c':
        total_grade_points += num_credits * 2; break;
    case 'D':
    case 'd':
        total_grade_points += num_credits * 1; break;
    case 'F':
    case 'f':
        total_grade_points += num_credits * 0; break;
    default:
        total_num_credits -= num_credits;
}
