#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{

    ll n, m;
    while(cin >> n >> m)
    {

        map< ll,vector<ll> > adjList;
        for(ll i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            adjList[input].push_back(i+1);
        }
        while(m--)
        {
            ll k ,v;
            cin >> k >> v;
            vector<ll> vec = adjList[v];
            if((unsigned long long)k > vec.size())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << vec[k-1] << endl;
            }
        }
    }








    return 0;
}
