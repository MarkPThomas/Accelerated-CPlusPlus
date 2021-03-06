#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;

// Compute a student's overall grade from midterm and final exam grades
//      and vector of homework grades.
// This function does not copy its argument, because median does so for us.
// '&' creates a reference to hw.
// 'const' makes the reference Read Only, so it cannot be changed.
//      Additionally, this must be used for referencing any constant as a parameter.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("Student has done no homework.");
    return grade(midterm, final, median(hw));
}

// Compute a student's overall grade from midterm and final exam grades and a homework grade.
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}
