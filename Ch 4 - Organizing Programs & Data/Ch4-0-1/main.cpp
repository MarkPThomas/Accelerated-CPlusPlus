#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;       // Length of the longest name

    // Read and store all the records
    // Invariant:   students contains all of the student records read so far
    //              maxlen contains the length of the longest name in students
    while(read(cin, record))
    {
        // Find the length of the longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Alphabetize the records
    sort(students.begin(), students.end(), compare);

    // Write the names and grades
    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i)
        {
            // Write the name, padded, on the right to maxlen + 1 characters
            cout << students[i].name
                 << string(maxlen + 1 - students[i].name.size(), ' ');

            // Compute and write the grade
            try
            {
                double final_grade = grade(students[i]);
                streamsize prec = cout.precision();
                cout << setprecision(3) << final_grade
                     << setprecision(prec);
            }
            catch (domain_error e)
            {
                cout << e.what();
            }

            cout << endl;
        }
    return 0;
}
