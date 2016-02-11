#include <algorithm>
#include <iomanip>  // Used to set the input-output manipulator 'precision' of final output.
#include <ios>      // Used to represent input-output stream sizes
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main()
{
    // Determine the number of divisions to make from the data set
    cout << "Specify the number of sets to group values in: ";
    int divisions;
    cin >> divisions;
    if(divisions < 1)
    {
        cout << endl << "Number of divisions must be greater than 0.    "
                        "Please try again." << endl;
        return 1;
    }

    // Get data set
    cout << "Please enter a set of numbers to be displayed in equal division sets, "
            "followed by end-of-file: ";

    double x;
    vector<double> values;

    // NOTE: No other inputs can be given on the command line after the while loop is started.
    while(cin >> x)
    {
        values.push_back(x);
    }

    // Determine number of entries
    typedef vector<double>::size_type vec_size;

    vec_size size = values.size();
    if(size == 0)
    {
        cout << endl << "You must enter at least one numerical value.    "
                        "Please try again." << endl;
        return 1;
    }

    // Sort data set by number value in descending order
    sort(values.begin(), values.end(), greater<double>());

    // Determine what the index counts are of the divisions.
    // Includes irregular-sized sets.
    int numExtra;
    vec_size sizeDivision;
    vec_size sizeDivisionExtra;
    if(size < divisions)
    {
        numExtra = 0;
        sizeDivision = 1;
        sizeDivisionExtra = 0;
        divisions = size;
    }
    else
        // Determine whether the division yields an integer.
        // If not, use a mixture of values for the best average set size.
    {
        numExtra = (int)size % divisions;
        sizeDivision = floor(size / divisions);
        sizeDivisionExtra = sizeDivision + 1;
    }
    unsigned int numDivision = divisions - numExtra;

    // Display each quartile based on quartile*quarterIndex
    vec_size iStart = 0;
    vec_size iEnd = iStart;
    cout << "The following are the division groups: " << endl;
    for(int i = 0; i < divisions; ++i)
    {
        // Set ending by division size.
        // Some divisions are irregular, in which case the index should be adjusted
        if (i < numDivision)
        {
            i == 0 ? iStart = 0 : iStart += sizeDivision;
            iEnd = iStart + sizeDivision;
        }
        else
        {
            i == numDivision ? iStart += sizeDivision : iStart += sizeDivisionExtra;
            iEnd = iStart + sizeDivisionExtra;
        }

        cout << "\n=====" +  patch::to_string(i + 1) + "=====" << endl;
        for(int j = iStart; j < iEnd; ++j)
        {
            cout << values[j] << endl;
        }
        cout << endl;
    }

    return 0;
}
