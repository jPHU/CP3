#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main(void)
{
    string input;
    while(getline(cin, input), input != "DONE")
    {

        bool palindrome = true;
        string inputText;
        for(char c : input)
        {
            if(c == '!' || c == '.' || c == ',' || c == '?' || c == ' ' || c == '\r')
            {
                continue;
            }


            inputText.push_back(tolower(c));

        }

        for(int i = 0, j = inputText.size() - 1; i <= j; ++i, j--)
        {
            if(inputText[i] != inputText[j]) palindrome = false;
        }

        if(palindrome)
        {
            printf("You won't be eaten!\n");
        }
        else
        {
            printf("Uh oh..\n");
        }

    }

    return 0;
}
