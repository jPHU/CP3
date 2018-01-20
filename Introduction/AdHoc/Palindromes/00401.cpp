#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <stack>

using namespace std;

map<char, char> reverseMap;

bool isPallindrome(string& input)
{
    for(int i = 0, j = input.size() - 1; i <= j; --j, ++i)
    {
        if(input[i] != input[j]) return false;
    }
    return true;
}

bool isMirrored(string& input)
{
    string mirrorString;
    for(int i = input.size() - 1; i  >= 0; i--)
    {
        char c = input[i];
        if(reverseMap.find(c) == reverseMap.end()) return false;
        mirrorString.push_back(reverseMap[c]);
    }

    if(mirrorString != input) return false;

    return true;
}


int main(void)
{
    reverseMap['A'] = 'A';
    reverseMap['E'] = '3';
    reverseMap['H'] = 'H';
    reverseMap['I'] = 'I';
    reverseMap['J'] = 'L';
    reverseMap['L'] = 'J';
    reverseMap['M'] = 'M';
    reverseMap['O'] = 'O';
    reverseMap['S'] = '2';
    reverseMap['T'] = 'T';
    reverseMap['U'] = 'U';
    reverseMap['V'] = 'V';
    reverseMap['W'] = 'W';
    reverseMap['X'] = 'X';
    reverseMap['Y'] = 'Y';
    reverseMap['Z'] = '5';
    reverseMap['1'] = '1';
    reverseMap['2'] = 'S';
    reverseMap['3'] = 'E';
    reverseMap['5'] = 'Z';
    reverseMap['8'] = '8';

    string input;

    while(cin >> input)
    {
        if(isPallindrome(input) && isMirrored(input))
        {
            printf("%s -- is a mirrored palindrome.\n",input.c_str());
        }
        else if(isPallindrome(input))
        {
            printf("%s -- is a regular palindrome.\n",input.c_str());
        }
        else if(isMirrored(input))
        {
            printf("%s -- is a mirrored string.\n",input.c_str());
        }
        else
        {
             printf("%s -- is not a palindrome.\n",input.c_str());
        }
        printf("\n");
    }
    return 0;


}
