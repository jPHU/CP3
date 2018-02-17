#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int cost[100];
int value[100];
int opt[101][10201];

int main(void)
{
    int m, n;
    int U;
    while(cin >> m >> n )
    {
           
        U = m;
        memset(cost, 0, 100*sizeof(int));
        memset(value, 0, 100*sizeof(int));
        memset(opt, 0, 100*10000*sizeof(int));

        if( m > 1800 ) 
        {
            U = m + 200;
        }
         

        for(int i = 0; i < n; ++i)
        {
            cin >> cost[i] >> value[i];
        }

        for(int i = 1; i < n + 1; ++i)
        {
            
            for(int j = 0; j < U + 1; ++j)
            {

                opt[i][j] = opt[i-1][j];
                if(j - cost[i-1] < 0) continue;
                // If we can actually get a value!
                // I.e. we can make exactly j by including item i
                // Or we can include this item DIRECTLY
                if( opt[i-1][j - cost[i-1]] > 0 || j == cost[i-1] )
                {
                    opt[i][j] = max(opt[i-1][j], opt[i-1][j-cost[i-1]] + value[i-1]);
                }

            }
        }
        int maxValue = 0;
        
        // If we are in the retarded no go zone
        if( m > 1800 && m < 2000)
        {
            // Check up to m
            maxValue = *(max_element(opt[n], opt[n] + m));
            
            // Now check all other items
            maxValue = max(maxValue, *(max_element(opt[n] + 2001, opt[n] + U + 1)));
        }
        else
        {
            maxValue = *(max_element(opt[n], opt[n] + U + 1));
        }
        cout << maxValue << endl;

    }

}
