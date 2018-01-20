#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main(void)
{
    ll jack, jill;
    while(scanf("%lld %lld", &jack, &jill)  && !(jack == 0 && jill == 0))
    {
    
        set<ll> cds;
        for(ll i = 0; i < jack; ++i)
        {
            ll number;
            scanf("%llu", &number);
            cds.insert(number);
        }

        ll duplicate = 0;
        for(ll i = 0; i < jill; ++i)
        {
            ll number;
            scanf("%llu", &number);
            if(cds.count(number) > 0) duplicate++;
        }
        cout << duplicate << endl;
        
    }









    return 0;
}
