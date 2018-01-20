#include <cstdio>
#include <iostream>

using namespace std;


int main(void)
{

    int n;
    int p;
    while(scanf("%d %d", &n, &p) && !(n == 0 && p == 0))
    {
    
        int sq = 1;
        int k = 0;
        while(sq*sq < p)
        {
        
            k++; 
            sq += 2;
        
        }
    
        int curPos = k + (n+1)/2;
        // sq is the size of the square atm! 
        int col = 0;
        int row = 0;
        if( p > sq*sq - sq)
        {
            col = curPos;
            row = curPos - (sq*sq - p);

        
        
        }
        else if( p > sq*sq - 2*sq + 1)
        {
        
        
            row = (n+1)/2 - k;
            col = curPos - (sq*sq - sq - p) - 1;
        

        
        }
        else if( p > sq*sq -  3*sq + 2)
        {
        
        
            col = (n+1)/2 - k;
            row = +(n+1)/2 - k  +  (sq*sq - 2*sq - p) + 2;
        
        
        } 
        else
        {
        
            row = curPos;
            col = (n+1)/2 - k + (sq*sq - 3*sq - p) + 3; 
        
        }
    
        printf("Line = %d, column = %d.\n", row, col);
    }









    return 0;

}
