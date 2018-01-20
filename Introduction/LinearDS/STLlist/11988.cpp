#include <list>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    
    string input;
    while(getline(cin, input) && input != "")
    {
        list<char> beiju;
        list<char>::iterator it = beiju.begin();
        for(char c : input)
        {
            if(c == '[')
            {
                it = beiju.begin(); 
            }
            else if (c == ']')
            {
                it = beiju.end();
            }
            else
            {
                beiju.insert(it,c);
            }
        
        
        }
    
        for(char c : beiju)
        {
            cout << c ; 
        }
        cout << endl;
    
    }








    return 0;
}
