#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

bool sortArray(const vi &a, const vi &b)
{
    for(int i = 0; i < a.size(); ++i)
    {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return false;
}
int main(void)
{
    int n;
    int x = 0;
    while(cin >> n && n)
    {
        if(x++ != 0) cout << endl;
        vi S;
        for(int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            S.push_back(k);
        }
        unsigned int v= (1<<6) - 1;
        vector<vector<int> > result;
        while(v < (unsigned int)((1<<n) - 1))
        {
            int counter = 0;

            vi temp;
            for(int i = 0; i < n; ++i)
            {
                if(v & (1 << i))
                {
                    temp.push_back(S[i]);
                }
            }

            result.push_back(temp);
            unsigned int t = (v | (v - 1)) + 1;  
            unsigned int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);  
            v = w;
        }
        sort(result.begin(), result.end(),sortArray);
        for(vi v : result)
        {
            for(int i = 0; i < v.size(); ++i)
            {
                if(i != 0 ) cout << " ";
                cout << v[i];
            }

            cout << endl;
        }
    }







    return 0;
}
