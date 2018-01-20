#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

class UnionFind
{
    private: vi p, r, setSize;
             int numSets;
    public:
             UnionFind(int N) // constructor for N independent groups!
             {
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
};
int main(void)
{










    return 0;
}
