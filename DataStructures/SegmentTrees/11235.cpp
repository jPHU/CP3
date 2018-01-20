#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
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
		vi st, A, num;
		vi leftMost, rightMost;
		vi numLeft, numRight;
		int n;
		int left (int p) {return p << 1;} // 2p
		int right (int p) { return (p << 1) + 1;} // 2p +  1

		void build(int p, int L, int R) // O(n)
		{
			numLeft[p] = A[L];
			numRight[p] = A[R];
			if(L == R)
			{
				st[p] = 1;
				num[p] = L;

				leftMost[p] = 1;
				rightMost[p] = 1;
			}
			else
			{
				build(left(p), L, (L+R)/2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				int num1 = numLeft[right(p)], num2 = numRight[left(p)];

				int combineTotal = 0;
				if(num1 == num2)
				{
					combineTotal = rightMost[left(p)] + leftMost[right(p)];
				}
				if(combineTotal > max(p1,p2))
				{
					st[p] = combineTotal;
					num[p] = num1; 


				}
				else
				{
					st[p] = (p1 < p2) ? p2 : p1;
					num[p] = (p1 < p2) ? num2 : num1;
				}



				if(numLeft[left(p)] == numLeft[p])
				{
					leftMost[p] = leftMost[left(p)] + leftMost[right(p)];
				}
				else
				{
					leftMost[p] = leftMost[left(p)]; 
				}
				if(numRight[left(p)] == numRight[p])
				{
					rightMost[p] = rightMost[right(p)] + rightMost[left(p)];
				}
				else

				{
					rightMost[p] = rightMost[right(p)]; 
				}
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

			int num1 = numLeft[right(p)], num2 = numRight[left(p)];
			int combineTotal = 0;
			if(num1 == num2)
			{
				combineTotal = rightMost[left(p)] + leftMost[right(p)];
			}
			if(combineTotal > max(p1,p2))
			{
				return combineTotal;

			}
			else
			{
				return (p1 < p2) ? p2 : p1;
			}



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
			num.assign(4*n,0);
			numLeft.assign(4*n,0);
			numRight.assign(4*n,0);
			leftMost.assign(4*n,0);
			rightMost.assign(4*n,0);
			build(1, 0, n-1);
		}
		int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
};
int main(void)
{


	int n, q;
	while(scanf("%d %d", &n, &q) && n != 0)
	{
		vi inputData;
		int _a;
		while(n--)
		{
			cin >> _a;
			inputData.push_back(_a);
		}
		SegmentTree segmentTree(inputData);
		int l,r;
		while(q--)
		{
			scanf("%d %d", &l, &r);
			cout << segmentTree.rmq(l,r) << endl;
		}

	}







	return 0;
}
