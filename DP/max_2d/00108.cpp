#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;



int main(void)
{
    int n;
    while(cin >> n)
    {
        int array[105][105];
        memset(array, 0, 105*105*sizeof(int));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                scanf("%d",array[i] + j);
            }
        }

        int A[105][105];

        memset(A, 0, 105*105*sizeof(int));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                A[i][j] += array[i][j];
                if(i > 0)
                {
                    A[i][j] += A[i-1][j];
                }
                if(j > 0)
                {
                    A[i][j] += A[i][j-1];
                }
                if(i > 0 && j > 0)
                {
                    A[i][j] -= A[i-1][j-1];
                }
            }
        }
        int best = -999999;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                for(int k = i; k < n; ++k)
                {
                    for(int l = j; l < n; ++l)
                    {
                        int subValue = 0;
                        subValue += A[k][l];
                        if(i > 0)
                        {
                            subValue -= A[i-1][l];
                        }
                        if(j > 0)
                        {
                            subValue -= A[k][j-1];
                        }
                        if(i > 0 && j > 0)
                        {
                           subValue += A[i-1][j-1];
                        }
                        if(subValue > best)
                        {
                            best = subValue;
                        }
                    }
                }
            }
        }
        cout << best << endl;
    }

}
