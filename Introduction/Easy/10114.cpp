#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
    int duration, records;
    double downPayment, amount;
    while(scanf("%d%lf%lf%d\n",&duration,&downPayment,&amount,&records) && duration > 0)
    {
        int resultMonth = 0;
        int currentMonth = 0;

        double carPrice = amount + downPayment;
        double loanLeft = amount;
        bool ownLess = false;

        double repayment = (amount + 0.0)/(duration + 0.0);

        // For all the records
        int month;
        double depreciation;
        scanf("%d %lf", &month, &depreciation);

        // First depreciation
        double currentDepreciation = depreciation;
        carPrice *= (1.0 - currentDepreciation);


        if(carPrice > loanLeft &&  ownLess == false)
        {
            ownLess = true;
            resultMonth = currentMonth;
        }

       currentMonth++;

        for(int i = 1; i < records; ++i)
        {
            scanf("%d %lf", &month, &depreciation);
            for(; currentMonth < month; ++currentMonth)
            {
                loanLeft -= repayment;

                carPrice *= (1.0 - currentDepreciation);


                if(carPrice > loanLeft &&  ownLess == false)
                {
                    ownLess = true;
                    resultMonth = currentMonth;
                }

            }
            currentDepreciation = depreciation;
        }

        // For the rest of the duration
        for(; currentMonth <= duration; ++currentMonth)
        {

            loanLeft -= repayment;

            carPrice *= (1.0 - depreciation);

            if(carPrice > loanLeft &&  ownLess == false)
            {
                ownLess = true;
                resultMonth = currentMonth;
            }


        }
        string result = (resultMonth == 1) ? "month" : "months";
        printf("%d %s\n",resultMonth,result.c_str());
    }

}
