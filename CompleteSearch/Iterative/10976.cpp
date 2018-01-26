#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{
    // xy = k (x+y)
    
    //1/( 1/k- 1/x) = y
    ll k;
    while(cin>>k)
    {
        vector<ll> x;
        vector<ll> y;

        for(ll i = k+1; ; ++i)
        {
            ll y_num = round(1.0/(1.0/k - 1.0/i));
            if(i > (y_num))
            {
                break;
            }
            if(y_num < 0) continue;
            if(i*y_num == k * (i + y_num))
            {
                x.push_back(i);
                y.push_back((y_num));
            }
        }
        cout << x.size() << endl;
        for(size_t i = 0; i < x.size(); ++i)
        {
            cout << "1/" << k <<" = 1/" << y[i] << " + 1/" << x[i]<< endl;
        }
    }









    return 0;
}
