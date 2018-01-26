#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

ll computeVal(ll n, vector<ll> a)
{
    ll val = 0;
    ll factor = 0;
    for(ll x : a)
    {
        val += (x)*pow(n,factor);
        factor++;
    }
    return val;
}
int main(void)
{

    int c;
    cin >> c;
    string input;
    while(c--)
    {
        vector<ll> poly;
        ll val;
        cin >> val;
        val++;
        while(val--)
        {
            ll curVal;
            cin >> curVal;
            poly.push_back(curVal);
        }
        ll k;
        int n = 0; 
        ll d;
        cin >> d;
        cin >> k;
        while(k > 0)
        {
            n++;
            k -= (n)*d; 
        }
        cout << computeVal(n, poly) << endl;


    }









    return 0;
}
