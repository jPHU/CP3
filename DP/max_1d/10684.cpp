#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    while(cin >> n && n)
    {
        int curSoln = 0;
        int best = -1000000;
        for(int i = 0; i < n; ++i)
        {
            int nextInt;
            cin >> nextInt;
            curSoln = max(curSoln + nextInt, 0);
            if(curSoln > best)
            {
                best = curSoln;
            }
        }
        if(best > 0)
        {
            printf("The maximum winning streak is %d.\n", best);
        }
        else
        {
            cout<<"Losing streak." << endl;
        }
    }
}
