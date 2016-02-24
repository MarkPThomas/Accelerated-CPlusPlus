#include <algorithm>
#include <vector>

#include "vector_width.h"
#include "count_numbers.h"

using namespace std;

int vector_width(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    return count_numbers(vec[vec.size()-1]);
}

int vector_width(vector<double> vec)
{
    sort(vec.begin(), vec.end());
    return count_numbers(vec[vec.size()-1]);
}

