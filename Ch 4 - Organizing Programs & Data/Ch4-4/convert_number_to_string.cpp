#include <sstream>
#include <string>

#include "convert_number_to_string.h"

using namespace std;

string convert(int number)
{
    string Result;          // string which will contain the result

    ostringstream convertResult;   // stream used for the conversion

    convertResult << number;      // insert the textual representation of 'Number' in the characters in the stream

    Result = convertResult.str(); // set 'Result' to the contents of the stream

          // 'Result' now is equal to "123"
    return Result;
}

string convert(double number)
{
    string Result;          // string which will contain the result

    ostringstream convertResult;   // stream used for the conversion

    convertResult << number;      // insert the textual representation of 'Number' in the characters in the stream

    Result = convertResult.str(); // set 'Result' to the contents of the stream

          // 'Result' now is equal to "123"
    return Result;
}
