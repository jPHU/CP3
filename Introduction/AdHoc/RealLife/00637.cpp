#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    int pages;
    while(scanf("%d",&pages) && pages != 0)
    {
        int remaining = pages%4 == 0 ? 0 : 4 - pages % 4;


        printf("Printing order for %d pages:\n", pages);

        int counterHigher = pages;
        int counterLow = 1;

        int remainingPages = pages;
        // The sheets
        for(int i = 0; i < pages/4 + 1; ++i)
        {
            printf("Sheet %d, front: ", i + 1);

            if(remaining > 0)
            {
                printf("Blank, %d\n", counterLow++);
                remainingPages--;
            }
            else
            {
                printf("%d, %d\n", counterHigher--, counterLow++);
                remainingPages -= 2;
            }

            remaining--;
            if(remainingPages <= 0) break;
            printf("Sheet %d, back : ", i + 1);


            if(remaining > 0)
            {
                printf("%d, Blank\n", counterLow++);
                remainingPages--;
            }
            else
            {
                printf("%d, %d\n", counterLow++, counterHigher--);
                remainingPages -=2;
            }

            remaining--;
            if(remainingPages <= 0) break;
        }



    }




    return 0;
}
