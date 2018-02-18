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

vector< vector<int> > dp;
vector<int> value;
vector<int> cost;
vector< pair<int, int> > soln;

void backtrack(int i, int j)
{
    if(i == 0) return;
    while(dp[i][j] == dp[i-1][j])
    {
        i--;
        if(i == 0) return;
    }
    soln.push_back( {value[i-1], cost[i-1]});
    backtrack( i - 1, j - cost[i-1]);
}

int main(void)
{

    int t, w;
    bool first = true;
    while(cin >> t >> w)
    {
        if(first)
        {
            first = false;
        }
        else
        {
            cout << endl;
        }
        soln.clear();
        int n;
        cin >> n;
        value.assign(n,0);
        cost.assign(n,0);
        for(int i = 0; i < n; ++i)
        {
            int d;
            cin >> d;
            cost[i] = d * w * 3;
            cin >> value[i];
        }


        dp.assign(n+1, vector<int>(t+1,0));
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 0; j < t + 1; ++j)
            {
                if(j >= cost[i-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - cost[i-1]] + value[i-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        backtrack(n,t);

        
        cout << dp[n][t] << endl;
        cout << soln.size() << endl;
        for(int i = soln.size() - 1; i >= 0; --i)
        {
            pair<int, int> p = soln[i];
            cout << p.second / (3*w);
            cout << " " << p.first << endl;
        }
        // Backtrack to find the actual solution!
    }









    return 0;
}
