#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > adj;


vector<bool> ans;
vector<bool> black;
vector<bool> set;
int n, k;


void findColouring(int seen, int colouringIndex)
{
    for(vector<int> neighbour : adj[colouringIndex])
    {
        if(black[colouringIndex])
        {
            seen++;
            adj[]
        }
    }
}
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        adj.clear();
        black.clear();
        cin >> n >> k;
        adj.resize(n);
        black.assign(n, 0);

        for(int i = 0; i < k; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        findColouring(0);

        black.clear();
        black.assign(n,0);
        black[0] = 1;
        findColouring(0);
        
    }
}
