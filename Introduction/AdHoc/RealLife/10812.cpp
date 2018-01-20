/*
a + b = x (W.L.O.G assume a is larger)
a - b = y

2a = x + y
a = (x + y) / 2
b = (x - y) / 2
*/
#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x < 0 || y < 0 || (x+y)%2 != 0 || x - y < 0 || (x - y)%2 != 0)
        {
            printf("impossible\n");
            continue;
        }
        else
        {
            printf("%d %d\n", (x+y)/2, (x-y)/2);
        }




    }
}
