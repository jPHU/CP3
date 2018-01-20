#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
    int S, report;
    while(scanf("%d  %d", &S, &report) && S != 0)
    {
        vector<bool> soliders(S+2, 1);
        while(report--)
        {
            int L, R;  
            scanf("%d %d", &L, &R);

            replace(soliders.begin() + L, soliders.begin() + R + 1, 1, 0);
            while(soliders[L] == 0)
            {
            
                L--; 
            }
            while(soliders[R] == 0)
            {
                R++;
            }
            
            if(L == 0)
            {
                printf("*");
            }
            else
            {
                printf("%d", L);
            }

            if(R == S+1)
            {
                printf(" *");
            }
            else
            {
                printf(" %d", R);
            }
            printf("\n");
        }
        printf("-\n"); 
    
    }

    









    return 0;
}
