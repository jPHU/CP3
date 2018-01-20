#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <string.h>

using namespace std;

int main(void)
{
    int numReq, numProp;
    int RFP = 0;
    while(true)
    {
        scanf(" %d %d\n", &numReq, &numProp);
        if(numReq == 0 && numProp == 0)
        {
            break;
        }
        RFP++;
        if(RFP != 1)
        {
            printf("\n");
        }

        char tempString[81];

        char name[81];
        double price;
        double compliance = 0;

        for(int i = 0; i < numReq; ++i)
        {
            fgets(tempString, 999, stdin);
        }

        for(int i = 0; i < numProp; ++i)
        {
            char curName[81];
            double curPrice;
            int reqHas;
            fgets(curName, 999, stdin);

            // cin >> curPrice >> reqHas;
            scanf("%lf %d\n", &curPrice, &reqHas);
            // cout << curPrice << " "<< reqHas << endl;

            double curCompliance = (reqHas + 0.0)/(numReq);

            for(int j = 0; j < reqHas; ++j)
            {
                fgets(tempString, 999, stdin);
            }

            if(curCompliance > compliance)
            {
                strcpy(name, curName);
                price = curPrice;
                compliance = curCompliance;
            }
            else if(curCompliance == compliance)
            {
                if(curPrice < price)
                {
                    strcpy(name, curName);
                    price = curPrice;
                    compliance = curCompliance;
                }
            }
        }
        printf("RFP #%d\n", RFP);
        printf("%s",name);
    }




}
