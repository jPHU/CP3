#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{

    while(1)
    {
        int m, n;
        scanf("%d %d", &m,  &n);
        if(m == 0) break;



        int ans = ceil(n*m/2.0);

        cout << ans << " knights may be placed on a "<< m << " row " << n << " column board." << endl;
    }


    return 0;
}
