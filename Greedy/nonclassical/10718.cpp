#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{

    uint32_t in_N, in_L, in_U;
    while(cin >>in_N >> in_L >> in_U)
    {

        
        bitset<32> N(in_N), L(in_L), U(in_U);
        bitset<32> M;

        for(int i = 31; i >= 0; --i)
        {
            bitset<32> temp;
            if(N[i] == 1)
            {
                if(M.to_ulong() >= L.to_ulong())
                {

                }
                else
                {
                    M[i] = L[i];
                }
            }
            else
            {
                temp = M;
                temp[i] = 1;
                if(temp.to_ulong() <= U.to_ulong())
                {
                    M[i] = 1;
                }
            }

        }
        cout << M.to_ulong() << endl;
    }

}
