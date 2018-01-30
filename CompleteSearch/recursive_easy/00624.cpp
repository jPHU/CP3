#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> bestVec;
int goal, best;

void findBest(vector<int> currentPick, int index, int value)
{
    for(size_t i = index; i < numbers.size(); ++i)
    {
        if(value + numbers[i] <= goal)
        {
            currentPick.push_back(numbers[i]);
            if(-value - numbers[i] +  goal < (goal - best))
            {
                best = value + numbers[i];
                bestVec = currentPick;
            }
            findBest(currentPick, i + 1, value + numbers[i]);
            currentPick.erase(currentPick.end() - 1);
            

        }
    }

}
 
int main(void)
{
    numbers.reserve(20);
    while(cin >> goal)
    {
        numbers.clear();
        best = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            numbers.push_back(a);
        }
        findBest(vector<int>(),0, 0);
        for(size_t i = 0; i < bestVec.size(); ++i)
        {
            cout << bestVec[i]  << " ";
        }
        cout << "sum:" <<  best << endl;
    }

}
