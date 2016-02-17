#include "Student_info.h"

using namespace std;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    // Read and store the student's name and midterm and final exam grades.
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);    // Read and store all of the student's homework grades
    return is;
}

// Read homework grades from an input stream into a vector<double>.
// Using '&' in the method name indicates that the return value is a reference.
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        // Get rid of previous contents.
        hw.clear();

        // Read homework grades.
        double x;
        while (in >> x)
            hw.push_back(x);

        // Clear the stream so that input will work for the next student.
        // Input can continue, but any error indications are reset.
        in.clear();
    }

    return in;
}
