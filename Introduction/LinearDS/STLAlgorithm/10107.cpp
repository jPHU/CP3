#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(void)
{



    int n;
    vector<int> inputs;
    int numElements = 0;
    while(scanf("%d",&n) == 1)
    {
        numElements++;
        inputs.push_back(n);
        sort(inputs.begin(), inputs.end());
        
        if(numElements%2)
        {
        
        
            cout << inputs[numElements/2] << endl; 
        
        
        
        }
        else
        {
        
        
            cout << (inputs[numElements/2 - 1] + inputs[numElements/2])/2  << endl;
        
        }
    
    }






    return 0;
}
