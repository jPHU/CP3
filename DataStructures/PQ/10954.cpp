#include <cstdio>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;


int main(void)
{
    long n;
    while(scanf("%lu", &n) && n != 0)
    {

        priority_queue<long, vector<long>, greater<long>> pq;
        while(n--)
        {
            long num;
            cin >> num;
            pq.push(num);
        }
        int cost = 0;
        while(pq.size() > 1)
        {
            int curCost = 0;
            curCost += pq.top();
            pq.pop();
            curCost += pq.top();
            pq.pop();
            pq.push(curCost); 
            cost += curCost;
        }
        cout << cost << endl; 


    }



    return 0;
}
