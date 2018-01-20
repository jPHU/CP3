#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

struct less_than_key
{
    bool operator()(const pii& a, const pii& b)
    {
        return (a.second*b.first < a.first*b.second);
    }
};

int main(void)
{
    int f, r;
    while(scanf("%d %d", &f,&r) == 2)
    {

        vector<int> frontCluster;
        vector<int> backCluster;
        for(int i = 0; i < f; ++i)
        {
            int n;
            cin >> n;
            frontCluster.push_back(n);
        }
        
        for(int i = 0; i < r; ++i)
        {
            int n;
            cin >> n;
            backCluster.push_back(n);
        }
        sort(frontCluster.begin(), frontCluster.end());
        sort(backCluster.begin(), backCluster.end());
        vii ratios;
        for(int i = 0; i < f; ++i)
        {
            for(int j = 0; j < r; ++j)
            {
                pair<int, int> p(frontCluster[i], backCluster[j]);
                ratios.push_back(p);
            }
        }
        sort(ratios.begin(), ratios.end(), less_than_key());
        int backGear1= 0;
        int frontGear1= 0;
        int backGear2= 0;
        int frontGear2 = 0;
        double curRatio;
        for(size_t i = 1; i < ratios.size(); ++i)
        {

            if(ratios[i].second*ratios[i-1].first*frontGear2*backGear1 >frontGear1 *backGear2* ratios[i-1].second * ratios[i].first || frontGear1 == 0)
            {
                backGear2 = ratios[i].second;
                frontGear2 = ratios[i].first;
                backGear1 = ratios[i-1].second;
                frontGear1 = ratios[i-1].first;
                curRatio = ((backGear2+0.0)/frontGear2)/((backGear1 +0.0)/frontGear1);
            }

        }
        printf("%.2f\n", round(100*(backGear2 + 0.0)/(frontGear2 + 0.0) / ((backGear1 + 0.0)/(frontGear1 + 0.0)))/100.0);
    }









    return 0;
}
