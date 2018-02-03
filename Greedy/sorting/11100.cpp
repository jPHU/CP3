#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(void)
{
    long long n;
    while(cin >> n && n)
    {
        vector<long long > input(n);
        for(long long i = 0; i < n; ++i)
        {
            long long a;
            cin >> a;
            input[i] = a;
        }

        sort(input.begin(), input.end(), [](long long&a, long long&b){ return a > b;});

        long long minBags = 1;

        long long counter = 1;
        for(long long i = 1; i < n; ++i)
        {
            if( input[i] == input[i-1])
            {
                counter++;
            }
            else
            {
                if(counter > minBags)
                {
                    minBags = counter;
                }
                counter = 1;
            }
        }
        if(counter > minBags)
        {
            minBags = counter;
        }

        vector< stack<long long> > baskets(minBags,stack<long long>());

        for(long long i = 0; i < minBags; ++i)
        {
            baskets[i].push(input[i]);
        }

        for(long long i = minBags; i < n; ++i)
        {
            bool found = false;
            long long basketSmallest = 0;
            long long basketSize = n+1;
            for(long long j = 0; j < baskets.size(); ++j)
            {
                if(baskets[j].top() > input[i])
                {
                    found = true;
                    if(basketSize > baskets[j].size())
                    {
                        basketSize = baskets[j].size();
                        basketSmallest = j;
                    }
                }
            }
            baskets[basketSmallest].push(input[i]);
        }
        
        cout << baskets.size() << endl;
        for(long long i = 0; i < baskets.size(); ++i)
        {
            long long size = baskets[i].size();
            for(long long j = 0; j < size; ++j)
            {
                if(j) cout << " ";
                cout << baskets[i].top();
                baskets[i].pop();
            }
            cout << endl;
            
        }
        cout << endl;





    }
}
