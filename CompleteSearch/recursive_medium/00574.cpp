#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
vector<int> numbers;
vector<bool> used; // The index that has been used
vector<int> solution;
vector< vector<int> > ans;
void findSums(int sumLeft, int last)
{
    if(sumLeft == 0)
    {
        ans.push_back(solution);
    }
    int justAdded = 0;
    for(int i = last; i < n; ++i)
    {

        while(numbers[i] == justAdded) i++;
        justAdded = 0;
        if(used[i]) continue;
        if( sumLeft - numbers[i] >= 0)
        {
            solution.push_back(numbers[i]);
            used[i] = 1;
            justAdded = numbers[i];
            findSums(sumLeft - numbers[i], i + 1);
            solution.erase(solution.end() - 1);
            used[i] = 0;
        }

    }
}
int main(void)
{
    while(cin >> t >> n && n)
    {
        numbers.clear();
        used.clear();
        ans.clear();
        solution.clear();
        used.resize(n);
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            numbers.push_back(a);
        }
        findSums(t,0);
        printf("Sums of %d:\n", t);
        if(ans.size() == 0)
        {
            cout << "NONE" << endl;
        }
        else
        {
            for(vector<int> v : ans)
            {
                for(int i = 0; i < v.size(); ++i)
                {
                    if(i != 0) cout << "+";
                    cout << v[i];
                }
                cout << endl;
            }
            
        }
    }
    
}
