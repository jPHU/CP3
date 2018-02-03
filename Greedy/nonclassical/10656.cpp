#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    bool printed = false;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if(a != 0)
            {
                if(printed) cout << " ";
                printed = true;
                cout << a;
            }
        }
        if(!printed) cout << "0";
        cout << endl;
        printed = false;
    }
}
