#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
    int hour, minute;
    while(scanf("%d:%d", &hour, &minute) && !(hour == 0 && minute == 0))
    {
        double minAngle;
        minAngle = (6)*minute;
        if(hour == 12) hour = 0;
        double hourAngle;
        hourAngle = 30 * hour + (0.5)*minute;

        double result;
        if(minAngle < 180 && hourAngle < 180)
        {
            result = max(minAngle, hourAngle) - min(minAngle, hourAngle);
        }
        else if(minAngle > 180 && hourAngle > 180)
        {
            minAngle = 360 - minAngle;
            hourAngle = 360 - hourAngle;
            result = max(minAngle, hourAngle) - min(minAngle, hourAngle);
        }
        else
        {
            result = max(minAngle, hourAngle) - min(minAngle, hourAngle);
            if(result > 180)
            {
                result = 360 - result;
            }
        }

        printf("%.3f\n", result);


    }



    return 0;
}
