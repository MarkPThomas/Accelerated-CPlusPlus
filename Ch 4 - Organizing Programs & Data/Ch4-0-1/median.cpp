#include <algorithm>    // To get the declaration of sort
#include <stdexcept>    // To get the declaration of domain_error
#include <vector>       // To get the declaration of vector
#include "median.h"     // It is not required, but is a good idea for confirming whether or not method signatures are not overloaded.

using namespace  std;

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
