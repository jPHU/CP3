#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main(void)
{

    string input;
    while(cin >> input && input != "#")
    {
        if(next_permutation(input.begin(), input.end()))
        {
        
            cout << input << endl; 
        
        
        }
        else
        {
        
        
            cout << "No Successor" << endl;
        }

    
    
    
    }

    








    return 0;
}
