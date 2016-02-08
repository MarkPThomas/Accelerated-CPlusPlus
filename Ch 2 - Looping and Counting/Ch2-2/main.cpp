#include <iostream>
#include <string>

//using namespace std;

// Say what standard-library names we use
using std::cin;     using std::endl;
using std::cout;    using std::string;

int main()
{
    // Ask for the person's name and read it
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // Build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // The number of blanks surrounding the greeting
    const int padVert = 2;
    const int padHor = 4;

    // Total number of rows and columns to write
    const int rows = padVert * 2 + 3;
    const string::size_type cols = greeting.size() + padHor * 2 + 2;
    // Note that 'size_type' is better to use since it maintains consistency of counting
    // for the string type. For example, the value is always positive and will always be
    // in a range that can be used as a string (min/max are appropriate).


    // Separate the output from the input by writing a blank line
    cout << endl;

    // Invariant: We have written r rows so far
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        // Invariant: We have written c characters so far in the current row
        while (c != cols)
        {
            // Is it time to write the greeting?
            if (r == padVert + 1 && c == padHor + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // Are we on the border?
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
}
