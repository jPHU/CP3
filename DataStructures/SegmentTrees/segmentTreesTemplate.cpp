#include <cstdio>
#include <iostream>
#include <vector>
#include <algorthm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

class SegmentTree
{
private: 
    vi st, A;
    int n;
    int left (int p) {return p << 1;} // 2p
    int right (int p) { return (p << 1) + 1;} // 2p +  1

    void build(int p, int L, int R) // O(n)
    {
        if(L == R)
        {
            st[p] = L;
        }
        else
        {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) // O(logn)
    {
        if(i > R || j < L) return -1; // outside query range
        if(L >= i && R <= j) return st[p]; // inside query range
        
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);

        if (p1 == -1) return p2; // segment outside query for p1
        if (p2 == -1) return p1; 

        return (A[p1] <= A[p2]) ? p1 : p2;

        
    }

    void update(int p, int L, int R, int i, int val)
    {
        if( i < L || i > R) return; // out of the range

        if( L == R)
        {
            A[i] = p; 
            return; // nothing to update
        }
        update(left(p), L, (L+R)/2, i, val);
        update(right(p), (L+R)/2 + 1, R, i, val);
        st[p] = min(A[st[left(p)]], A[st[right(p)]]);
        

    }
public:
    SegmentTree(const vi &_A)
    {
        A = _A; n = (int)A.size();
        st.assign(4*n, 0); // add a buffer
        build(1, 0, n-1);
    }
    int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
    int update(int i, int val)
    {
        
    }

};
int main(void)
{










    return 0;
}
