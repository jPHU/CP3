#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

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
    int caseNum = 1;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> h(n,0);
        vector<int> w(n,0);
        for(int i = 0; i < n; ++i)
        {
            cin >> h[i];
        }
        for(int i = 0; i < n; ++i)
        {
            cin >> w[i];
        }

        // The opt width of LIS ending at i
        vector<int> L(n,0);

        int increasingBest = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j >= 0; --j)
            {
                if( h[i] > h[j] || i == j)
                {
                    L[i] = max(L[i], w[i] + L[j]);
                }
            }
            increasingBest = max(increasingBest, L[i]); 
        }



        L.assign(n,0);
        int decreasingBest = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j >= 0; --j)
            {
                if( h[i] < h[j] || i == j)
                {
                    L[i] = max(L[i], w[i] + L[j]);
                }
            }
            decreasingBest = max(decreasingBest, L[i]); 
        }
        if(increasingBest >= decreasingBest)
        {

            printf("Case %d. Increasing (%d). Decreasing (%d).\n", caseNum++, increasingBest, decreasingBest);
        }
        else
        {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", caseNum++, decreasingBest, increasingBest);
        }
 
    }









    return 0;
}
