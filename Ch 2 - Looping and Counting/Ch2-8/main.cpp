#include <iostream>
#include <string>

using namespace std;

// See the following for concatenating numbers and strings:
// http://stackoverflow.com/questions/191757/c-concatenate-string-and-int
// In the current compiler, there is a bug that prevents std::to_string from working.
// This example employs a workaround found here:
// http://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-so-g


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
    int product = 1;
    for (int i = 0; i < 9; i++)
    {
        string calculation = patch::to_string(i+1) + " * " + patch::to_string(product) + " = ";
        cout << calculation;
        product *= (i+1);
        cout << product << endl;
    }

    return 0;
}
