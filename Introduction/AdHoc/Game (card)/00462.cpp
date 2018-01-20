#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


int main(void)
{
    map<char, int> suitsOrder;
    suitsOrder['S'] = 1;
    suitsOrder['H'] = 2;
    suitsOrder['D'] = 3;
    suitsOrder['C'] = 4;


    while(true)
    {
        // Suit, second map is the cards
        map<char, set<char> > cards;
        int points = 0;
        int numCards = 13;
        int bonus = 0;

        char largestSuit;
        unsigned int sizeLargest = 0;

        while(numCards--)
        {
            string str;
            cin >> str;
            if(str.size() != 2)
            {
                return 0;
            }
            // Add the card
            cards[str[1]].insert(str[0]);

            if(str[0] == 'A') points += 4;
            if(str[0] == 'K') points += 3;
            if(str[0] == 'Q') points += 2;
            if(str[0] == 'J') points += 1;
        }

        bool stopped = true;

        if(cards.size() != 4)
        {
            stopped = false;
        }
        // Rule 2;
        for(pair<char, set<char> > pair : cards)
        {
            // For every suit
            set<char> suit = pair.second;

            if(suit.size() > sizeLargest)
            {
                largestSuit = pair.first;
                sizeLargest = suit.size();
            }
            else if(suit.size() == sizeLargest)
            {
                if(suitsOrder[pair.first] < suitsOrder[largestSuit])
                {
                    largestSuit = pair.first;
                }
            }
            //THere exists a king
            if(suit.find('K') !=  suit.end())
            {
                if(suit.size()  <= 1)
                {
                    points--;
                }
            }
            if(suit.find('Q') !=  suit.end())
            {
                if(suit.size() <= 2)
                {
                    points--;
                }
            }
            if(suit.find('J') !=  suit.end())
            {
                if(suit.size() <= 3)
                {
                    points--;
                }
            }
            if(suit.size() == 2)
            {
                bonus++;
            }
            else if (suit.size() <= 1)
            {
                bonus += 2;
            }

            if(!(suit.find('A') != suit.end() || (suit.find('K') != suit.end() && suit.size() > 1) || (suit.find('Q') != suit.end() && suit.size() > 2) || (suit.find('J') != suit.end() && suit.size() > 3)))
            {
                stopped = false;
            }
        }

        // Check if no trump is possible.
        if(points >= 16 && stopped)
        {
            cout << "BID NO-TRUMP" << endl;
            continue;
        }

        if(points + bonus < 14)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "BID " << largestSuit << endl;
        }

    }



}
