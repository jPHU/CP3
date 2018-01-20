#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
    {
        int num;
        scanf("%d", &num);
        int minSpeed = 0;
        while(num--)
        {
            int curSpeed;
            scanf("%d", &curSpeed);
            if(curSpeed > minSpeed)
            {
                minSpeed = curSpeed;
            }
        }
        printf("Case %d: %d\n",i,minSpeed);

    }



}
