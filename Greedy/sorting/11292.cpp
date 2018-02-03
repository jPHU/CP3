#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void)
{
    int n, m;
    while(cin >> n >> m && n)
    {
        vector<int> dragons;
        vector<int> knights;
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            dragons.push_back(a);
        }

        for(int j = 0; j < m; ++j)
        {
            int a;
            cin >> a;
            knights.push_back(a);
        }

        sort(dragons.begin(), dragons.end());
        sort(knights.begin(), knights.end());

        int knightsIndex = 0;
        int totalPrice = 0;
        bool doomed = false;
        for(int i = 0; i < n; ++i)
        {
            if(knightsIndex == m)
            {
                doomed=true;
                break;
            }

            while(dragons[i] > knights[knightsIndex])
            {
                knightsIndex++;
                if(knightsIndex == m)
                {
                    doomed=true;
                    break;
                }
            }
            if(doomed) break;
            totalPrice += knights[knightsIndex];
            knightsIndex++;
        }
        if(doomed) cout << "Loowater is doomed!" << endl;
        else
        {
            cout << totalPrice << endl;
        }
    }
}
