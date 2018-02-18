#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int dp[100+1][500*100 + 1];

int main(void)
{

    int n;
    cin >> n;
    while(n--)
    {
        int m;
        cin >> m;

        memset(dp, 0, sizeof(dp));

        vector<int> items(m,0);
        int total = 0;
        for(int i = 0; i < m; ++i)
        {
            cin >> items[i];
            total += items[i];
        }

        
        
        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 0; j < total/2 + 1; ++j)
            {
                if(j >= items[i-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1]] + items[i-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << (total - dp[m][total/2]) - dp[m][total/2] << endl;
    }








    return 0;
}
