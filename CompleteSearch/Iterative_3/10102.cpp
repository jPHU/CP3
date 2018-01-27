#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{
    int n;
    while(cin >> n)
    {
        vii three;
        vii one;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                char x;
                cin >> x;
                if(x - '0'== 3)
                {
                    three.push_back(pii(i,j));
                }
                else if(x - '0' == 1)
                {
                    one.push_back(pii(i,j));
                }
            }
        }

        int maxDist = 0;
        for(pii p : one)
        {
            int minDist = n*n;
            for(pii q : three)
            {
                int curDist = abs(p.first - q.first) + abs(p.second - q.second);
                if(curDist < minDist)
                {
                   minDist = curDist;
                }
            }
            if (minDist > maxDist)
            {
                maxDist = minDist;
            }
        }
        cout << maxDist << endl;
    }









    return 0;
}
