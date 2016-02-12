#include <algorithm>
#include <iomanip>  // Used to set the input-output manipulator 'precision' of final output.
#include <ios>      // Used to represent input-output stream sizes
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Typedef is used to assign a shorthand name to the type.
// Size_type is used as a size for vectors rather than a more generic size
// to remain implementation-independent
typedef vector<double>::size_type vec_sz;

double median(vector<double> values)
{
    // Calculate the Median result
    vec_sz size = values.size();

    if(size == 0)
    {
        cout << endl << "You must enter values.    "
                        "Please try again." << endl;
        return 1;
    }

    sort(values.begin(), values.end());
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (values[mid] + values[mid-1])/2
                           : values[mid];
    return median;
}

int main()
{
    int numHomeworks = 4;
    vector<string> students;
    vector<double> grades;

    cout << "Please enter the number of students to be graded: ";
    int numStudents;
    cin >> numStudents;
    cout << endl;

    if (numStudents < 1)
    {
        cout << "Invalid number. Program will close" << endl;
        return 1;
    }

    for (int i = 0; i < numStudents; ++i)
    {
        // Ask for and read the student's name
        cout << endl;
        cout << "Student " << i + 1 << ", please enter your first name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;

        // Ask for and read the midterm and final grades
        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        // Ask for the homework grades
        cout << "Enter all " << numHomeworks << " of your homework grades, "
                "followed by end-of-file: " << endl;
        vector<double> homework;
        for (int i = 0; i < numHomeworks; ++i)
        {
            double grade = 0;
            cin >> grade;
            homework.push_back(grade);
        }
        //cin.clear();

        // Calculate the student grades
        double studentMedian = median(homework);
        double studentGrade = 0.2 * midterm + 0.4 * final + 0.4 *  studentMedian;

        // Save results
        students.push_back(name);
        grades.push_back(studentGrade);
    }

    // Write the result
    streamsize prec = cout.precision();
    cout << endl;
    cout << "The final student grades are: " << setprecision(3) << endl;
    for (int i = 0; i < students.size(); ++i)
    {
        cout << students[i] + ": " << grades[i] << endl;
    }
    cout << setprecision(prec) << endl;
    // The final 'setprecision(prec)' resets the precision to the original, default value.

    return 0;
}
