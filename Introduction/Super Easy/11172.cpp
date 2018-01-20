#include <iostream>
#include <stdio.h>
#include <inttypes.h>
using namespace std;


int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if(a > b)
        {
            cout << ">" << endl;
        }
        else if(a < b)
        {
            cout << "<" << endl;
        }
        else
        {
            cout << "=" << endl;
        }
    }

}
