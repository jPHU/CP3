#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main(void)
{
    while(1)
    {
        string input;
        getline(cin, input);
        if(input == "Game Over")
        {
            break;
        }
        // 2 points for each  thing
        int score = 0;
        int strike[11];
        int spare[11];
        memset(strike,0,sizeof(strike[0])*10);
        memset(spare,0,sizeof(spare[0])*10);


        int i = 0;
        bool first = true;
        int firstScore = 0;

        for(char c : input)
        {
            if(c == ' ' || c == '\r') continue;
            if(c == '/')
            {
                spare[i] = true;
            }
            if(c == 'X')
            {
                strike[i] = true;
            }


            if(c == '/' )
            {
                score += 10 - firstScore;

                if(i - 1 >= 0 && i < 10)
                {
                    if(strike[i-1]) score += 10 - firstScore;
                }

                i++;
                firstScore = 0;
                first = true;
            }
            else if(c == 'X')
            {
                score += 10;
                if(i - 1 >= 0 && i < 10)
                {
                    if(spare[i-1] || strike[i-1]) score += 10;
                }
                if(i - 2 >= 0 && i < 11)
                {
                    if(strike[i-2] && strike[i-1]) score += 10;
                }
                i++;

                firstScore = 0;
                first = true;
            }
            else
            {
                score += c - '0';


                if(first)
                {
                    firstScore = c - '0';
                    first = false;
                    if(i - 1 >= 0 && i < 10)
                    {
                        if(spare[i-1] || strike[i-1]) score += c - '0';
                    }
                    if(i - 2 >= 0 && i < 11)
                    {
                        if(strike[i-2] && strike[i-1]) score += c - '0';
                    }
                }
                else
                {
                    firstScore = 0;
                    if(i - 1 >= 0 && i < 10)
                    {
                        if(strike[i-1]) score += c - '0';
                    }
                    i++;
                    first = true;
                }
            }
        }
        printf("%d\n",score);

    }
    return 0;
}
