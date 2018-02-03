#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    int caseNum = 1;
    while(T--)
    {
        int n;
        long long d;
        cin >> n >> d;
        vector<pair<char, long long> > stones(n + 2); 
        stones[0].first = 'B';
        stones[0].second = 0;
        stones[n+1].first = 'B';
        stones[n+1].second = d;
        for(int i = 1; i < n + 1; ++i)
        {
            pair<char, long long> p;
            cin >> p.first;
            char temp;
            cin >> temp;
            cin >> p.second;
            stones[i] = p;
        }

        int firstBank = 0;
        int nextBank = 1;
        
        long long maxDist = 0;
        while(firstBank != n + 1)
        {
            while(stones[nextBank].first != 'B') nextBank++;

            for(int i = firstBank; i < nextBank; i+=2)
            {
                int nextBlock = min(i + 2, nextBank);
                maxDist = max(maxDist, stones[nextBlock].second - stones[i].second); 
            }

            for(int i = firstBank + 1; i < nextBank; i+=2)
            {
                int nextBlock = min(i + 2, nextBank);
                maxDist = max(maxDist, stones[nextBlock].second - stones[i].second); 
            }

            firstBank = nextBank;
            nextBank++;
        }
        printf("Case %d: %lld\n", caseNum++, maxDist);

    }
}
