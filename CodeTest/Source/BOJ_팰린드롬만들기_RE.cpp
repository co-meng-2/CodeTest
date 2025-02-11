#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 2구간으로 나누고 겹치는 가장 긴 수열을 구한다?
// 시그마 k(n-k) -> 몇백억 정도..

// dp는 구간에서의 팰린드롬을 위해 추가해야 하는 최소 값

int nums[5000];
int dp[5000][5000];

int dfs(int s, int e)
{
	if(s >= e)
	{
		return 0;
	}

	if(dp[s][e] != 0)
	{
		return dp[s][e];
	}
	
	if(nums[s] == nums[e])
	{
		return dp[s][e] = dfs(s +1, e - 1);
	}
	else
	{
		return dp[s][e] = min( dfs(s+1, e), dfs(s, e - 1)) + 1; 
	}
}


int main()
{
	fastio;

	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	cout << dfs(0, n-1);

	return 0;
}


// S : 5:22
// U : 5:22
// T : 5:52
// C :
// Total :
