#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
    int t;
    cin >> t;
    int counter = 0;
    while(t--)
    {
        int n;
        cin >> n;
        int numberCrows = 0;
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '#') continue;
            if(s[i] == '.')
            {
                numberCrows++;
                i+= 2;
            }
            
        }
        printf("Case %d: %d\n", ++counter, numberCrows);
    }
}
