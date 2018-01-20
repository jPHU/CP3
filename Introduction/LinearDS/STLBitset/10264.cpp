#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
#include <utility>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;



int main(void)
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        map< uint16_t, int>  values;
        for(uint16_t i = 0; i < (uint16_t) pow(2,n); ++i)
        {
            uint16_t bit = i;
            int val;
            cin >> val;
            values.insert(make_pair(bit, val));


        }
        map<uint16_t, int> potVal;
        // read in all the values! Lets find max
        for(pair< uint16_t, int> p : values)
        {
        
            int curValue = 0; 
             
            for(int i = 0; i < n; ++i)
            {
                uint16_t neighbour = p.first ^ (1 << i);  
                curValue += values[neighbour]; 
            
            
            }
            potVal[p.first] = curValue; 
        }
        vector<int> biggest;
        for(pair<uint16_t, int> p: potVal)
        {
            int biggestNeighbour = 0; 
            for(int i = 0; i < n; ++i)
            {
                uint16_t neighbour = p.first ^ (1<<i);
                if(potVal[neighbour] > biggestNeighbour)
                {
                    biggestNeighbour = potVal[neighbour];
                }
            
            }
            biggest.push_back(p.second + biggestNeighbour);
        }
        sort(biggest.begin(), biggest.end());
        cout << biggest[pow(2,n) - 1] << endl;
    }
    
 









    return 0;
}
