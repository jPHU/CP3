#include <iostream>
#include <cstdio>
#include <string>
#include <locale>
#include <limits>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    int caseNum = 1;
    string rawInput;
    getline(cin, rawInput);
    while(n--)
    {
        getline(cin, rawInput);

        printf("Case #%d:\n", caseNum);
        caseNum++;
        string textInput;

        for(char c : rawInput)
        {
            if(c == '?' || c == ' ' || c == '.' || c == ',' || c == '!' || c == '(' || c == ')' || c == '\r') continue;

            textInput.push_back(tolower(c));
        }

        bool magic = true;
        int k;
        if(fabs(sqrt(textInput.size() + 0.0) - (int)sqrt(textInput.size())) < numeric_limits<double>::epsilon())
        {
            k = sqrt(textInput.size());
        }
        else
        {
            printf("No magic :(\n");
            continue;
        }


        char mat[k][k];

        int counter = 0;
        for(int i = 0; i < k; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                mat[i][j] = textInput[counter];
                counter++;
            }
        }

        counter = 0;
        for(int i = 0; i < k; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                if(mat[j][i] != textInput[counter]) magic = false;
                counter++;
            }
        }

        counter = 0;
        for(int i = k - 1; i >= 0; --i)
        {
            for(int j = k - 1; j >= 0; --j)
            {
                if(mat[i][j] != textInput[counter]) magic = false;
                if(mat[j][i] != textInput[counter]) magic = false;
                counter++;
            }
        }
        if(magic)
        {
            printf("%d\n", k);
        }
        else
        {
            printf("No magic :(\n");
        }
    }
}
