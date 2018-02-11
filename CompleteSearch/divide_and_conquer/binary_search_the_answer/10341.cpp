#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

#define EPS 1e-7

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{
    int p,q,r,s,t,u;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) == 6)
    {
        double lower = 0;
        double upper = 1;
        double x = 0.5;
        double result; 
        double newX;
        int counter = 1000;
        do
        {
            x = newX;
            result = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t * x * x + u;

            if(result > 0)
            {
                lower = x;
                newX = (upper + x)/2;
            }
            else
            {
                upper = x;
                newX = (x + lower)/2;
            }
            counter--;

        }while((abs(newX - x) > EPS || abs(result) > EPS) && counter);
        if(counter == 0)
        {
            cout <<  "No solution" << endl;
        }
        else
        {
            printf("%.4f\n", round(x*10000)/10000.0);
        }
        
    }










    return 0;
}
