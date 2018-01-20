#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
    while(true)
    {
        int n;
        scanf("%d\n",&n);
        if(n == 0)
        {
            break;
        }

        n--;
        string pos = "+x"; // Look at diagram, going counterclockwise from positive x




        while(n--)
        {
            string input;
            cin >> input;

            if(pos == "+x")
            {
                if(input == "+y") pos = "+y";
                if(input == "-y") pos = "-y";
                if(input == "+z") pos = "+z";
                if(input == "-z") pos = "-z";
            }
            else if(pos == "-x")
            {
                if(input == "+y") pos = "-y";
                if(input == "-y") pos = "+y";
                if(input == "+z") pos = "-z";
                if(input == "-z") pos = "+z";
            }


            else if(pos == "-z")
            {
                if(input == "+y") pos = "-z";
                if(input == "-y") pos = "-z";
                if(input == "+z") pos = "+x";
                if(input == "-z") pos = "-x";
            }


            else if(pos == "+z")
            {
                if(input == "+y") pos = "+z";
                if(input == "-y") pos = "+z";
                if(input == "+z") pos = "-x";
                if(input == "-z") pos = "+x";
            }

            else if(pos == "+y")
            {
                if(input == "+y") pos = "-x";
                if(input == "-y") pos = "+x";
                if(input == "+z") pos = "+y";
                if(input == "-z") pos = "+y";
            }


            else if(pos == "-y")
            {
                if(input == "+y") pos = "+x";
                if(input == "-y") pos = "-x";
                if(input == "+z") pos = "-y";
                if(input == "-z") pos = "-y";
            }

        }
        cout << pos << endl;

    }
}
