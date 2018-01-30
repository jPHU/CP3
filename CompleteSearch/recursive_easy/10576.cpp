#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

int s, d;
int best = 0;
vector<int> bestNumbers;

void find_best(vector<int> values, int currentSurplus, int index, int totalSurplus)
{
    if(index == 12)
    {
        if(totalSurplus > best)
        {
            best = totalSurplus;
            bestNumbers = values;
        }
        return;
    }

    if(index <= 4)
    {
        values.push_back(s);
        find_best(values, currentSurplus + s, index + 1, totalSurplus + s);
        values.erase(values.end() - 1);

        values.push_back(-d);
        find_best(values, currentSurplus - d, index + 1, totalSurplus - d);
        values.erase(values.end() - 1);
    }
    else
    {
        if(currentSurplus > 0) return;
        if( currentSurplus - values[0] + s < 0)
        {
            vector<int> temp = values;
            temp.push_back(s);
            temp.erase(temp.begin());
            find_best(temp, currentSurplus + s - values[0], index + 1, totalSurplus + s);
        }
        if (currentSurplus - values[0] - d < 0)
        {
            
            vector<int> temp = values;
            temp.push_back(-d);
            temp.erase(temp.begin());
            find_best(temp, currentSurplus - d - values[0], index + 1, totalSurplus - d);
        }
        else
        {
            return;
        }
    }
}
int main(void)
{
   while(scanf("%d %d", &s, &d) == 2)
   {
       best = 0;
       vector<int> values;
       find_best(values, 0, 0,0);
       if(best)
       {
           cout << best << endl;
       }
       else
       {
           cout << "Deficit" << endl;
       }
   }









    return 0;
}
