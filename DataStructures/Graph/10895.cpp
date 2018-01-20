#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2)
    {
        vector< vector<pii> > vec(n);
        for(int i = 0; i < m; ++ i)
        {
            int x;
            cin >> x;
            if(x == 0) continue;
            vii tempVec(x);
            for(int j = 0; j < x; ++j)
            {
                int k;
                cin >> k;
                tempVec[j].first = k;
            }
            for(int j = 0; j < x; ++j)
            {
                int k;
                cin >> k;
                tempVec[j].second = k;
            }
            for(pii p : tempVec)
            {
                vec[p.first - 1].push_back(pii(i+1,p.second));
            }

        }
        cout << n << " " << m << endl;
        for(vii v : vec)
        {
            if(v.size() == 0)
            {
                cout << "0" << endl << endl;
                continue;
            }
            cout << v.size();
            for(pii p : v)
            {
                cout << " " << p.first; 
            }
            cout << endl;
            bool fir = true;
            for(pii p : v)
            {
                if(!fir) 
                {
                    cout << " ";
                }
                cout << p.second;
                fir = false; 
        
            }
            cout << endl;
        }


    }









    return 0;
}
