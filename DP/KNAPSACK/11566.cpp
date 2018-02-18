#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, x, T, K;
// items, exact price, number of dishes!
int dp[221][1500][50];


// VAlue and Cost
// Divide values by N+1 at th end
int  V[221], C[221];

int tax(int x) {
    x *= 11;
    if (x%10 == 0) return x/10;
    else return (x/10)+1;
}


int main(void)
{
    while(cin >> N >> x >> T >> K && (N || x || K || T))
    {
        memset(dp, 0, sizeof(dp));   

        memset(V, 0, sizeof(V));   

        memset(C, 0, sizeof(C));   
        N++;
        
       
        

        for(int i = 0; i < K; ++i)
        {
            cin >> C[i];
            C[i+K] = C[i];
            for(int j = 0; j < N; ++j)
            {
                int a;
                cin >> a;
                V[i] += a;
                V[i+K] += a;
            }
        }

        K *= 2;

        

        // For all the dishes
        for(int i = 1; i < K + 1; ++i)
        {
            
            // For every possible price
            for(int j = 0; j < (x)*N + 1; ++j)
            {

                // For every number of items!
                for(int k = 1; k < 2*(N) + 1; k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if( j < C[i-1]) continue;
                   
                    // IF we can add this item!
                    if( dp[i-1][j-C[i-1]][k-1] > 0 || (j == C[i-1] && k == 1))
                    {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-C[i-1]][k-1] + V[i-1]);
                    }
                    else
                    {
                        // Add no items!
                        dp[i][j][k] = dp[i-1][j][k];
                    }

                    
                }
                
            }
        }

        int maxValue = 0;
        
        for(int j = 0; j < (x)*N + 1; ++j)
        {
            int thisPrice = 0;
            thisPrice = j + (N)*T;

            // Round it UP!
            thisPrice = ceil(1.1*thisPrice - 0.0001);

            if(thisPrice > x*N) break;

            for(int k = 1; k < 2*(N) + 1; ++k)
            {
                maxValue = max(maxValue, dp[K][j][k]);
                               
            }
        }
        printf("%d.%.2d\n", maxValue/(N), (int)round(maxValue*100.0/(N))%100);
        // printf("%.2lf\n", (maxValue + 0.0)/N);

        
    }

}
