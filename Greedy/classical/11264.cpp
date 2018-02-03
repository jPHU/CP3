#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int n;
vector<ll> coins;
set<ll> coinsAdded;
void withdraw(int X){
    if ( X == 0 ) return;
    for(int i = n-1; i >= 0; --i)
    {
        if( X - coins[i] >=0)
        {
            coinsAdded.insert(coins[i]);
            withdraw(X - coins[i]);  
            return;
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        coins.clear();
        cin >> n;

        for(int i = 0; i < n; ++i)
        {
            ll a;
            cin >> a;
            coins.push_back(a);
        }
        
        
        int runningSum = 0;
        int numCoins = 0;
        for(int i = 0; i < n; ++i)
        {
            coinsAdded.clear();
            withdraw(runningSum + coins[i]);
            if( coinsAdded.size() > numCoins)
            {
                runningSum += coins[i];
                numCoins = coinsAdded.size();
            }

        }
        cout << numCoins << endl;

    }
}
