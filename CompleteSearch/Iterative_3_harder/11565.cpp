#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
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
    while(t--)
    {
        int A,B,C;
        cin >> A >> B >> C;
        bool soln = false;
        for(int x = -100; x <= 100; ++x)
        {
            if(soln)
            {
                break;
            }
            for(int y = x+1; y <= 100; ++y)
            {
                int z = A - x - y;
                if(z == y || z == x) continue;
                if(x*y*z == B && x*x + y*y + z*z == C && x + y + z == A)
                {
                    vector<int> res;
                    res.push_back(x);
                    res.push_back(y);
                    res.push_back(z);
                    sort(res.begin(), res.end());
                    x = res[0];
                    y = res[1];
                    z = res[2];
                    printf("%d %d %d\n", x,y,z);
                    soln = true;
                    break;
                }
            }
        }
        if(!soln) cout << "No solution." << endl;
        
    }








    return 0;
}
