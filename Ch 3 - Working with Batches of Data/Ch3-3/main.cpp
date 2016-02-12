#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

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

    // Create a unique list of words
    unordered_set<string> wordsUniqueSet;
    for (int i = 0; i < wordsRaw.size(); ++i)
    {
       wordsUniqueSet.insert(wordsRaw[i]);
    }
    vector<string> wordsUnique(wordsUniqueSet.begin(), wordsUniqueSet.end());

    // For each entry, get a word occurrence count
     vector<int> wordCounts;
     for (int i = 0; i < wordsUnique.size(); ++i)
     {
         string word = wordsUnique[i];
         int occurrence = 0;
         for (int j = 0; j < wordsRaw.size(); ++j)
         {
             if (word == wordsRaw[j])
             {
                 ++occurrence;
             }
         }
         wordCounts.push_back(occurrence);
     }

    // Print output
    cout << "The following words appeared the following number of times: " << endl;
    for (int i = 0; i < wordsUnique.size(); ++i)
    {
        cout << wordsUnique[i] + ": " << wordCounts[i] << endl;
    }

    return 0;
}
