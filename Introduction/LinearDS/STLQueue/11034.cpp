#include <cstdio>
#include <queue>
#include <iostream>

#include <string>
using namespace std;


int main(void)
{
    int n;

    cin >> n;
    while(n--)
    {
        queue<long> left;
        queue<long> right;
        int l, m;
        cin >> l >> m;
        for(int i = 0; i < m; ++i)
        {
            string inp;
            int val; 
            cin >> val >> inp;
            if(inp == "left")
            {
                left.push(val);
            }
            else
            {
                right.push(val);
            }
        }
        int numberCrosses = 0;
        bool leftBank = true;
        while(m > 0)
        {
            int curSpace = l*100; 
            if(leftBank)
            {
                while(!left.empty())
                {
                    if(curSpace - left.front() > 0)
                    {
                        curSpace -= left.front();
                        left.pop();
                        m--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                
                while(!right.empty())
                {
                    if(curSpace - right.front() > 0)
                    {
                        curSpace -= right.front();
                        right.pop();
                        m--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            numberCrosses++;
            leftBank = !leftBank;
        }
        cout << numberCrosses << endl;
    }





    return 0;
}
