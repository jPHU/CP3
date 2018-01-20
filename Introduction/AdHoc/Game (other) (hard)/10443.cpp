#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



int main(void)
{
    int testCases;
    scanf("%d",&testCases);

    while(testCases--)
    {
        int r, c, n;
        scanf("%d %d %d", &r, &c, &n);

        char board[r+2][c+2];
        char newBoard[r+2][c+2];
        memset(board, 0, sizeof(board[0][0])*(r+2)*(c+2));
        memset(newBoard, 0, sizeof(newBoard[0][0])*(r+2)*(c+2));

        for(int i = 1; i < r + 1; ++i)
        {
            for(int j = 1; j < c + 1; ++j)
            {
                char curChar;
                scanf(" %c", &curChar);
                board[i][j] = curChar;
            }
        }

        // n iterations
        while(n--)
        {
            for(int i = 1; i < r + 1; ++i)
            {
                for(int j = 1; j < c + 1; ++j)
                {
                    char winner;
                    if(board[i][j] == 'R')
                    {
                        winner = 'P';
                    }
                    else if(board[i][j] == 'P')
                    {
                        winner = 'S';
                    }
                    else if(board[i][j] == 'S')
                    {
                        winner = 'R';
                    }

                    bool winnerFound = false;


                    if(board[i+1][j] == winner) winnerFound = true;
                    if(board[i][j-1] == winner) winnerFound = true;
                    if(board[i][j+1] == winner) winnerFound = true;
                    if(board[i-1][j] == winner) winnerFound = true;

                    if(winnerFound)
                    {
                        newBoard[i][j] = winner;
                    }
                    else
                    {
                        newBoard[i][j] = board[i][j];
                    }
                }
            }
            // for(int i = 1; i < r + 1; ++i)
            // {
            //     for(int j = 1; j < c + 1; ++j)
            //     {
            //         printf("%c", board[i][j]);
            //     }
            //     printf("\n");
            // }
            memcpy(board, newBoard, sizeof(newBoard[0][0])*(r+2)*(c+2));
        }
        for(int i = 1; i < r + 1; ++i)
        {
            for(int j = 1; j < c + 1; ++j)
            {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }

        if(testCases != 0) printf("\n");

    }
    return 0;
}
