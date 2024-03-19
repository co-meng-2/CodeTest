#include <functional>
#include <iostream>
#include <queue>
#include <set>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>

#include <algorithm>
using namespace  std;

// dp?
// 합은 같다 -> sum / 3으로 만들 수 있는가?
// 20 20 20
// 2A B-A C
// 10 30 20
//
// 20 15 25
// 20 30 10
// 20 20 20

// set multiset 구분
// 역연산

struct tInfo
{
	int a, b, c;
};

void dfs(int a, int b, int c, set<multiset<int>>& Set);

void check(int i, int j, int k, set<multiset<int>>& Set)
{
	int big, small;

	big = i; small = j;

	if (small % 2) return;
	small /= 2;
	big += small;

	if( Set.find(multiset<int>{big, small , k}) == Set.end())
	{
		Set.insert(multiset<int>{big, small, k});
		dfs(big, small, k, Set);
	}

	big = j; small = i;

	if (small % 2) return;
	small /= 2;
	big += small;

	if (Set.find(multiset<int>{big, small, k}) == Set.end())
	{
		Set.insert(multiset<int>{big, small, k});
		dfs(big, small, k, Set);
	}
}

void dfs(int a, int b, int c, set<multiset<int>>& Set)
{
	check(a, b, c, Set);
	check(b, c, a, Set);
	check(a, c, b, Set);
}

void check2(int a, int b, int c, set<multiset<int>>& Set, queue<tuple<int, int, int>>& Q, int val)
{
	int big, small;
	big = a > b ? a : b;
	small = a <= b ? a : b;

	big -= small;
	small *= 2;

	if (Set.find({ big, small, c }) == Set.end())
	{
		Set.insert({ big, small, c });
		Q.push({ big, small, c });
	}
}

int main()
{
	fastio;

	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 3)
	{
		cout << 0;
		return 0;
	}
	int val = (a + b + c) / 3;

	set<multiset<int>> Set;
	// Set.insert(multiset<int>{ val, val, val });
	// dfs(val, val, val, Set);
	//if (Set.find(multiset<int>{a, b, c}) != Set.end())
	//	cout << 1;
	//else
	//	cout << 0;

	bool ans = false;
	queue<tuple<int, int, int>> Q;
	Q.push({a,b,c});
	while(!Q.empty())
	{
		auto [ca, cb, cc] = Q.front();
		Q.pop();

		if( ca == cb && cb == cc)
		{
			ans = true;
			break;
		}

		check2(ca, cb, cc, Set, Q, val);
		check2(cb, cc, ca, Set, Q, val);
		check2(cc, ca, cb, Set, Q, val);
	}

	if (ans)
		cout << 1;
	else
		cout << 0;


	return 0;
}


// S : 10:21
// U : 10:21
// T : 10:36
// C : 11:41
// Total : 1h20min