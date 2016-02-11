#include <algorithm>
#include <iomanip>  // Used to set the input-output manipulator 'precision' of final output.
#include <ios>      // Used to represent input-output stream sizes
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

    // A variable into which to read
    double x;
    vector<double> homework;

    // invariant: Homework contains all of the homework grades read so far
    while (cin >> x)
    {
        homework.push_back(x);
    }

    // Calculate the Median result
    // Typedef is used to assign a shorthand name to the type.
    // Size_type is used as a size for vectors rather than a more generic size
    // to remain implementation-independent
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if(size == 0)
    {
        cout << endl << "You must enter your grades.    "
                        "Please try again." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2
                           : homework[mid];

    // Write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 *  median
         << setprecision(prec) << endl;

         // The final 'setprecision(prec)' resets the precision to the original, default value.

    return 0;
}
