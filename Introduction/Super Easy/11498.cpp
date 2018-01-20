#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
    int k;
    scanf("%d\n", &k);

    while(k)
    {
        int n,m;
        scanf("%d %d\n", &n, &m);
        for(int i = 0; i < k; ++i)
        {
            int x, y;
            scanf("%d %d\n",&x, &y);
            string result = (x == n || y == m) ? "divisa" : (y > m && x < n) ? "NO" : (y > m && x > n) ? "NE" : (y < m && x < n) ? "SO" : "SE";
            cout << result << endl;
        }

        scanf("%d\n",&k);
    }



}
