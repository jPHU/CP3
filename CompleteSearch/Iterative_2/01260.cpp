
#include <cstdio>
#include <iostream>
#include <vector>

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
        int n;
        cin >> n;
        vector<int> a;
        while(n--)
        {
            int inp;
            cin >> inp;
            a.push_back(inp);
        }

        int counter = 0;
        for(size_t i = 1; i < a.size(); ++i)
        {
            for(size_t j = 0; j < i; ++j)
            {
                if(a[i] >= a[j])
                {
                    counter++;
                }
            }

        }
        cout << counter << endl;
    }








    return 0;
}
