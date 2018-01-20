#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

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
    int curCase = 1;
    while(cin >> n && n)
    {
        cout << "Case " << curCase << ":" << endl;
        curCase++;
        vector<int> a;
        while(n--)
        {
            int num;
            cin >> num;
            a.push_back(num);
        }

        int m;
        cin >> m;
        while(m--)
        {
            int q;
            cin >> q;
            int curclosest = a[0] + a[1];
            for(size_t i = 0; i < a.size(); ++i)
            {
                for(size_t j = i + 1; j < a.size(); ++j)
                {
                    if( abs(a[i] + a[j] - q) < abs(curclosest - q))
                    {
                        curclosest = a[i] + a[j];
                    }

                }
            }
            cout << "Closest sum to " << q << " is " << curclosest << "." << endl;
            
        }
        
        
    }









    return 0;
}
