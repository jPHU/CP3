#include <functional>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class contestant
{
    public:
        int index;
        int totalPenalty;
        int correct;
        vector<int> penalty;
        vector<int> vec_cor;
        contestant() : index(0), totalPenalty(0),  correct(0), penalty(10,0),vec_cor(10,0){}

};
struct contestantGreater
{

    bool operator() (const contestant& lin,const contestant& in) const
    {
        if(lin.correct >  in.correct)
        {
            return true; 

        }
        else if(lin.correct < in.correct)
        {
            return false;
        }
        else
        {
            if(lin.totalPenalty < in.totalPenalty)
            {
                return true;
            }
            else if(lin.totalPenalty > in.totalPenalty)
            {
                return false;
            }
            else
            {
                return lin.index < in.index; 
            
            }

        }


    }
};
int main(void)
{

    int n;
    cin >> n;
    string input;
    getline(cin, input);
    getline(cin, input); // new line
    while(n--)
    {
        vector<contestant> people(101);
        while(getline(cin, input) && input != "")
        {
            stringstream ss(input);
            int index;
            int curProblem;
            int tim;
            char result;
            ss >> index;
            ss >> curProblem;
            ss >> tim;
            ss >> result;


            people[index].index =index;
            if(result == 'R' || result == 'U' || result == 'E') continue;
            if(people[index].vec_cor[curProblem]) continue; //already correct!
            if(result == 'I')
            {

                people[index].penalty[curProblem] += 20; 



            }
            else
            {
                people[index].vec_cor[curProblem] = 1;
                people[index].correct++;
                people[index].totalPenalty += people[index].penalty[curProblem];
                people[index].totalPenalty += tim; 
            }
            // Sort time



        }
        sort(people.begin(), people.end(), contestantGreater()); 
        for(contestant c : people)
        {


            if(c.index == 0) continue;

            printf("%d %d %d\n", c.index, c.correct, c.totalPenalty);
        }

       if(n) printf("\n");




    }








    return 0;
}
