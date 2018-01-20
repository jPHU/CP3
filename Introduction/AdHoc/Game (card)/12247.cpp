#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{

    while(1)
    {
        vector<int> usedCards(53,0);
        vector<int> prince(2,0);
        vector<int> princess(3,0);
        for(int i = 0; i < 3; ++i)
        {
            int num;
            scanf("%d", &num);
            princess[i] = num;
            usedCards[num] = 1;
        }
        for(int i = 0; i < 2; ++i)
        {
            int num;
            scanf("%d", &num);
            prince[i] = num;
            usedCards[num] = 1;
        }
        if(princess[0] == 0)
        {
            break;
        }

        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());

        int princeIndex = 0;
        int princessIndex = 0;

        int princessFirstCardWin = 0;
        // How many princess cards higher than princes
        while(princess[princessIndex] < prince[princeIndex] && princessIndex != 3)
        {
            princessIndex++;
        }


        // If we reach here the princess' current card MUST be >3
        if(princessIndex == 3)
        {
            //No card is greater
            for(int i = 1; i < 53; ++i)
            {
                if(usedCards[i] != 1)
                {
                    cout << i << endl;
                    break;
                }
                else if(i == 52)
                {
                    cout << -1 << endl;
                }
            }
        }
        else
        {
            princessFirstCardWin = princessIndex;
            if(princessIndex == 2)
            {
                princessFirstCardWin = 1;
            }
            else if(princessFirstCardWin == 1)
            {
                princessFirstCardWin = 2;
            }
            else
            {
                princessFirstCardWin = 2;
            }
            princessIndex++;
            // Princess greater than 1 card
            princeIndex++;
            // How many princess cards higher than princes
            while(princess[princessIndex] < prince[princeIndex] && princessIndex != 3)
            {
                princessIndex++;
            }

            // Now if we reach here the current card MUST be >3
            if(princessIndex == 3)
            {
                //No card is greater
                for(int i = princess[princessFirstCardWin] + 1; i < 53; ++i)
                {
                    if(usedCards[i] != 1)
                    {
                        cout << i << endl;
                        break;
                    }
                    else if(i == 52)
                    {
                        cout << -1 << endl;
                    }
                }

            }
            else
            {
                cout << -1 << endl;
            }
        }



    }
}
