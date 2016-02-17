#include <stdexcept>>
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
    // Ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // Ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // Ask for the homework grades
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    vector<double> homework;

    // Read in the homework grades
    read_hw(cin, homework);

    // Compute and generate the final grade, if possible
    try
    {
        // Grade is calculated separately first, outside of the stream so that
        //      if it throws an exception, there are no side effects.
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error)
    {
        cout << endl << "You must enter your grades.    "
                        "Please try again." << endl;
        return 1;
    }

    return 0;
}
