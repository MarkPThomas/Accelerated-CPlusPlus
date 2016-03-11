#include <vector>

#include "fill_vector.h"

using namespace std;

void fill_vector(vector<int>& vec, int maxNum)
{
    for (int i = 0; i <= maxNum; ++i)
    {
        vec.push_back(i);
    }
}

void fill_vector(vector<double>& vec, int maxNum)
{
    for (int i = 0; i <= maxNum; ++i)
    {
        vec.push_back(i);
    }
}
