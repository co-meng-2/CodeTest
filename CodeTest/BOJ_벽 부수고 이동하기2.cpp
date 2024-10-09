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



// 최단 경로를 저장하는 -> dp 부순 벽 갯수 1000 1000
// 부순 벽 갯수 가 크거나 같고, 최단 경로가 더 크거나 같으면 continue;

int n, m, k;
int board[1000][1000];
int dp[11][1000][1000];
bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= m;
}

int main()
{
	fastio;

	memset(dp, INF, sizeof(dp));

	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <m; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c- '0';
		}

	using tiiii = tuple<int, int, int, int>;
	queue<tiiii> Q;
	Q.push({ 0, 0, 1, 0 });
	dp[0][0][0] = 1;

	while(!Q.empty())
	{
		auto [cy, cx, cd, cw] = Q.front();
		Q.pop();

		for(int dir = 0; dir < 4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			int nw = cw;
			int nd = cd + 1;
			if (OOB(ny, nx)) continue;
			if (board[ny][nx]) ++nw;
			if (nw > k) continue;
			if (dp[nw][ny][nx] <= nd) continue;
			dp[nw][ny][nx] = nd;
			Q.push({ ny, nx, nd, nw });
		}
	}

	int mnDist = INF;
	for(int i = 0; i <= k; ++i)
	{
		mnDist = min(mnDist, dp[i][n - 1][m - 1]);
	}

	if (mnDist == INF)
		cout << -1;
	else
		cout << mnDist;

	return 0;
}


// S : 4 20
// U : 4 21
// T : 4 25
// C : 4 38
// Total : 18min

