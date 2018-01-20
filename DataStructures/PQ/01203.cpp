#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Query
{
    public:
        int qNum;
        int query;
        int period;
};
typedef pair<int,int> pii;
struct Compare
{
    bool operator()(const Query& left, const Query& right)
    {

        if(left.query != right.query)
        {
            return left.query > right.query; // make it a min heap!
        }
        else
        {
            return left.qNum > right.qNum; // smaller q number first
        }
    }
};
int main(void)
{
    string inputs;
    priority_queue< Query, vector<Query>, Compare> pq;
    while(cin >> inputs && inputs != "#")
    {
        Query q;
        cin >> q.qNum >> q.query;
        q.period = q.query; 
        pq.push(q);
    }
    int numberQueries;
    cin >> numberQueries;
    while(numberQueries--)
    {
        cout << pq.top().qNum << endl;
        Query p = pq.top();
        pq.pop();
        p.query += p.period;
        pq.push(p);
    }











    return 0;
}
