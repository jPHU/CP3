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
int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,24,26,28,30,32,34,36,38,40,21,27,33,39,42,45,48,50,51,54,57,60};
int main(void)
{
    int score;
    vector<int> vec;
    vec.assign(array, array + 43);
    sort(vec.begin(), vec.end());
    while(cin >> score && score > 0)
    {
        int permutations = 0;
        for(int i = 0; i < vec.size() ; ++i)
        {
            for(int j = 0; j < vec.size(); ++j)
            {
                for(int k = 0; k < vec.size(); ++k)
                {
                    if(vec[i] +vec[j] + vec[k] == score)
                    {
                        permutations++;
                    }
                }
            }
        }
        int combinations = 0;
        for(int i = 0; i < vec.size(); ++i)
        {
            for(int j = i; j < vec.size(); ++j)
            {
                for(int k = j; k < vec.size(); ++k)
                {
                    
                    if(vec[i] +vec[j] + vec[k] == score)
                    {
                        combinations++;
                    }
                }
            }
        }
        if(permutations != 0)
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combinations);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutations);
        }
        else
        {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        }
        for(int i = 0; i < 70; ++i) printf("*");
        printf("\n");
    }
    printf("END OF OUTPUT\n");









    return 0;
}
