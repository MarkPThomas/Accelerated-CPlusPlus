#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        const string s = "a string";
        cout << s << endl;
    }
    {
        const string s = "another string in a sub-scope";
        cout << s << endl;
    }

    return 0;
}
