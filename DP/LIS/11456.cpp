#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define MAXN 2000

int L[MAXN];
int L_id[MAXN];
int X[MAXN];

bool greaterComparator( int a, int b)
{
    return a > b;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {

        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> X[i];
        }

        int longest = 0;
        // Starting index
        for(int i = 0; i < n; ++i)
        {
            // Force it to start at this index!
            L[0] = X[i];
            L_id[0] = i;


            // DP
            int seqLen = 1;
            for(int j = i + 1; j < n; ++j)
            {

                if(X[j] < X[i]) continue;
                int* ptr = lower_bound(L + 1, L + seqLen, X[j]);
                // Compute increasing subsequence! 
                int pos = ptr - L;

                // Set the value that pos the best value is X[j]
                L[pos] = X[j];

                // Set the index!
                L_id[pos] = j;


                if(pos + 1 > seqLen)
                {
                    seqLen = pos + 1;
                }
            }

            int increasing = seqLen;
            // Force it to start at this index!
            L[0] = X[i];
            L_id[0] = i;


            // DP
            seqLen = 1;
            for(int j = i + 1; j < n; ++j)
            {

            
                if(X[j] > X[i]) continue;
                int* ptr = lower_bound(L + 1, L + seqLen, X[j], greaterComparator);
                // Compute increasing subsequence! 
                int pos = ptr - L;

                // Set the value that pos the best value is X[j]
                L[pos] = X[j];

                // Set the index!
                L_id[pos] = j;

                if(pos + 1 > seqLen)
                {
                    seqLen = pos + 1;
                }
            }
            longest = max(longest, seqLen + increasing - 1);

        }
        cout << longest << endl;
    }










    return 0;
}
