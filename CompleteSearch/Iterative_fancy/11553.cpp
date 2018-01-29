#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;



int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector< vector<int> > board(n, vector<int>(n,0));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j  < n; ++j)
            {
                int a;
                cin >> a;
                board[j][i] = a;
            }
        }
        int bob[n];
        for(int i = 0 ; i < n; ++i)
        {
            bob[i] = i;
        }
        int best = 1005*n;

       
            do{

                int currentScore = 0;
                vector<bool> row(n,0);
                for(int i = 0; i < n; ++i)
                {
                    int curMin = 1005*n;
                    int rowChosen = 0;
                    for(int j = 0; j < n; ++j)
                    {
                        if( board[bob[i]][j] < curMin && !row[j])
                        {
                            curMin = board[bob[i]][j];
                            rowChosen = j;
                        }
                        
                    }
                    row[rowChosen] = 1;
                    currentScore += curMin;
                }
                if(currentScore < best)
                {
                    best = currentScore;
                }
                 
            
            
            }while(next_permutation(bob, bob+n));
        
        
        
        

       cout << best << endl; 
    }









    return 0;
}
