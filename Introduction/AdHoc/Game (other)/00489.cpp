#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int roundNum = 0;
    while(1)
    {
        scanf("%d", &roundNum);
        if(roundNum == -1) break;
        string input;
        printf("Round %d\n",  roundNum);
        // Get rid of the new line in buffer from scanf
        getline(cin, input);

        map<char, int> word;
        getline(cin, input);
        istringstream wordInput(input);
        char c;

        // read in all the words
        while(wordInput >> c)
        {
            if(c == '\n') break;
            word[c] = 1;
        }

        int target = word.size();

        getline(cin, input);
        istringstream contestantInput(input);

        int mistakes = 0;


        while(1)
        {
            if(!(contestantInput >> c))
            {
                cout << "You chickened out." << endl;
                break;
            }

            map<char, int>::iterator it = word.find(c);
            if(it == word.end())
            {
                mistakes++;
                word[c] = 0;
            }
            else
            {
                if(it->second != 0)
                {
                    it->second = 0;
                    target--;
                }
            }




            if(mistakes >= 7)
            {
                cout << "You lose." << endl;
                break;
            }
            else if(target == 0)
            {
                cout << "You win." << endl;
                break;
            }
        }





    }




    return 0;
}
