#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(void)
{
    int field = 1;
    while(1)
    {
        int r,c;
        scanf("%d %d", &r, &c);
        if(r == 0 ||  c == 0) return 0;
        if(field != 1)
        {
            printf("\n");
        }
        printf("Field #%d:\n",field++);

        // Gonna set row 1 = row 1
        bool mineField[r + 2][c + 2];
        memset(mineField, 0, sizeof(mineField[0][0])*(r+2)*(c+2));
        for(int i = 1; i < r + 1; ++i)
        {
            for(int j = 1; j < c + 1; ++j)
            {
                char input;
                scanf(" %c", &input);
                mineField[i][j] = input == '*' ? 1 : 0;
            }
        }

        for(int i = 1; i < r + 1; ++i)
        {
            for(int j = 1; j < c + 1; ++j)
            {
                if(mineField[i][j] == 1)
                {
                    printf("*");
                }
                else
                {
                    int counter = 0;
                    if(mineField[i+1][j] == 1) counter++;
                    if(mineField[i+1][j-1] == 1) counter++;
                    if(mineField[i+1][j+1] == 1) counter++;
                    if(mineField[i][j+1]==1) counter++;
                    if(mineField[i][j-1]==1) counter++;
                    if(mineField[i-1][j] == 1) counter++;
                    if(mineField[i-1][j-1] == 1) counter++;
                    if(mineField[i-1][j+1] == 1) counter++;
                    printf("%d",counter);
                }
            }
            printf("\n");
        }


    }



    return 0;
}
