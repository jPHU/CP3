#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, n;
int countOccruances(vector<vector<char> > &input, vector<vector<char> >& square)
{
    int count = 0;
    for(int i = 0; i < N - n + 1; ++i)
    {

        for(int j = 0; j < N - n + 1; ++j)
        {
            bool correct = true;

            for(int q = 0; q < n; ++q)
            {
            
                for(int p = 0; p < n; ++p)
                {
                
                    if(input[i+q][j+p] != square[q][p]) correct = false;
                
                }
            
            
            }
            if(correct) count++;

        }

    }
    return count;

}


int main(void)
{
    while(scanf("%d %d", &N, &n) && N != 0 && n != 0)
    {

        vector<vector<char> > input(N, vector<char>(N, 0));;
        vector<vector<char> > square(n, vector<char>(n, 0));;
        for(int i = 0; i < N; ++i)
        { 
            for(int j = 0; j < N; ++j)
            {

                char c;
                scanf(" %c", &c);
                input[i][j] = c;

            }


        }
        for(int i = 0; i < n; ++i)
        { 
            for(int j = 0; j < n; ++j)
            {

                char c;
                scanf(" %c", &c);
                square[i][j] = c;

            }


        }

        vector< vector<char> > rotated;
        rotated.assign(square.begin(), square.end());
        printf("%d ",countOccruances(input, square)); 

        // Rotation
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                rotated[i][j] = square[n - 1 - j][i]; 
            
            
            }
        
        
        }

        square.assign(rotated.begin(), rotated.end()); 
        printf("%d ",countOccruances(input, square)); 


        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                rotated[i][j] = square[n - 1 - j][i]; 
            
            
            }
        
        
        }

        square.assign(rotated.begin(), rotated.end()); 
        printf("%d ",countOccruances(input, square)); 

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                rotated[i][j] = square[n - 1 - j][i]; 
            
            
            }
        
        
        }

        square.assign(rotated.begin(), rotated.end()); 
        printf("%d\n",countOccruances(input, square)); 


    }








    return 0;
}
