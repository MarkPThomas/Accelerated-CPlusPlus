#include <vector>

#include "square_vector.h"

using namespace std;

typedef vector<int>::size_type vec_sz;
typedef vector<double>::size_type vec_sz_dbl;

vector<int> square_vector(vector<int> vec)
{
    vector<int> squares;
    for (vec_sz i = 0; i < vec.size(); ++i)
    {
        int square = vec[i] * vec[i];
        squares.push_back(square);
    }

    return squares;
}

vector<double> square_vector(vector<double> vec)
{
    vector<double> squares;
    for (vec_sz_dbl i = 0; i < vec.size(); ++i)
    {
        double square = vec[i] * vec[i];
        squares.push_back(square);
    }

    return squares;
}
