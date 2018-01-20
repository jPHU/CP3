#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    cin.ignore();
    cin.ignore();
    while(n--)
    {
        string input;


        map<string, vector<string> > anagrams;
        while(getline(cin, input) && input != "")
        {
            string curWord;
            // Process input
            for(char c : input)
            {
                if(c == ' ' || c == '\r')
                    continue;

                curWord.push_back(c);
            }

            string sortWord = curWord;
            sort(sortWord.begin(), sortWord.end());
            anagrams[sortWord].push_back(input);
        }


        vector<string> results;
        for(pair<string, vector<string> > p : anagrams)
        {
            vector<string> vec = p.second;

            if(vec.size() == 1) continue;

            sort(vec.begin(), vec.end());

            for(unsigned int i = 0; i < vec.size(); ++i)
            {
                for(unsigned int j = i + 1; j < vec.size(); ++j)
                {
                    char result[1000];
                    sprintf(result,"%s = %s\n", vec[i].c_str(), vec[j].c_str());
                    string resultStr(result);
                    results.push_back(resultStr);
                }
            }

        }


        sort(results.begin(), results.end());
        for(string s : results)
        {
            printf("%s", s.c_str());
        }
        if(n != 0)
        {
            printf("\n");
        }
    }
}
