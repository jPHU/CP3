#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    while(1)
    {

        long long curNumber = -1000000;
        long long i = 0;
        long long pos = -1;
        long long neg = 1;

        long long bestSoln = -1000000;
        while(cin >> curNumber && curNumber!= -999999)
        {
            long long newPos, newNeg;
            if(curNumber > 0)
            {
                newPos = max(pos*curNumber,curNumber);
                newNeg = min(neg*curNumber, curNumber);
            }
            else
            {
                newPos = max(neg*curNumber, curNumber);
                newNeg = min(pos*curNumber, curNumber);
            }
            if(newPos > bestSoln)
            {
                bestSoln = newPos;
            }
            
            pos = newPos;
            neg = newNeg;
        }

        if(curNumber == -1000000)
        {
            break;
        }
        else
        {
            cout << bestSoln << endl;
        }

        
    }




}
