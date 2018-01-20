#include <iostream>
#include <stdio.h>
#include <limits>
using namespace std;

int main(void)
{
    int num, budget, hotels, weeks;
    while(scanf("%d %d %d %d", &num, &budget, &hotels, &weeks) == 4)
    {
        int minPrice = 500001;
        bool found = false;
        for(int i = 0; i < hotels; ++i)
        {
            int price;
            scanf("%d\n",&price);
            for(int j = 0; j < weeks; ++j)
            {
                int numPeople;
                scanf("%d",&numPeople);
                if(numPeople >= num)
                {
                    if(price*num <= budget)
                    {
                        if(price*num < minPrice)
                        {
                            minPrice = price*num;
                            found = true;
                        }
                    }
                }
            }
        }

        if(found)
        {
            printf("%d\n",minPrice);
        }
        else
        {
            printf("stay home\n");
        }



    }





}
