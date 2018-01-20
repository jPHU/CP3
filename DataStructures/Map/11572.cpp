#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        long k;
        cin >> k;

        long currentLongest = 0;
        long indexStarted = 0;
        map<long,long> snowflakes;
        long result = 0;
        for(int i = 0; i < k; ++i)
        {
            long input;
            cin >> input;
            if(snowflakes.find(input) == snowflakes.end() || snowflakes[input] < indexStarted)
            {
                snowflakes[input] = i;
                currentLongest++;
            }
            else
            {
                
                result = max(result, currentLongest);
                currentLongest = i - snowflakes[input];
                indexStarted = snowflakes[input]; 
                snowflakes[input] = i;
            }
        }
        result = max(result, currentLongest);
        cout <<result<< endl;
    }








    return 0;
}
