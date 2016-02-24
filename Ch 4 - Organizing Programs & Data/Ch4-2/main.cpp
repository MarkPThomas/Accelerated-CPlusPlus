#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::size_type vec_sz;

vector<int> fill_vector(int maxNum)
{
    vector<int> values;
    for (int i = 0; i <= maxNum; ++i)
    {
        values.push_back(i);
    }

    return values;
}

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

int count_numbers (int num)
{
   int count = 0;

   if (num == 0)
   {
      return 1;
   }

   while (num != 0)
   {
      count++;
      num /= 10;
   }
   return count;
}

int vector_width(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    return count_numbers(vec[vec.size()-1]);
}

int main()
{
    // First column lists values of Ints up to 100
    vector<int> values = fill_vector(100);

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
