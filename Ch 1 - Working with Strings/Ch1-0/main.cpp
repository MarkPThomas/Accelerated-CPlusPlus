#include <iostream>
#include <string>

using namespace std;

int main()
{
      // ask for a person's name
    cout << "Please enter your first name: ";

    // read the name
    string name;    // define name
    cin >> name;    // read into name

    // write a greeting
    cout << "Hello, " << name << "!" << endl;
    return 0;
}
