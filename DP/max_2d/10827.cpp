#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

// Maximum size is 75*2 = 150
// First row is a dud row with sums 0!
int array[200][200];
int A[200][200];
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(array, 0, 200*200*sizeof(int));
        memset(A, 0, 200*200*sizeof(int));
        int n;
        cin >> n;
        int matSize = 2*n;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                int a;
                cin >> a;
                array[i][j] = a;
                array[i + n][j] = a;
                array[i][j + n] = a;
                array[i + n][j + n] = a;
            }
        }

        // Comput the cumulative sums!
        for(int i = 1; i <= matSize; ++i)
        {
            for(int j = 1; j <= matSize; ++j)
            {
                A[i][j] += array[i][j];
                A[i][j] += A[i-1][j];
                A[i][j] += A[i][j-1];
                A[i][j] -= A[i-1][j-1];
            }
        }

        // Make sure size cannot be larger than n
        // Compute all possible subset sums!
        int best = -100*100;
        for(int i = 1; i <= matSize; ++i)
        {
            for(int j = 1; j <= matSize; ++j)
            {
                // i and j are the top corners
                
                for(int k = i; k <= matSize; ++k)
                {
                    for(int l = j; l <= matSize; ++l)
                    {
                        // (k,l) bottom right corenr
                        if(k - i  + 1 > n) continue;
                        if(l - j + 1 > n) continue;

                        // Compute the current sum
                        int curSum = 0;
                        curSum += A[k][l];
                        curSum -= A[k][j - 1];
                        curSum -= A[i - 1][l];
                        curSum += A[i - 1][j - 1];

                        best = max(best, curSum);
                    }
                }
            }
        }
        cout << best << endl;
    }









    return 0;
}

