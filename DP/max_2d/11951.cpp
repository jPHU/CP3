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

int P[101][101];
int cumSum[101][101];

int main(void)
{
    int t;
    cin >> t;
    int caseNum = 1;
    while(t--)
    {
        memset(P, 0, 101*101*sizeof(int));
        memset(cumSum, 0, 101*101*sizeof(int));
        int N, M, K;
        cin >> N >> M >> K;
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                cin >> P[i][j];
            }
        }
        int bestPrice = K + 1;
        int area = -1;

        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                cumSum[i][j] += P[i][j];
                cumSum[i][j] += cumSum[i-1][j];
                cumSum[i][j] += cumSum[i][j-1];
                cumSum[i][j] -= cumSum[i-1][j-1];
            }
        }

        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {

                for(int k = i; k <= N; ++k)
                {
                    for(int l = j; l <= M; ++l)
                    {
                        int curSum = 0;
                        curSum += cumSum[k][l];
                        curSum -= cumSum[i-1][l];
                        curSum -= cumSum[k][j-1];
                        curSum += cumSum[i-1][j-1];
                        
                        if(curSum <= K )
                        {
                            int thisArea = (k - i + 1) * (l - j + 1);
                            if( thisArea > area)
                            {
                                area = thisArea; 
                                bestPrice = curSum;
                            }
                            else if( thisArea == area)
                            {
                                if(bestPrice > curSum)
                                {
                                    bestPrice  = curSum;
                                }
                            }

                        }

                    }
                }


            }
        }
        if(area == -1)
        {
            area = 0;
            bestPrice = 0;
        }
        printf("Case #%d: %d %d\n", caseNum++, area, bestPrice);


    }










    return 0;
}
