#include <stack>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;


int main(void)
{
    int n;
    while(scanf("%d", &n) == 1 && n != 0 )
    {







        while(1)
        {
            queue<int> trains;
            for(int i = 0; i < n; ++i)
            {
                trains.push(i+1);

            }
            stack<int> trainStack;
            bool done = false;
            bool empty = false; 
            for(int i = 0; i < n; ++i)
            {
                int reOrder;
                scanf("%d", &reOrder);
                if(reOrder == 0)
                {
                    done = true;
                    cout << endl;
                    break;
                }
                while(trainStack.empty() || trainStack.top() != reOrder)
                {
                    if(trains.empty())
                    {
                        empty = true;
                        break;
                    }
                    trainStack.push(trains.front()); 
                    trains.pop();
                }
                if(!trainStack.empty()) trainStack.pop();

            }
            if(done) break; 
            if(empty)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }

        }







    }

    return 0;
}
