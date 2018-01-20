#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


bool isZero( bool input[5][5])
{

    for(int i = 1; i < 4; ++ i)
    {
    
    
        for(int j = 1; j < 4; ++j)
        {
        
        
            if(input[i][j])
            {
                return false;
            }
        
        
        }
    
    
    }



    return true;


}
int main(void)
{


    int n;
    scanf("%d",&n);
    while(n--)
    {
    
        bool input[5][5];
        bool temp[5][5];
        memset(input, 0, sizeof(input[0][0])*5*5);
        memset(temp, 0, sizeof(temp[0][0])*5*5);
    
        for(int i = 1; i < 4; ++i)
        {
        
        
            for(int j = 1; j < 4; ++j)
            {
            
                int inp;
                scanf("%1d", &inp);
                input[i][j] = inp;
            
            
            
            }
        
        }
    
    int transforms = -1;
    while(!isZero(input))
    {
    
        for(int i = 1; i < 4; ++i)
        {
        
        
            for(int j = 1; j < 4; ++j)
            {
            
                temp[i][j] = (input[i+1][j] + input[i-1][j] + input[i][j+1] + input[i][j-1]) % 2; 
            
            
            }
        
        }
    
        memcpy(input, temp, sizeof(temp[0][0]) * 5 * 5);
        transforms++;
    
    }
    

    printf("%d\n", transforms);
    
    
    }








    return 0;
}
