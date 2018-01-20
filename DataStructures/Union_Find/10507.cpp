#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

vi p, r, setSize;
int numSets;
void UnionFind(int N) // constructor for N independent groups!
{
    p.clear();
    r.clear();
    setSize.clear();
    r.assign(N,0);
    p.assign(N,0);
    setSize.assign(N,1);
    numSets = N;
    // set them all to their own groups
    for(int i = 0; i < N; ++i)
    {
        p[i] = i;
    }
}

int findSet(int i)
{
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    // sets the parent to the absolute parent as well as reutrning the absolute
    // parent
}

bool inSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j )
{
    if(!inSameSet(i,j))
    {
        int x = findSet(i);
        int y = findSet(j);
        if(r[x] > r[y])
        {
            p[y] = x;
            setSize[x] += setSize[y];
        }
        else
        {
            p[x] = y;
            if(r[x] == r[y]) r[y]++;
            setSize[y] += setSize[x];
        }
        numSets--;

    }

}


int numDisjointSets(){return numSets;}
int sizeOfSet(int i){return setSize[findSet(i)];}
int main(void)
{
    int n;
    while(cin >> n)
    {
        int connections;
        cin >> connections;

        map<char, int> awake;
        map<char, vector<char> > connect;

        string input;
        cin >> input;
        for(char c : input)
        {
            awake[c] = 1;
        }

        while(connections--)
        {
            cin >> input;
            for(char c : input)
            {
                if(awake.find(c) == awake.end()) awake[c] = 0;
            }
            connect[input[0]].push_back(input[1]);
            connect[input[1]].push_back(input[0]);
        }

        int years = 0;
        int numAwake = 3; 
        map<char,int> tempAwake = awake;
        while(numAwake <  n)
        {
            int temp = numAwake;
            for(pair<char, vector<char> > p : connect)
            {
                if(awake[p.first]) continue;
                vector<char> v = p.second;
                int numWoke = 0;
                for(char c : v)
                {
                   if(awake[c]) numWoke++;
                   if(numWoke == 3) break;
                }
                if(numWoke == 3)
                {
                    tempAwake[p.first] = 1;
                    numAwake++;
                }
            }
            if(temp == numAwake) break;
            years++;
            awake = tempAwake;
        }
        if(numAwake == n)
        {
            printf("WAKE UP IN, %d, YEARS\n", years);
        }
        else
        {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
       
    }









    return 0;
}
