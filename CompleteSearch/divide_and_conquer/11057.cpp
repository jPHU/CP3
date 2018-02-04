#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int n;

    bool first = true;
    while(cin >> n)
    {
        
        vector<long> books(n, 0);
        for(int i = 0; i < n; ++i)
        {
            long a;
            cin >> a;
            books[i] = a; 
        }

        sort(books.begin(), books.end());
        long minDist  = 1000002;
        long M;
        cin >> M;
        long book1, book2;
        long ans1, ans2;
        for(int i = 0; i < n; ++i)
        {
            vector<long>::iterator it = lower_bound(books.begin(), books.end(), M - books[i]);
            if(*it != M - books[i]) continue;
            if(it != books.end())
            {
                book1 = books[i];
                book2 = *it;

                if( abs(book1 - book2)  < minDist)
                {
                    
                    minDist = abs(book1 - book2);
                    if(book1 > book2)
                    {
                        ans1 = book2;
                        ans2 = book1;
                    }
                    else
                    {
                        ans1 = book1;
                        ans2 = book2;
                    }
                }

            }
        }
        printf("Peter should buy books whose prices are %ld and %ld.\n\n",ans1, ans2);
    }
}
