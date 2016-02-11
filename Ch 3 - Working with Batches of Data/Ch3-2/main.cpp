#include <algorithm>
#include <iomanip>  // Used to set the input-output manipulator 'precision' of final output.
#include <ios>      // Used to represent input-output stream sizes
#include <iostream>
#include <math.h>
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

vector<double> lowerHalf(vector<double> values)
{
    // Calculate the Median result
    vec_sz size = values.size();

    if(size == 0)
    {
        cout << endl << "You must enter values.    "
                        "Please try again." << endl;
        return vector<double>();
    }

    sort(values.begin(), values.end());
    vector<double> lowerHalfCurrent;
    vec_sz mid = round(size/2);

    for (int i = 0; i < mid; ++i)
    {
        lowerHalfCurrent.push_back(values[i]);
    }

    return lowerHalfCurrent;
}

vector<double> upperHalf(vector<double> values)
{
    // Calculate the Median result
    vec_sz size = values.size();

    if(size == 0)
    {
        cout << endl << "You must enter values.    "
                        "Please try again." << endl;
        return vector<double>();
    }

    sort(values.begin(), values.end());
    vector<double> upperHalfCurrent;
    vec_sz mid = round(size/2);
    if(size % 2 != 0)
    {
        mid += 1;
    }

    for (int i = mid; i < size; ++i)
    {
        upperHalfCurrent.push_back(values[i]);
    }

    return upperHalfCurrent;
}


int main()
{
    // Ask for the homework grades
    cout << "A set of values to get their quartiles, "
            "followed by end-of-file: ";

    // A variable into which to read
    double x;
    vector<double> fullNumberSet;

    // invariant: Homework contains all of the homework grades read so far
    while (cin >> x)
    {
        fullNumberSet.push_back(x);
    }

    vector<double> firstHalf = lowerHalf(fullNumberSet);
    double firstQuartile = median(firstHalf);

    vector<double> secondHalf = upperHalf(fullNumberSet);
    double thirdQuartile = median(secondHalf);

    // Write the result
    streamsize prec = cout.precision();

    vec_sz size = firstHalf.size();
    for (int i = 0; i < size; ++i)
    {
        cout << firstHalf[i] << endl;
    }
    cout << "The first quartile is " << setprecision(3) << firstQuartile << endl;
    cout << endl;

    size = secondHalf.size();
    for (int i = 0; i < size; ++i)
    {
        cout << secondHalf[i] << endl;
    }
    cout << "The third quartile is " << setprecision(3) << thirdQuartile << endl;
    cout << endl;

    cout << setprecision(prec) << endl;

         // The final 'setprecision(prec)' resets the precision to the original, default value.

    return 0;
}
