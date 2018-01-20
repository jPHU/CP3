#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
map<string, string> p; // parent;
map<string, int> r; // rank
map<string, int> sizeSet; // size of the current set

string findSet(string i)
{

    return (i == p[i] ? i : (p[i] = findSet(p[i])));
}

bool inSameSet(string a, string b)
{
    return(findSet(a) == findSet(b));
}
void unionSet(string a, string b)
{
    if(!inSameSet(a,b))
    {
        string parentA = findSet(a);
        string parentB = findSet(b);
        if(r[parentA] > r[parentB])
        {
            p[parentB] = parentA;
            sizeSet[parentA] += sizeSet[parentB];
        }
        else
        {
            p[parentA] = parentB;
            sizeSet[parentB] += sizeSet[parentA];
            if(r[parentA] == r[parentB]) r[parentB]++;
        }
    }
}
int setSize(string a)
{

    return sizeSet[findSet(a)];
}

int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        p.clear();
        r.clear();
        sizeSet.clear();

        int people;
        cin >> people;
        string a,b;
        while(people--)
        {
            cin >> a >> b;
            if(p.find(a) == p.end())
            {
                sizeSet[a] = 1;
                p[a] = a;
                r[a] = 1;
            }
            if(p.find(b) == p.end())
            {
                sizeSet[b] = 1;
                p[b] = b;
                r[b] = 1;
            }
            unionSet(a,b);
            cout << setSize(a) << endl;
        

            
        }

    }








    return 0;
}
