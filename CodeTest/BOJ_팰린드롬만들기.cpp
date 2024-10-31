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

int n;

int nums[5001];
int dp[5001][5001];
int dfs(int s, int e)
{
	if( s >= e)
	{
		return 0;
	}

	if (dp[s][e] >= 0) return dp[s][e];

	if(nums[s] == nums[e])
	{
		return dp[s][e] = dfs(s + 1, e - 1);
	}
	else
	{
		return dp[s][e] = min(dfs(s + 1, e), dfs(s, e - 1)) + 1;
	}
}

int main()
{
	fastio;

	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int s = 0; int e = n - 1;

	cout << dfs(s, e);

	return 0;
}


// S : 1231 
// U : 1232
// T : 1233
// C : 1257
// Total : 26min
