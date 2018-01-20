#include <iostream>
#include <stdio.h>
#include <ios>
#include <cstring>
using namespace std;

// To check if the squares are free (0) is free, (1) is full
bool freeSquares[8][8];

char piecePosition[8][8];


int main(void)
{
    while(1)
    {
        memset(freeSquares, 0, sizeof(freeSquares[0][0]) * 32 * 32);
        memset(piecePosition, 0, sizeof(piecePosition[0][0]) * 32 * 32);

        for(int i = 0; i < 8; ++i)
        {
            int counter = 0;
            while(counter < 8)
            {
                char curChar;
                // cin >> curChar;
                if(scanf(" %c", &curChar) != 1) return 0;
                if(curChar == '/') continue;


                if(curChar <= '8' && curChar > '0')
                {
                    counter += curChar - '0';
                }
                else
                {
                    piecePosition[i][counter] = curChar;
                    freeSquares[i][counter] = 1;
                    counter++;
                }

            }

        }

        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                char piece = piecePosition[i][j];
                if(piece == 0) continue;

                if(piece == 'r' || piece == 'R')
                {
                    int x = j + 1;

                    while(x < 8)
                    {
                        if(piecePosition[i][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[i][x] = 1;
                        }
                        x++;
                    }
                    x = j - 1;

                    while(x >= 0)
                    {
                        if(piecePosition[i][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[i][x] = 1;
                        }
                        x--;
                    }



                    int y = i + 1;

                    while(y < 8)
                    {
                        if(piecePosition[y][j] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][j] = 1;
                        }
                        y++;
                    }
                    y = i - 1;

                    while(y >= 0)
                    {
                        if(piecePosition[y][j] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][j] = 1;
                        }
                        y--;
                    }

                }

                if(piece == 'q' || piece == 'Q')
                {
                    int x = j + 1;

                    while(x < 8)
                    {
                        if(piecePosition[i][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[i][x] = 1;
                        }
                        x++;
                    }
                    x = j - 1;

                    while(x >= 0)
                    {
                        if(piecePosition[i][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[i][x] = 1;
                        }
                        x--;
                    }



                    int y = i + 1;

                    while(y < 8)
                    {
                        if(piecePosition[y][j] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][j] = 1;
                        }
                        y++;
                    }
                    y = i - 1;

                    while(y >= 0)
                    {
                        if(piecePosition[y][j] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][j] = 1;
                        }
                        y--;
                    }
                    x = j + 1;
                    y = i + 1;
                    while(x < 8 && y < 8)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y++;
                        x++;
                    }

                    x = j + 1;
                    y = i - 1;
                    while(x < 8 && y >= 0)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y--;
                        x++;
                    }

                    x = j - 1;
                    y = i + 1;
                    while(x >= 0 && y < 8)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y++;
                        x--;
                    }

                    x = j - 1;
                    y = i - 1;
                    while(x >= 0 && y >= 0 )
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y--;
                        x--;
                    }
                }

                if(piece == 'b' || piece == 'B')
                {

                    int x = j + 1;
                    int y = i + 1;
                    while(x < 8 && y < 8)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y++;
                        x++;
                    }


                    x = j + 1;
                    y = i - 1;
                    while(x < 8 && y >= 0)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y--;
                        x++;
                    }

                    x = j - 1;
                    y = i + 1;
                    while(x >= 0 && y < 8)
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y++;
                        x--;
                    }

                    x = j - 1;
                    y = i - 1;
                    while(x >= 0 && y >= 0 )
                    {
                        if(piecePosition[y][x] != 0)
                        {
                            break;
                        }
                        else
                        {
                            freeSquares[y][x] = 1;
                        }
                        y--;
                        x--;
                    }
                }

                if(piece == 'k' || piece == 'K')
                {
                    if(i + 1 < 8)
                    {
                        freeSquares[i+1][j] = 1;
                        if(j + 1 < 8)
                        {
                            freeSquares[i+1][j+1] = 1;
                        }
                        if(j - 1 >= 0)
                        {
                            freeSquares[i+1][j-1] = 1;
                        }
                    }

                    if(j + 1 < 8)
                    {
                        freeSquares[i][j+1] = 1;
                    }
                    if(j - 1 >= 0)
                    {
                        freeSquares[i][j-1] = 1;
                    }

                    if(i - 1 >= 0)
                    {
                        freeSquares[i-1][j] = 1;
                        if(j + 1 < 8)
                        {
                            freeSquares[i-1][j+1] = 1;
                        }
                        if(j - 1 >= 0)
                        {
                            freeSquares[i-1][j-1] = 1;
                        }
                    }
                }

                if(piece == 'p')
                {
                    if(i + 1 < 8 && j + 1 < 8) freeSquares[i+1][j+1] = 1;
                    if(i + 1 < 8 && j - 1 >= 0) freeSquares[i+1][j-1] = 1;

                }

                if(piece == 'P')
                {
                    if(i - 1 >= 0 && j + 1 < 8) freeSquares[i-1][j+1] = 1;
                    if(i - 1 >= 0 && j - 1 >= 0) freeSquares[i-1][j-1] = 1;
                }

                if(piece == 'n' || piece == 'N')
                {
                    if(i + 2 < 8 && j + 1 < 8) freeSquares[i+2][j+1] = 1;
                    if(i + 1 < 8 && j + 2 < 8) freeSquares[i+1][j+2] = 1;
                    if(i - 1 >= 0 && j + 2 < 8) freeSquares[i-1][j+2] = 1;
                    if(i - 2 >= 0 && j + 1 < 8) freeSquares[i-2][j+1] = 1;

                    if(i + 2 < 8 && j - 1 >=0) freeSquares[i+2][j-1] = 1;
                    if(i + 1 < 8 && j - 2 >=0) freeSquares[i+1][j-2] = 1;
                    if(i - 1 >= 0 && j - 2 >=0) freeSquares[i-1][j-2] = 1;
                    if(i - 2 >= 0 && j - 1 >=0) freeSquares[i-2][j-1] = 1;
                }

            }
        }
        int counter = 0;
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                if(freeSquares[i][j] == 0) counter++;
            }
        }
        cout << counter << endl;


    }
    // for(int i = 0; i < 8; ++i)
    // {
    //     for(int j = 0; j < 8; ++j)
    //     {
    //         printf("%c",piecePosition[i][j] == 0 ? '0' : piecePosition[i][j]);
    //     }
    //     printf("\n");
    // }





    return 0;
}
