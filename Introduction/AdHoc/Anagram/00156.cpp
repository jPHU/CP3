#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <locale>
using namespace std;

int main(void)
{
    map<string, vector<string> > words;
    string input;
    while(cin >> input)
    {
        if(input == "#") break;
        string sorted = input;
        for(string::iterator it = sorted.begin(); it != sorted.end(); it++)
        {
            *it = tolower(*it);
        }
        sort(sorted.begin(), sorted.end());

        words[sorted].push_back(input);
    }

    vector<string> printWords;

    for(pair<string, vector<string> > p : words)
    {
        // Only 1 element
        if(p.second.size() == 1)
        {
            // if(!(p.second[0].size() == 1))
            // {
                printWords.push_back(p.second[0]);
            // }
        }
    }

    sort(printWords.begin(), printWords.end());

    for(string s : printWords)
    {
        cout << s << endl;
    }

    return 0;


}
