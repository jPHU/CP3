#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int n, built;

struct OverlapClass{
    long towerOver;
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
        vector<OverlapClass> overlap;
        for(int i = 0; i < m; ++i)
        {
            int towers;
            cin >> towers;
            long towerOver = 0;
            for(int j = 0; j < towers; ++j)
            {
                int curTower;
                cin >> curTower;
                towerOver |= (1 << (curTower-1)); 
            }
            int overlapNum;
            cin >> overlapNum;
            OverlapClass oc;
            oc.towerOver = towerOver;
            oc.num = overlapNum;
            overlap.push_back(oc);

                
        }
        unsigned long locations;
        int value = 0;
        long comp = 1 << n;
        long v = ( 1 << built)-1;
        while(v < (comp))
        {
            int people = 0;
            for(size_t i = 0; i < (size_t)n; ++i)
            {
                people += ((long)(1<<i))&v? towersServiced[i]  : 0;
            }

            for(size_t i = 0; i < overlap.size(); ++i)
            {
                OverlapClass oc = overlap[i];
                long numOverlapped = oc.towerOver & v;
                if(numOverlapped > 1)
                {
                    bitset<32> x = numOverlapped; 
                    people -= ((x.count()-1))* oc.num;
                }
            }
            if(people > value)
            {
                value = people;
                locations = v;
            }
            unsigned long t = (v| (v - 1)) + 1;
            v = t | ((((t & -t) / (v & -v)) >> 1) - 1);
        }
        printf("Case Number  %d\n",caseNum++);
        printf("Number of Customers: %d\n", value);
        printf("Locations recommended: ");
        int first = 0;
        for(int i = 0; i < n; ++i)
        {
            if( (1<<i)&locations)
            {
                if(first++) cout  << " ";
                cout << i + 1;
            }
        }
        cout << endl;
        cout << endl;










    }









    return 0;
}
