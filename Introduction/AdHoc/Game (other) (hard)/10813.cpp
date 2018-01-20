#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int board[5][5];
bool strike[5][5];
bool checkWinner()
{
    // Check vertical
    for(int i = 0; i < 5; ++i)
    {
        bool winner1 = true;
        bool winner2 = true;
        for(int j = 0; j < 5; ++j)
        {
            if(strike[i][j] == 0) winner1 = false;
            if(strike[j][i] == 0) winner2 = false;
        }
        if(winner1 || winner2)
        {
            return true;
        }
    }

    bool winner = true;
    for(int i = 0, j = 0; i < 5; ++i, ++j)
    {
        if(strike[i][j] == 0) winner = false;
    }
    if(winner)
    {
        return true;
    }

    winner = true;
    for(int i = 0, j = 4; i < 5; ++i, --j)
    {
        if(strike[i][j] == 0) winner = false;
    }
    if(winner)
    {
        return true;
    }
    return false;

}

int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(board, 0, sizeof(board[0][0])*5*5);
        memset(strike, 0, sizeof(strike[0][0])*5*5);

        strike[2][2] = 1;

        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(i == 2 && j == 2) continue;
                int num;
                scanf("%d",&num);
                board[i][j] = num;
            }
        }
        bool winner = false;
        int winnerIndex = 0;
        for(int k = 0; k < 75; ++k)
        {
            int num;
            scanf("%d", &num);
           if(winner)
           {

           }
           else
           {



            for(int i = 0; i < 5; ++i)
            {
                for(int j = 0; j < 5; ++j)
                {
                    if(board[i][j] == num)
                    {
                        strike[i][j] = 1;
                        break;
                    }
                }
            }

            if(checkWinner())
            {
                winner = true;
                winnerIndex = k + 1;
            }
        }

        }

        printf("BINGO after %d numbers announced\n", winnerIndex);


    }
    return 0;
}
