#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        int k;
        scanf("%d",  &k);
        map<char, int> maps;
        while(k--)      
        {
            char input;
            int price;
            scanf(" %c %d", &input, &price);
            maps[input] = price;
        
        
        
        }
        int value = 0;
        string input;
        input.reserve(10000);
        scanf("%d", &k);

        getline(cin, input); // \n
        while(k--)
        {
            getline(cin, input);
            for(char c : input)
            {
                if(maps.find(c) != maps.end())
                {
                    value += maps[c];
                
                }


            } 
        
        }
        
        printf("%d.%.2d$\n", value/100, value%100); 
    
    }








    return 0;
}
