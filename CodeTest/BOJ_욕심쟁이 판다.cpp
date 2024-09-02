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

int board[500][500]{};
int dp[500][500]{};
int n;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

int dfs(int y, int x)
{
	if (dp[y][x])
		return dp[y][x];

	for(int dir = 0; dir <4 ; ++dir)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (OOB(ny, nx) || board[ny][nx] <= board[y][x]) continue;
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}

	if (dp[y][x] == 0)
		dp[y][x] = 1;
	return dp[y][x];
}

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (dp[i][j]) continue;
			ans = max(dfs(i, j), ans);
		}

	cout << ans;

	return 0;
}


// S : 1:30
// U : 1:31
// T : 1:41 
// C : 1:53
// Total : 23min
