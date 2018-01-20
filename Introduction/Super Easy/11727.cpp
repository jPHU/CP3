#include <iostream>
#include <stdio.h>

using namespace std;


int main(void)
{
    int t;
    scanf("%d\n",&t);
    int caseNum = 1;
    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d\n",&a, &b, &c);
        printf("Case %d: ", caseNum++);
        if(a >= b && a >= c )
        {
           if(b > c)
           {
               printf("%d\n",b);
           }
           else
           {
               printf("%d\n",c);
           }
        }
        else if( b >= a && b >= c)
        {
            if(a > c)
            {
                printf("%d\n",a);
            }
            else
            {
                printf("%d\n",c);
            }
        }
        else
        {
            if(b > a)
            {
                printf("%d\n",b);
            }
            else
            {
                printf("%d\n",a);
            }
        }
    }
}
