#include <iostream>
#include <string>

using namespace std;

// Note: For calling a method, these must be defined in order of being called.

void block(int height, int width)
{
    cout << endl;

    // Ensure that the shape is at least 2x2
    height < 2 ? height = 2 : height = height;
    width < 2 ? width = 2 : width = width;

    for (int r = 0; r < height; ++r)
    {
        // Is top of shape?
        if (r == 0 || r == height - 1)
        {
            string border(width, '*');
            cout << border;
        }
        else
        {
            string space(width - 2, ' ');
            cout << "*" + space + "*";
        }
        cout << endl;
    }
    cout << endl;
}

void triangle(int height, int width)
{
    cout << endl;

    // Ensure that the shape is at least 2x2
    height < 2 ? height = 2 : height = height;
    width < 2 ? width = 1 : width = width;

    int rowWidth = 0;
    for (int r = 0; r < height; ++r)
    {
        double rowWidthNotRounded = ((double)r / (height - 1)) * width + 1;
        rowWidth = (int)(rowWidthNotRounded + 0.5);

        // Ensure that rowWidth is at least 1
        rowWidth < 1? rowWidth = 1 : rowWidth = rowWidth;

        // Is top of shape?
        if (r == 0 || r == height - 1)
        {
            string border(rowWidth, '*');
            cout << border;
        }
        else
        {
            string space(rowWidth - 2, ' ');
            cout << "*" + space + "*";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int width = 0;
    int height = 0;

    // Write square
    cout << "Enter square dimension: ";
    cin >> width;
    height = width;
    block (height, width);

    // Write rectangle
    cout << "Enter rectangle height: ";
    cin >> height;
    cout << "Enter rectangle width: ";
    cin >> width;
    block (height, width);

    // Write triangle
    cout << "Enter triangle height: ";
    cin >> height;
    cout << "Enter triangle width: ";
    cin >> width;
    triangle(height, width);

    return 0;
}
