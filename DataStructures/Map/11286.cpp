#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;



int main(void)
{
    int n;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        string input;
        getline(cin, input); // get rid of new line
        map< string, int> popularity;
        string ordered;
        for(int i = 0; i < n; ++i)
        {
            getline(cin, input);
            stringstream ss(input);
            vector<string> vecStrings;
            string tempString;
            for(int j = 0; j < 5; ++j)
            {
                ss >> tempString;
                vecStrings.push_back(tempString);
            }
            sort(vecStrings.begin(), vecStrings.end());
            string orderedKey;
            for(int j = 0; j < 5; ++j)
            {
                orderedKey+=vecStrings[j];
            }
            popularity[orderedKey]++;
        }
        int preResult = 0;
        for(pair<string, int> p : popularity)
        {
            preResult = max(preResult, p.second);
        }
        int result = 0;
        for(pair<string, int> p : popularity)
        {
            if(p.second == preResult) result+= preResult; 
        }
        cout << (result) << endl;
    }









    return 0;
}
