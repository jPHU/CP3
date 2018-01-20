#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int main(void)
{
    int c;
    scanf("%d", &c);
    while(c--)
    {
        vector<long> vecLeft;
        vector<long> vecRight;
        vector<string> leftyRighty;
        vector<long> leftTime;
        vector<long> rightTime;
        long n, t, m;
        scanf("%ld %ld %ld", &n, &t, &m);
        long mm = m;
        for(int i = 0; i < m; ++i)
        {
            long arrival;
            string dir;
            cin >>  arrival >> dir;
            if(dir == "left")
            {
                vecLeft.push_back(arrival);
            }
            else
            {
                vecRight.push_back(arrival);
            }
            leftyRighty.push_back(dir);
        }
        bool leftBank = true;
        long curTime = 0;
        while(m > 0)
        {
            long temp= m ;
            if(leftBank)
            {
                long numberLoaded = 0;
                while(numberLoaded < n && !vecLeft.empty())
                {
                    if(*vecLeft.begin() > curTime) break; // Cant add bois anyway
                    numberLoaded++;
                    vecLeft.erase(vecLeft.begin());
                }
                if(numberLoaded)
                {

                    curTime += t;
                    m -= numberLoaded;
                    leftBank = false;
                    for(int i = 0; i < numberLoaded; ++i)
                    {
                        leftTime.push_back(curTime);
                    }
                }
            }
            else
            {
                long numberLoaded = 0;
                while(numberLoaded < n && !vecRight.empty())
                {
                    if(*vecRight.begin() > curTime) break; // Cant add bois anyway
                    numberLoaded++;
                    vecRight.erase(vecRight.begin());
                }
                if(numberLoaded != 0)
                {

                    curTime += t;
                    m -= numberLoaded;
                    leftBank = true;
                    for(int i = 0; i < numberLoaded; ++i)
                    {
                        rightTime.push_back(curTime);
                    }
                }
            }
            if(temp == m)
            {
                if(!vecLeft.empty() && !vecRight.empty())
                {
                    if(*vecLeft.begin() > *vecRight.begin())
                    {
                        if(leftBank)
                        {
                            curTime =max(*vecRight.begin()+ t, curTime + t);
                            leftBank = !leftBank;
                        }
                        else
                        {
                            curTime = max(*vecRight.begin(), curTime);
                        }
                    }
                    else
                    {
                        if(leftBank)
                        {
                            curTime = max(*vecLeft.begin(), curTime);
                        }
                        else
                        {
                            curTime =max(*vecLeft.begin()+ t, curTime + t);
                            leftBank = !leftBank;

                        }
                    }
                }
                else if(!vecLeft.empty())
                {
                    if(leftBank)
                    {
                        curTime = max(*vecLeft.begin(), curTime);
                    }
                    else
                    {
                        curTime =max(*vecLeft.begin()+ t, curTime + t);
                        leftBank = !leftBank;
                    }
                }
                else
                {
                    if(leftBank)
                    {
                        curTime = max(*vecRight.begin() + t, curTime + t);
                        leftBank = !leftBank;
                    }
                    else
                    {
                        curTime = max(curTime,*vecRight.begin());
                    }


                }
            }
        }
        {
            vector<long>::iterator itLeft = leftTime.begin();
            vector<long>::iterator itRight = rightTime.begin();
            for(string s : leftyRighty)
            {
                if(s == "left")
                {
                
                    cout << *itLeft << endl;
                    itLeft++;
                }
                else
                {
                    cout << *itRight << endl;
                    itRight++;
                }
            }
        }
        if(c) cout << endl;
    }









    return 0;
}
