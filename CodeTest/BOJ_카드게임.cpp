#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
#include <unordered_set>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int dp[2][1001][1001]{};
int acc[1001]{};
int nums[1001]{};

void dfs(int s, int e, bool turn = true)
{
	if (dp[turn][s][e] != INF) return;
	if (s == e)
	{
		dp[turn][s][e] = nums[s];
		return;
	}

	if (dp[!turn][s + 1][e] == INF) dfs(s + 1, e, !turn);
	if (dp[!turn][s][e-1] == INF) dfs(s, e-1, !turn);

	dp[turn][s][e] = max(acc[e] - acc[s-1] - dp[!turn][s + 1][e], acc[e] - acc[s-1] - dp[!turn][s][e - 1]);
}

int main()
{
	fastio;

	int T;
	cin >> T;
	while(T--)
	{
		memset(dp, INF, sizeof(dp));
		memset(acc, 0, sizeof(acc));

		int n;
		cin >> n;
		
		for (int i = 1; i <= n; ++i)
		{
			cin >> nums[i];
			acc[i] += nums[i] + acc[i - 1];
		}

		dfs(1, n);

		cout << dp[1][1][n] << "\n";
	}

	return 0;
}

// S : 2 17
// U : 2 18
// T : 3 55
// C : 4 17
// Total : 2h