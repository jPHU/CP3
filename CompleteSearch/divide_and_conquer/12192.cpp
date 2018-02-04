#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void)
{
    int n, m;
    while(cin >> n >> m && n && m)
    {
        vector< vector<int> > height(n, vector<int>());
        vector< vector<int> > width(m, vector<int>(n));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int a;
                cin >> a;
                width[j][i] = a;
                height[i].push_back(a);
            }
        }

        int q;
        cin >> q;
        while(q--)
        {
            int best = 0;
            int L, U;
            cin >> L >> U;
            int bestL, bestR;
            for(int i = 0; i < n; ++i)
            {
                int a,b,c,d;
                vector<int>::iterator itUL = lower_bound(height[i].begin(), height[i].end(), L);
                if(itUL == height[i].end()) continue;
                a = itUL - height[i].begin();
                vector<int>::iterator itUR = upper_bound(height[i].begin(), height[i].end(), U); // TO deal with multiple
                itUR--;
                b = itUR - height[i].begin();

                if(width[a].begin() + i > width[a].end()) continue;
                vector<int>::iterator itBL = upper_bound(width[a].begin() + i, width[a].end(), U);
                itBL--;
                c = itBL - width[a].begin();

                if(width[b].begin() + i > width[b].end()) continue;
                vector<int>::iterator itBR = upper_bound(width[b].begin() + i, width[b].end(), U);
                itBR--;
                d = itBR - width[b].begin();

                int soln = min((c-i), (d-i));
                soln = min(soln, (b-a));
                soln++;
                if(soln > best) best = soln;

               
            }
            cout << best << endl;
        }
        cout << "-" << endl;
    }
}
