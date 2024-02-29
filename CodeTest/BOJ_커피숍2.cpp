#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

using ll = long long;

class SegementTree
{
public:
	vector<ll> tree;
	int initSize;

	ll build(vector<ll>& vecInit, int idx, int left, int right)
	{
		if (left == right)
			return tree[idx] = vecInit[left];

		int mid = (left + right) / 2;

		ll left_sum = build(vecInit, idx * 2, left, mid);
		ll right_sum = build(vecInit, idx * 2 + 1, mid + 1, right);
		return tree[idx] = left_sum + right_sum;
	}

	int findtarget(int idx)
	{
		int left = 0;
		int right = initSize - 1;
		int target = 1;
		while (left != right)
		{
			int mid = (left + right) / 2;
			if ( idx <= mid)
			{
				right = mid;
				target *= 2;
			}
			else
			{
				left = mid + 1;
				target = target * 2 + 1;
			}
		}
		return target;
	}

	void update(int idx, int num)
	{
		idx -= 1;
		
		int target = findtarget(idx);
		long long diff = num - tree[target] ;
		tree[target] = num;
		
		target /= 2;
		while (target)
		{
			tree[target] += diff;
			target /= 2;
		}
	}
	
	ll sum(int s, int e)
	{
		s -= 1;
		e -= 1;
		return sum(1, 0, initSize - 1, s, e);
	}

	ll sum(int node, int s, int e, int left, int right)
	{
		if (s > right || e < left)
			return 0;

		if (left <= s && right >= e)
			return tree[node];

		int mid = (s + e) / 2;
		long long left_sum = sum(node * 2, s, mid, left, right);
		long long right_sum = sum(node * 2 + 1, mid+1, e, left, right);
		return left_sum + right_sum;
	}

	SegementTree(vector<ll>& vecInit)
	{
		initSize = vecInit.size();
		tree.resize(initSize * 4);
		build(vecInit, 1, 0, vecInit.size()-1);
	}
};

int main()
{
	fastio;

	int N, Q;
	cin >> N >> Q;
	vector<ll> vecNums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNums[i];
	}

	SegementTree ST(vecNums);
	for (int i = 0; i < Q; ++i)
	{
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		if (x > y) std::swap(x, y);
		cout << ST.sum(x, y) << "\n";
		ST.update(z, w);
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :