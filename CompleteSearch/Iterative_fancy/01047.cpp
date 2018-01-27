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

int n, built;

void increment(vector<int>& v,int index)
{
    v[index]++;
    if(v[index] > n - 1)
    {
        if(index == 0)
        {
            return;
        }
        increment(v, index - 1);
        v[index] = v[index-1] + 1;
    }
}
struct OverlapClass{
    vector<int> v;
    int num;
};

int main(void)
{
    int caseNum = 1;
    while(cin >> n >> built && n && built)
    {
        vector<int> towersServiced(n,0);
        for(int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            towersServiced[i] = num;
        }
        int m;
        cin >> m;
        vector<vector<OverlapClass> > overlap(n);
        for(int i = 0; i < m; ++i)
        {
            int towers;
            cin >> towers;
            vector<int> towerOver;
            for(int j = 0; j < towers; ++j)
            {
                int curTower;
                cin >> curTower;
                towerOver.push_back(curTower-1);
            }
            OverlapClass oc;
            oc.v.assign(towerOver.begin(), towerOver.end());
            int overlapNum;
            cin >> overlapNum;
            oc.num = overlapNum;
            for(int j = 0; j < towers; ++j)
            {
                overlap[towerOver[j]].push_back(oc);
            }
        }
        vector<int> towersChosen(built);
        for(int i = 0; i < built; ++i)
        {
            towersChosen[i] = i;
        }
        vector<int> locations;
        int value = 0;

        while(1)
        {

            int people = 0;
            for(size_t i = 0; i < towersChosen.size(); ++i)
            {
                people += towersServiced[towersChosen[i]];
                for(OverlapClass oc : overlap[towersChosen[i]])
                {
                    for(size_t j = 0; j < i; ++j)
                    {
                       if(find(oc.v.begin(), oc.v.end(), towersChosen[j]) != oc.v.end() && find(oc.v.begin(), oc.v.end(), towersChosen[i]) != oc.v.end())
                       {
                           people -= oc.num; 
                           break;
                       }
                    }
                }
            }
            if(people > value)
            {
                value = people;
                locations.assign(towersChosen.begin(), towersChosen.end());
            }
            increment(towersChosen, built - 1);
            if(towersChosen[0] >= n - built) break;
        }
        printf("Case Number %d\n",caseNum++);
        printf("Number of Customers: %d\n", value);
        printf("Locations recommended: ");
        int first = 0;
        for(int l : locations)
        {
            if(first++) cout  << " ";
            cout << l + 1;
        }
        cout << endl;
        cout << endl;










    }









    return 0;
}
