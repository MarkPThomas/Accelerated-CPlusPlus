#include <iomanip>
#include <iostream>
#include <vector>

#include "count_numbers.h"
#include "fill_vector.h"
#include "square_vector.h"
#include "vector_width.h"

using namespace std;

typedef vector<int>::size_type vec_sz;

int main()
{
    cout << "Specify the largest number to square: " << endl;
    int maxNum;
    cin >> maxNum;

    // First column lists values of Ints up to 100
    vector<int> values = fill_vector(maxNum);

    // Second column contains the square of each value
    vector<int> squares = square_vector(values);

    // Use setw to align columns in the output
    for (vec_sz i = 0; i < values.size(); ++i)
    {
        cout << setw(vector_width(values)) << values[i] << "^2 = "
             << setw(vector_width(squares)) << squares[i] << endl;
    }

    return 0;
}
