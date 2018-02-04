#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


map< char, vector<int> > input;

int main(void)
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        char a = s[i];
        input[a].push_back(i);
    }

    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        long curIndex = -1;
        bool correct = true;
        long first = 0;
        long last = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            char a = s[i];
            vector<int>::iterator it =  lower_bound(input[a].begin(), input[a].end(), curIndex + 1);

            // Can't find an element!
            if( it == input[a].end() ) 
            {
                correct = false;
                break;
            }

            curIndex = *it;
            if(i == 0) first = *it;
            if(i == s.size() - 1) last = *it;
            
        }
        if(correct)
        {
            printf("Matched %ld %ld\n", first, last);
        }
        else
        {
            cout << "Not matched" << endl;
        }
    }

    
}
