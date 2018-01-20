#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int index = 0; index < n; ++index)
    {
        int y = 0;
        vector< string > cards(52);

        for(int i = 0; i < 52; ++i)
        {
            string curCard;
            cin >> curCard;

            // set index 0 to the be the top of the deck
            cards[i] = curCard;
        }

        // Start at the top
        int curIndex = 51;
        int discard = 0;

        //"discard first 25"
        curIndex -= 25;

        for(int i = 0; i < 3; ++i)
        {
            int x = 10;
            if(cards[curIndex][0] <= '9' && cards[curIndex][0] >= '2')
            {
                x = cards[curIndex][0] - '0';
            }
            y += x;
            curIndex -= 10 - x + 1;
            discard += 10 - x + 1;
        }
        printf("Case %d: %s\n", index + 1 , cards[discard + y - 1].c_str());

    }
    return 0;
}
