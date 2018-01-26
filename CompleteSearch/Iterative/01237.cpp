#include <cstdio>
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

int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        int d;
        cin >> d;
        ll low[d];
        ll high[d];
        vector<string> names;
        for(int i = 0; i < d; ++i)
        {
            string input;
            cin >> input;
            names.push_back(input);
            cin >> low[i];
            cin >> high[i];
        }
        int Q;
        cin >> Q;
        while(Q--)
        {
            int found = 0;
            int index = 0;
            ll val;
            cin >> val;

            for(int i = 0; i < d; ++i)
            {
                val >= low[i] && val <= high[i] ? found++,index = i  : 0;
                if(found > 1) break;
            }
            cout << (found == 1 ? names[index] : "UNDETERMINED") << endl; 
        }
        if(n!= 0) cout << endl;
    }



    















    return 0;
}
