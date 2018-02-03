#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    int n, d, r;
    while(scanf("%d %d %d", &n, &d, &r) == 3 && n != 0)
    {
        vector<int> morn;
        vector<int> even;
        for(int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            morn.push_back(num);
        }
        for(int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            even.push_back(num);
        }
        sort(morn.begin(), morn.end());
        sort(even.begin(), even.end());

        int overtimePay = 0;

        for(int i = 0; i < n; ++i)
        {
            if(morn[i] + even[n-i-1] - d > 0)
            {
                overtimePay += r * (morn[i] + even[n-i-1] - d);
            }
        }
        cout << overtimePay << endl;
    }
}
