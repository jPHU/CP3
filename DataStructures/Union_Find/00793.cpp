#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    r.clear();
    p.clear();
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
    cin >> n;
    while(n--)
    {
        int computers;
        cin >> computers;

        UnionFind(computers);
        string input;
        int success = 0, fail = 0;
        getline(cin, input); // new line char
        while(getline(cin, input) && input != "")
        {
            char dead;
            int a, b;
            stringstream ss(input);
            ss >> dead >> a >> b; 
            if(input[0] == 'c')
            {
                unionSet(a - 1,b - 1);
            }
            else
            {
                if(inSameSet(a - 1, b- 1))
                {
                    success++;
                }
                else
                {
                    fail++;
                }
            }
        }
        cout << success << "," << fail << endl;
        if(n) cout << endl;
    }


















    return 0;
}
