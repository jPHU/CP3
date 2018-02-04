#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector< vector<int> > sequence;

bool digit[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
bool found = false;
vector< bool > broken;
void checkMatch(int pos, int last)
{
    if(pos == sequence.size()) found = true;
    else
    {
        for(int i = 0; i < 7; ++i)
        {
            // If it is on but it was broken before
            if( sequence[pos][i] && broken[i]) return; 

            // Needs to be on
            if( digit[last][i] )
            {
                // It is already on
                if( sequence[pos][i] ) continue;

                // It is not on, so lets just say it is broken
                if( !sequence[pos][i] ) broken[i] = 1;

            }

            // If it needs to be off
            else
            {
                if( sequence[pos][i] ) return;
            }
        }
        checkMatch( pos + 1, last - 1);
    }
}

int main(void)
{
    int n;

    while(cin >> n && n)
    {
        sequence.clear();
        broken.clear();
        broken.assign(7,0);
        string inp;
        found =false;
        for(int i = 0; i < n; ++i)
        {
            cin >> inp;

            vector<int> curInp(7,0);
            for(int j = 0; j <= 7; ++j)
            {
                if(inp[j] == 'Y') curInp[j] = 1;
            }
            sequence.push_back(curInp);
        }
        for(int i = 9; i >= sequence.size() - 1; i--)
        {
            if(found) break;
            checkMatch(0,i);
            broken.clear();
            broken.assign(7,0);
        }
        if(found) cout << "MATCH" << endl;
        else cout << "MISMATCH" << endl;
    }

}
