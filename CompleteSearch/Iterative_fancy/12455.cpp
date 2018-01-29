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
    int t;
    cin >> t;
    while(t--)
    {
        int goal;
        cin >> goal;
        int n;
        cin >> n;
        vector<int> lengths(n);
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            lengths[i] = a;
        }
        bool found = false;
        for(long i = 0; i < (1 << n); ++i)
        {

            int curSoln = 0;
            for(long j = 0; j < n; ++j)
            {
                if( i & (1 << j))
                {
                    curSoln += lengths[j];
                }
            }
            if(curSoln == goal)
            {
                found = true;
            }

        }
        if(found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO"<< endl;
        }
    }









    return 0;
}
