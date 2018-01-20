#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main(void)
{
    int n;
    string input;
    cin >> n;
    getline(cin, input);
    while(n--)
    {
        map<char, vector<char> > adj;
        map<char, int> seen;
        while(cin >> input && input[0] != '*')
        {
            char u, v;
            u = input[1];
            v = input[3];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        stack<char> nodes;
        getline(cin, input);
        if(cin.peek()== '(')
        {
            cout << "There are 0 tree(s) and 0 acorn(s)." << endl;
            continue;
        }
        getline(cin, input);
        for(char c : input)
        {
            if(c < 'A' || c > 'Z') continue;
            nodes.push(c);
            seen[c] = 0;
        }
        if(nodes.empty())
        {
            cout << "There are 0 tree(s) and 0 acorn(s)." << endl;
            continue;
        }
        int trees = 0;
        int acorns = 0;
        while(!nodes.empty())
        {

            stack<char> s;
            int curNode = nodes.top();
            nodes.pop();
            if(seen[curNode]) continue;
            s.push(curNode); 
            bool tree = false;
            while(!s.empty())
            {
                int thisNode = s.top();
                s.pop();
                if(seen[thisNode]) continue;
                seen[thisNode] = 1;

                for(char v : adj[thisNode])
                {
                    if(seen[v]) continue;
                    s.push(v);
                    tree  = true;
                }
            }
            if(tree)
            {
                trees++;
            }
            else
            {
                acorns++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }









    return 0;
}
