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

struct area{
    long r;
    long c;
    long num;
};


int main(void)
{
    long t;
    vector< pair<long, long>> position(25);
    long pos = 0;
    for(long i = 0; i < 5; ++i)
    {
        for(long j = 0; j < 5; ++j)
        {
            pii p(i,j);
            position[pos++] = p; 
        }
    }
    cin >> t;
    while(t--)
    {
        long n;
        cin >> n;
        vector< area> v_area;
        for(long k = 0; k < n; ++k)
        {
            long i, j, num;
            cin >> i >> j >> num;

            area thisArea;
            thisArea.r = i;
            thisArea.c = j;
            thisArea.num = num;
            v_area.push_back(thisArea);
        }
        long best = 9999999;
        vector<long> result(5,0);
        for(long a = 0; a <  25 - 4; ++a)
        {
            for(long b = a + 1; b < 25 - 3; ++b)
            {
                for(long c = b + 1; c < 25 - 2; ++c)
                {
                    for(long d = c + 1; d < 25 - 1; ++d)
                    {
                        for(long e = d + 1; e < 25; ++e)
                        {
                            long value = 0;
                            for(area thisArea : v_area)
                            {
                                long minDist = 25*25*10000;
                                long thisValue = 0;
                                thisValue = thisArea.num * (abs(thisArea.r - position[a].first) + abs(thisArea.c - position[a].second));
                                if(thisValue < minDist) minDist = thisValue;

                                thisValue = thisArea.num * (abs(thisArea.r - position[b].first) + abs(thisArea.c - position[b].second));
                                if(thisValue < minDist) minDist = thisValue;

                                thisValue = thisArea.num * (abs(thisArea.r - position[c].first) + abs(thisArea.c - position[c].second));
                                if(thisValue < minDist) minDist = thisValue;

                                thisValue = thisArea.num * (abs(thisArea.r - position[d].first) + abs(thisArea.c - position[d].second));
                                if(thisValue < minDist) minDist = thisValue;

                                thisValue = thisArea.num * (abs(thisArea.r - position[e].first) + abs(thisArea.c - position[e].second));
                                if(thisValue < minDist) minDist = thisValue;
                                
                                value += minDist;
                            }
                            if(value < best )
                            {
                                best = value;
                                result[0] = a;
                                result[1] = b;
                                result[2] = c;
                                result[3] = d;
                                result[4] = e;
                            }
                        }
                    }
                }
            }
        }
        long k = 0;
        for(long x : result)
        {
            if(k++ != 0) cout << " ";
            cout << x;
        }
        cout << endl;
        
    }









    return 0;
}
