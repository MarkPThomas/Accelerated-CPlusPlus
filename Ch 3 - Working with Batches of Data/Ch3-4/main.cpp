#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string::size_type str_size;

int main()
{
    cout << "Add a list of words. Type '0' to end the sequence." << endl;

    // Get raw list of words
    string x;
    vector<string> wordsRaw;
    while(cin >> x)
    {
        if (x == "0") {break;}
        wordsRaw.push_back(x);
    }

    // Get largest and smallest words, and their sizes
    str_size sizeMin = 100;
    str_size sizeMax = 0;
    string wordMin;
    string wordMax;
    for (int i = 0; i < wordsRaw.size(); ++i)
    {
        str_size sizeWord = wordsRaw[i].size();
        if (sizeWord > sizeMax)
        {
            sizeMax = sizeWord;
            wordMax = wordsRaw[i];
        }

        if(sizeWord < sizeMin)
        {
            sizeMin = sizeWord;
            wordMin = wordsRaw[i];
        }

    }

    // Print output
    cout << "The longest word and its length are: " << wordMax + " - " << sizeMax << endl;
    cout << "The shortest word and its length are: " << wordMin + " - " << sizeMin << endl;

    return 0;
}
