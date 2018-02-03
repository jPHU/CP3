#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    int B, S;
    int caseNum = 1;
    while(cin >> B >> S && B && S)
    {
        int youngest = 60;
        for(int i = 0; i < B; ++i)
        {
            int a;
            cin >> a;
            if(  a < youngest)
            {
                youngest = a;
            }
        }
        for(int i = 0; i < S; ++i)
        {
            int a;
            cin >> a;
        }
        printf("Case %d: ", caseNum++);
        if( S >= B) cout << "0" << endl;
        else
        {
            cout << B - S << " " << youngest << endl;
        }
        
    }
}
