#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        string input;
        cin >> input;
        sort(input.begin(), input.end());
        cout << input << endl;
        while(next_permutation(input.begin(), input.end()))
        {
            cout << input << endl;
        }
    }


    return 0;
}
