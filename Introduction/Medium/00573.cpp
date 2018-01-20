#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    while(true)
    {
        int height, day, night, fatigue;
        scanf("%d %d %d %d", &height, &day, &night, &fatigue);
        if(height == 0)
        {
            break;
        }

        int dayReached = 0;
        double curSpeed = day;
        double fatigueSlide = (fatigue*day + 0.0) / 100.0;
        double curPosition = 0;
        while(true)
        {
            dayReached++;
            curPosition += curSpeed;
            curSpeed = max(0.0, curSpeed - fatigueSlide);
            if(curPosition > height)
            {
                printf("success on day %d\n",dayReached);
                break;
            }
            curPosition -= night;
            if(curPosition < 0)
            {
                printf("failure on day %d\n",dayReached);
                break;
            }

        }
    }
}
