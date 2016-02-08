// Ask for a person's name and generate a framed greeting.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;    // Reads and discards characters from the string until a non-whitespace character is encountered.
                    // Reads and characters into 'name' until whitespace is encountered.

    // Build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // Build the second and fourth lines of output
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // Build the first and fifth lines of the output
    const string first(second.size(), '*');

    const string exclam = "!";

    // Note: Below fails because two string literals cannot be concatenated together
    // const string messageConc = "Hello" + ", world" + exclam;

    // Write all
    cout << endl;
    cout << first << endl;
    cout << second << endl;
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;

    // Note: 'endl' ends the line of output, then flushes the buffer,
    // which forces the system to write to the output stream immediately.
    // This is good to do as a habit at opportune times to avoid overloading
    // the computer's buffer.

    // Note: + and << are 'left-associative'. For example:
    //  cout << s << t = (cout << s) << t

    // Note: use "" for string literals, and '' for character literals.

    return 0;
}
