#include <cstdio>
#include <iostream>

using namespace std;

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthsLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int n, d, m, y;

    while(scanf("%d %d %d %d", &n, &d, &m, &y) && !(n == 0 && d == 0 && m == 0 && y == 0))
    {

        // Reset the status to d = 1, m = 1, y = xxx
        while(!(d == 1 && m == 1))
        {
            int* monthArray = isLeap(y) ? monthsLeap : months;
            if(n > monthArray[m - 1] - d)
            {
                n -= monthArray[m - 1] - d + 1;
                d = 1;
                m++;
                if(m == 13)
                {
                    y++;
                    m = 1;
                }
            }
            else
            {
                break;
            }
        }
        while(n > 0)
        {
            int* monthArray = isLeap(y) ? monthsLeap : months;
            if(n >= 366 || (n >= 365 && !isLeap(y)) )
            {
                if(isLeap(y))
                {
                    n -= 366;
                }
                else
                {
                    n -= 365;
                }
                y++;
            }
            else if(n > monthArray[m - 1] - d)
            {
                n -= monthArray[m - 1] - d + 1;
                d = 1;
                m++;
                if(m == 13)
                {
                    y++;
                    m = 1;
                }
            }
            else
            {

                d += n;
                n = 0;
            }


        }
        printf("%d %d %d\n", d, m, y);



    }


    return 0;
}
