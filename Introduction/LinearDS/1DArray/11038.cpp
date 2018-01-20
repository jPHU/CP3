#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


long long countZero(long long m){



        // Compute how many 0s printed from one number
        long long num = 0;
        int multiple = 1;
        int rem = 0;
        while(m > 0)
        {
            if(m%10 != 0){
            
             num +=( m/10)*(multiple); 

            }
            else{

                num +=( m/10-1)*(multiple) + rem + 1;
            }
            rem += (m % 10)*multiple;
            m /= 10;
            multiple *= 10; 
        }
       return num;
 

}
int main(void)
{
    long long  m, n;
    while(scanf("%lld %lld",&m, &n) && m >= 0)
    {
        printf("%lld\n", countZero(n) - countZero(m-1) +(long long)( m==0 ? 1 : 0)); 
     
   
    }









    return 0;
}
