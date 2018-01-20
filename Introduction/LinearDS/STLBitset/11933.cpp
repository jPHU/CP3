#include <cstdio>
#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
using namespace std;


int main(void)
{

    uint32_t n;
    while(scanf("%u", &n) == 1 && n != 0)
    {
        bitset<32> input(n);
        vector<int> positions;

        for(int i = 0; i < 32; ++i)
        {
            if(!input[i]) continue;
            positions.push_back(i);
        
        }
        
        bitset<32> a(0);
        bitset<32> b(0);
        
        for(size_t i = 0; i < positions.size(); ++i)
        {
            if(i%2)
            {
                b.set(positions[i]); 
            
            }
            else
            {
                a.set(positions[i]);
            }
        
        
        }

        
        cout << a.to_ullong() << " " << b.to_ullong() << endl; 
         

    }








    return 0;
}
