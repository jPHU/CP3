#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector< pair<int,int> > board;
vector< pair<int,int> > pieces;
vector< bool > used;
bool found = false;


void findSolution(int index)
{
    if(found) return;
    if(index == n + 1)
    {
        if(board[n+1].first == board[n].second) found = true;
    }
    else
    {


        for(int i = 0; i < m; ++i)
        {
            if(used[i]) continue;
            if(board[index - 1].second ==  pieces[i].first)
            {
                board[index] = pieces[i];
                used[i] = 1;
                findSolution(index + 1);
                used[i] = 0;
            }
            if(board[index - 1].second == pieces[i].second)
            {
                pair<int, int> p;
                p.first = pieces[i].second;
                p.second = pieces[i].first;
                board[index] = p;
                used[i] = 1;
                findSolution(index + 1);
                used[i] = 0;
            }
        }
    }
}
int main(void)
{
    while(cin >> n >> m && n)
    {
        board.clear();
        pieces.clear();
        used.clear();
        found = false;
        board.resize(n + 2);
        used.resize(m);
        pieces.resize(m);
        pair<int,int> p;
        cin >> p.first >> p.second;
        board[0] = p;
        cin >> p.first >> p.second;
        board[n+1] = p;
        for(int i = 0; i < m; ++i)
        {

            pair<int,int> curPair;
            cin >> curPair.first >> curPair.second;
            pieces[i] = curPair;

        }
        findSolution(1);
        if(found) cout << "YES";
        else cout << "NO";
        cout << endl;

    }

}
