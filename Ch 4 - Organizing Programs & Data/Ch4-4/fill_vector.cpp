#include <vector>

#include "fill_vector.h"

using namespace std;

vector<int> fill_vector(int maxNum)
{
    vector<int> values;
    for (int i = 0; i <= maxNum; ++i)
    {
        values.push_back(i);
    }

    return values;
}

vector<double> fill_vector(int maxNum)
{
    vector<double> values;
    for (int i = 0; i <= maxNum; ++i)
    {
        values.push_back((double)i);
    }

    return values;
}
