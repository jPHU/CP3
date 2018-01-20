#include <cstdio>
#include <iostream>
#include <set>
#include <iterator>
using namespace std;


int main(void)
{
    long n;
    while(cin >> n && n != 0)
    {
        multiset<long> raffle;
        long totalPrice = 0;
        while(n--)
        {
            long k;
            cin >> k;
            while(k--)
            {
                long raffleNum;
                cin >> raffleNum;
                raffle.insert(raffleNum); 
            }
            totalPrice += *(--raffle.end()) - *raffle.begin();
            raffle.erase(raffle.begin());
            raffle.erase(--raffle.end());

        }
        cout << totalPrice << endl;
    
    }









    return 0;
}
