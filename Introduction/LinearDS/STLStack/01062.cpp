#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>        
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{

    string input;
    int caseNum = 1;
    while(cin >> input && input != "end")
    {

        vector< stack<char> > stacks;
        for(char c : input)
        {
            bool inserted = false;
            for(size_t i = 0; i < stacks.size(); ++i)
            {
                if(stacks[i].top() >= c)
                {
                    inserted = true;
                    stacks[i].push(c);
                    break;
                }

            }
            if(!inserted)
            {
                stacks.push_back(stack<char>());
                (*(stacks.end()-1)).push(c);
            }
            sort(stacks.begin(), stacks.end(),
                    [](const stack<char>& a, const stack<char>& b) {
                    return a.top() < b.top();
                    });

        }
        cout << "Case " << caseNum << ": " <<  stacks.size() << endl;
        caseNum++;
    }







    return 0;
}
