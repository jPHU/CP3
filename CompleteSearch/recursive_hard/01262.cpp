#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int k;
int numSoln;
vector<char> soln;
vector<char> ans;
vector< vector<bool> > valid; // wheel[j][i] is the column j index i
vector< vector<char> > wheel; // wheel[j][i] is the column j index i
void findSoln(int pos)
{
    if(pos == 5)
    {
        // Check if it is valid
        for(int j = 0; j < 5; ++j)
        {
            if(valid[j][soln[j] - 'A'] != 1)
            {
                return;
            }
        }

        numSoln++;

        if(numSoln == k)
        {
            ans = soln;
        }
    }
    else
    {
        char pastChar = '0';
        for(int i = 0; i < 6; ++i)
        {
            if(wheel[pos][i] == pastChar)
            {
                continue;
            }
            else
            {
                pastChar = wheel[pos][i];
            }
            soln.push_back(wheel[pos][i]);
            findSoln(pos + 1);
            soln.erase(soln.end() - 1);
        }
    }
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        numSoln = 0;
        soln.clear();
        wheel.clear();
        valid.clear();
        valid.assign(5, vector<bool>(26,0));
        wheel.assign(5, vector<char>(6,0));

        cin >> k;
        for(int i = 0; i < 6; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                char a;
                cin >> a;
                wheel[j][i] = a;
            }
        }

        for(int i = 0; i < 6; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                char a;
                cin >> a;
                valid[j][a - 'A'] = 1;
            }
        }

        for(int j = 0; j < 5; ++j)
        {
            sort(wheel[j].begin(), wheel[j].end());
        }

        findSoln(0);
        if(numSoln < k) cout << "NO" << endl;
        else
        {
            for(char a : ans)
            {
                cout << a;
            }
            cout << endl;
        }


    }










    return 0;
}
