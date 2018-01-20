#include <cstdio>
#include <iterator>
#include <iostream>
#include <set>
using namespace std;


int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        int fields, green, blue;
        cin >> fields >> green >> blue;
        multiset<int> greenArmy;
        multiset<int> blueArmy;
        for(int i = 0; i < green; ++i)
        {
            int l;
            cin >> l;
            greenArmy.insert(l); 
        }
        for(int i = 0; i < blue; ++i)
        {
            int l;
            cin >> l;
            blueArmy.insert(l);
        }
        while((greenArmy.size() && blueArmy.size()))
        {
            multiset<int> greenArmyTemp;
            multiset<int> blueArmyTemp;
            for(int i = 0; i <fields; ++i)
            {
                if(!greenArmy.size() || !blueArmy.size())
                {
                    break;
                }
                multiset<int>::reverse_iterator itG = greenArmy.rbegin();
                multiset<int>::reverse_iterator itB = blueArmy.rbegin();

                if(*itG > *itB)
                {
                    greenArmyTemp.insert(*itG - *itB);
                }
                else if(*itG < *itB)
                {
                    blueArmyTemp.insert(*itB - *itG);

                }
                {
                    blueArmy.erase( --blueArmy.end());
                    greenArmy.erase(--greenArmy.end());
                }
            }
            greenArmy.insert(greenArmyTemp.begin(), greenArmyTemp.end());
            blueArmy.insert(blueArmyTemp.begin(), blueArmyTemp.end());
        }
        if(greenArmy.size() == 0 && blueArmy.size() == 0)
        {
            cout << "green and blue died" << endl;
        }
        else if(greenArmy.size() != 0)
        {
            cout << "green wins" << endl;
            for(multiset<int>::reverse_iterator it = greenArmy.rbegin(); it != greenArmy.rend(); it++)
            {
                cout << *it << endl;
            }
        }
        else
        {
            cout << "blue wins" << endl;
            for(multiset<int>::reverse_iterator it = blueArmy.rbegin(); it != blueArmy.rend(); it++)
                
            {
                cout << *it << endl;
            }
        }
        if(n) cout << endl;
            
    }









    return 0;
}
