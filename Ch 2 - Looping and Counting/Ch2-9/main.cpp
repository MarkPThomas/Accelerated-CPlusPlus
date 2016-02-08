#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int numberOne;
    cin >> numberOne;

    cout << "Enter another number: ";
    int numberTwo;
    cin >> numberTwo;

    cout << endl;

    int largestNumber = -1;
    numberOne > numberTwo ? largestNumber = numberOne : largestNumber = numberTwo;

    cout << "The largest number is: " << largestNumber << endl;
}
