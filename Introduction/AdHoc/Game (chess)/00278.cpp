#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        char c;
        int m, n;
        scanf(" %c %d %d",&c, &m,  &n);

        int ans = 0;
        if(c == 'r')
        {
            ans = min(m,n);
        }
        else if(c == 'K')
        {
            ans = max((ceil((m + 0.0)/2)) * ceil((n+0.0)/2),ceil((n+0.0)/2) * ceil((m+0.0)/2));
        }
        else if (c == 'k')
        {
            ans = ceil(n*m/2.0);
        }
        else if(c == 'Q')
        {
            ans = min(m,n);
        }
        cout << ans << endl;
    }


    return 0;
}
