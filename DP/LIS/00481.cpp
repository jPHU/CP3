#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

bool sortDir(int i, int j) { return i > j; }
int main(void)
{
    int curIn;

    vector<int> X;
    while(cin >> curIn)
    {
        X.push_back(curIn);
    }
    vector<int> M(X.size(), 999999999);
    vector<int> P(X.size(),0);
    vector<int> ans(X.size(), 999999999);

    int L = 0;
    for(size_t i = 0; i < X.size(); ++i)
    {
        curIn = X[i];
       
        // lower_bound ensures STRICTLY INCREASING solution!
        int pos = lower_bound(ans.begin(), ans.begin() + L, curIn) - ans.begin(); // Index of lower bound!
       
    
        // Update our subsequence array!
        ans[pos] = curIn;

        // Predecessor
        if( pos == 0)
        {
            P[i] = -1;
        }
        else
        {
            P[i] = M[pos - 1];
        }

        // This index is now  held by i
        M[pos] = i;

        if(pos + 1 > L)
        {
            L = pos + 1;
        }

        //if(it == ans.end())
        //{
        //    if(ans.size() > 0)
        //    {
        //        backtrack[it - ans.begin()] = (ans.end() - 1) - ans.begin();
        //    }
        //    ans.push_back(curIn);
        //}
        //else
        //{
        //    *it = curIn;
        //    if(it - ans.begin() != 0)
        //    {
        //        backtrack[it - ans.begin()] = (it-1) - ans.begin();
        //    }
        //}
    }
    cout << L << endl;
    cout << '-' << endl;

    int k = M[L - 1]; 
    vector<int> soln(L, 0);
    for(int i = L-1; i >= 0; --i, k=P[k])
    {
        soln[i] = X[k];
    }
    for(int i : soln)
    {
        cout << i << endl;
    }










    return 0;
}
