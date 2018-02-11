#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int pmod(int i, int n) {
    return (i % n + n) % n;
}

int main(void)
{
    int n, q;
    int caseNum = 1;
    while(cin >> n >> q && n && q)
    {
        vector<ll> inputs(n,0);
        for(int i = 0; i < n; ++i)
        {
            cin >> inputs[i];
        }
        printf("SET %d:\n", caseNum++);
        int qNum = 1;
        int d,m;

        while(q--)
        {
            bool seen = false;
            if(1)
            {

                cin >> d >> m;
                seen = true;
            }

        

            if(seen)
            {

                // First dimension is  after considering item i
                // Second dimension is using j items
                // Third dimension is achieving a sum of k
                vector< vector< vector<ll> > >  OPT(n+1,vector<vector<ll> >(m+1,vector<ll>(d,0)));

                // Base case!
                // Considering ALL items
                for(int i = 1; i < n + 1; ++i)
                {
                    // Considering ALL possible number of items used!
                    for(int j = 1; j < m + 1; ++j)
                    {
                        if(j == 1)
                        {
                            // Add this item
                            OPT[i][j][pmod(inputs[i-1],d)] = 1;


                            for(int k = 0; k < d; ++k)
                            {
                                OPT[i][j][k] += OPT[i-1][j][k];
                            }

                        }
                        else
                        {
                            for(int k = 0; k < d; ++k)
                            {
                                // Number of ways considering all items before i-1
                                // Considering selecing ONLY j items
                                // Producing a sum of k
                                int numWays = OPT[i-1][j-1][k];
                                OPT[i][j][pmod((k + inputs[i-1]) , d)] += numWays;


                                // Not include current element
                                OPT[i][j][k] += OPT[i-1][j][k];
                            }
                        }

                    }

                }

                printf("QUERY %d: %lld\n", qNum++, OPT[n][m][0]);
            }


        }

    }









    return 0;
}
