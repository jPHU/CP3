#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && !(m == 0 && n == 0))
    {
    
        vector<bool> tasks(1000000);
        bool conflict = false; 
        for(int i = 0; i < n; ++i)
        {
            int p,q;
            scanf("%d %d", &p, &q);
            for(int j = p; j < q; ++j)
            {
                if(tasks[j])
                {
                    conflict = true; 
                    break;      
                }
                else
                {
                    tasks[j] = 1;
                }
            
            
            }
            if(conflict) break; 
        
        }
        for(int i = 0; i < m; ++i)
        {
            int p,q,r;
            scanf("%d %d %d", &p, &q, &r);
            do
            {
                for(int j = p; j <min(q, 1000000); ++j)
                {
                    if(tasks[j])
                    {
                        conflict = true; 
                        break;      
                    }
                    else
                    {
                        tasks[j] = 1;
                    }
            
            
                }
                if(conflict) break; 
         
                p += r;
                q += r;
            
            
            }while(p < 1000000);
        
        
        }
        if(conflict)
        {
        
        
            cout << "CONFLICT" << endl;
        }
        else
        {
            cout << "NO CONFLICT" << endl;
        }

    
    
    
    
    }

    








    return 0;
}
