#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map<int, int> SAL;
        for(int i = 0; i < b; ++i)
        {
            int start, end;
            scanf("%d %d", &start, &end);
            SAL[start] = end;
        }

        int positions[a];
        for(int i = 0; i < a; ++i)
        {
            positions[i] = 1;
        }
        bool winner = false;
        int curPlayer = 0;
        for(int i = 0; i < c; ++i)
        {
            int roll;
            scanf("%d", &roll);

            if(winner) continue;

            int newPosition = positions[curPlayer] + roll;

            if(newPosition >= 100)
            {
                positions[curPlayer] = 100;
                winner = true;
            }
            // Theres a SNEK
            else if(SAL.find(newPosition) != SAL.end())
            {
                positions[curPlayer] = SAL.find(newPosition)->second;
            }
            else
            {
                positions[curPlayer] = newPosition;
            }
            if(positions[curPlayer] >= 100)
            {
                winner = true;
            }
            curPlayer = (curPlayer + 1) % a;
        }

        for(int i = 0; i < a; ++i)
        {
            printf("Position of player %d is %d.\n", i + 1, positions[i]);
        }


    }




}
