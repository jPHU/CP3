#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
struct soln{
    double a;
    double b;
    double c;
    double d;
};

int main(void)
{
    vector<soln> result;
    for(int a = 1; a < 2000; a++)
    {
        for(int b = a; b < 2000 - a; b++)
        {
            for(int c = b; c < 2000 - a - b; c ++)
            {
                if(a*b*c - 100*100*100 == 0) continue;
                int d = ((b+c+a)*100*100*100)/(a*b*c - 100*100*100);
                if( a > d || b > d || c > d) continue;
                if(abs(a*b*c*d - 100*100*100*(a + b + c + d)) < 0.0001 && a + b + c + d <= 2000 && d > 0)
                {
                    soln s;
                    s.a = a;
                    s.b = b;
                    s.c = c;
                    s.d = d;

                    printf("%.2f %.2f %.2f %.2f\n", s.a/100, s.b/100, s.c/100,s.d/100);
                    result.push_back(s);
                }

            }
        }
    }









    return 0;
}
