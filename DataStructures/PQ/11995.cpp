#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main(void)
{
    int n;
    while(cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int>pq;
        bool boolS = true;
        bool boolQ = true;
        bool boolPQ= true;
        while(n--)
        {
            int a, b;
            cin >> a >> b;
            if(a == 1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if(s.empty() || q.empty() || pq.empty())
                {
                    boolS = false;
                    boolQ = false;
                    boolPQ = false;
                    continue;
                }
                else
                {
                    int popped;
                    popped = s.top();
                    s.pop();
                    if(popped != b ) boolS = false;

                    popped = q.front();
                    q.pop();
                    if(popped != b) boolQ = false;

                    popped = pq.top();
                    pq.pop();
                    if(popped != b) boolPQ = false;
                }
            }
        }
        if(!boolS && !boolQ && !boolPQ)
        {
            cout << "impossible" << endl;
        }
        else if (boolS && !boolQ && !boolPQ)
        {
            cout << "stack" << endl;
        }
        else if (!boolS && boolQ && !boolPQ)
        {
            cout << "queue" << endl;
        }
        else if(!boolS && !boolQ && boolPQ)
        {
            cout << "priority queue" << endl;
        }
        else
        {
            cout << "not sure" << endl;
        }

    }









    return 0;
}
