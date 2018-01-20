#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(void)
{
    int n;
    cin >> n;
    string dummy;
    getline(cin, dummy);
    getline(cin, dummy);// new line char
    while(n--)
    {
        map<string, int> occur;
        string input; 
        int counter = 0;
        while(getline(cin, input) && input != "")
        {
            counter++;
            if(occur.find(input) == occur.end())
            {
                occur[input] = 1;
            }
            else
            {
                occur[input]++;
            }
        }
        for(pair<string, int> p : occur)
        {
           printf("%s %.4lf\n",  p.first.c_str(), 100*p.second/(counter+0.0)); 
        }
        if(n) cout << endl;
    }









    return 0;
}
