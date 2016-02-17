#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student_info
{
    string name;
    double midterm, final;
    vector<double> homework;
};

// Compute the median of a vector<double>.
// Note that calling this function copies the entire argument vector.
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("Median of an empty vector.");
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

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
double grade(double miterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
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

istream& read(istream& is, Student_info& s)
{
    // Read and store the student's name and midterm and final exam grades.
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);    // Read and store all of the student's homework grades
    return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // Read and store all the records and find the length of the longest name
    while(read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Alphabetize the records
    sort(students.begin(), students.end(), compare());

    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i)
        {
            // Write the name, padded, on the right to maxlen + 1 characters
            cout << students[i].name
                 << string(maxlen + 1 - students[i].name.size(), ' ');

            // Compute and write the grade
            try
            {
                double final_grade = grade(students[i);
                streamsize prec = cout.precision();
                cout << setprecision(3) < final_grade
                     << setprecision(prec);
            }
            catch (domain_error)
            {
                cout << e.what();
            }

            cout << endl;
        }
    return 0;
}
