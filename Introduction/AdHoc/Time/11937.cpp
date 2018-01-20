#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthsLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


string zodiac(int day, int month) {
  if (day >= 21 && month == 1 || day <= 19 && month == 2)
    return "aquarius";
  if (day >= 20 && month == 2 || day <= 20 && month == 3)
    return "pisces";
  if (day >= 21 && month == 3 || day <= 20 && month == 4)
    return "aries";
  if (day >= 21 && month == 4 || day <= 21 && month == 5)
    return "taurus";
  if (day >= 22 && month == 5 || day <= 21 && month == 6)
    return "gemini";
  if (day >= 22 && month == 6 || day <= 22 && month == 7)
    return "cancer";
  if (day >= 23 && month == 7 || day <= 21 && month == 8)
    return "leo";
  if (day >= 22 && month == 8 || day <= 23 && month == 9)
    return "virgo";
  if (day >= 24 && month == 9 || day <= 23 && month == 10)
    return "libra";
  if (day >= 24 && month == 10 || day <= 22 && month == 11)
    return "scorpio";
  if (day >= 23 && month == 11 || day <= 22 && month == 12)
    return "sagittarius";
  if (day >= 23 && month == 12 || day <= 20 && month == 1)
    return "capricorn";
}


int main(void)
{


    int numInput;
    cin >> numInput;

    for(int i = 1; i < numInput + 1; ++i)
    {
        int n = 40*7;
        // string input;
        // cin >> input;
        int d, m, y;
        // string temp = input.substr(0, 2);
        // stringstream tempStream1(temp);
        // tempStream1 >> m;
        //
        // temp = input.substr(2, 2);
        // stringstream tempStream2(temp);
        // tempStream2 >> d;
        //
        // temp = input.substr(4, 4);
        // stringstream tempStream3(temp);
        // tempStream3 >> y;

        scanf("%2d%2d%4d", &m, &d, &y);

        while(n > 0)
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

                d += n;
                n = 0;
            }
        }

        printf("%d %02d/%02d/%04d %s\n",i, m, d, y, zodiac(d,m).c_str());
    }
}
