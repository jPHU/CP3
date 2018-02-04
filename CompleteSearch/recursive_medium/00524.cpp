#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int k;
vector< vector<int> > solutions;
vector< bool > used(k+1,0);


bool isPrime(int n)
{
    if(n == 1 || n == 2) return true;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}


void computeCases(int n, vector<int>& currentSolution)
{
    if(n == k)
    {
        if(isPrime(currentSolution[0] + currentSolution[n-1]))
        {
            solutions.push_back(currentSolution);
        }
    }
    else
    {
        for(int i = 1; i < k + 1; ++i)
        {
           if(used[i]) continue;
           if(isPrime(i + currentSolution[n-1]))
           {
               currentSolution.push_back(i);
               used[i] = 1;
               computeCases(n + 1, currentSolution);
               used[i] = 0;
               currentSolution.erase(currentSolution.end() - 1);
           }
        }
    }
}

int main(void)
{
    int caseNum = 1;
    while(cin >> k)
    {
        if(caseNum != 1)
        {
            cout << endl;
        }
        printf("Case %d:\n", caseNum++);
        solutions.clear();
        fill(used.begin(), used.end(),0);
        used[1] = 1;
        vector<int> currentSolution;
        currentSolution.push_back(1);
        computeCases(1, currentSolution);

        for(vector<int> s : solutions)
        {
            for(int i = 0; i < s.size(); ++i)
            {
                if(i != 0) cout << " ";
                cout << s[i];
            }
            cout << endl;
        }
    }
}
