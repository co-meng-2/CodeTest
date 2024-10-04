#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiiii = tuple<int, int, int,int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n;
char board[50][50]{};
int dp[4][50][50]{};

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

// 3방향으로 진행 가능.
// 각 위치에서의 방향을 포함한 최소 거울을 사용한 dp 만듦

int main()
{
	fastio;
	memset(dp, 0x3f, sizeof(dp));

	cin >> n;
	vector<pii> gate;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == '#')
			{
				gate.push_back({ i,j });
			}
		}

	queue<tiiii> Q;
	Q.push({ 0,  0, gate[0].first, gate[0].second });
	Q.push({ 1,  0, gate[0].first, gate[0].second });
	Q.push({ 2,  0, gate[0].first, gate[0].second });
	Q.push({ 3,  0, gate[0].first, gate[0].second });
	while(!Q.empty())
	{
		auto [cd, cw, cy, cx] = Q.front();
		Q.pop();

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		if (!(OOB(ny, nx) || board[ny][nx] == '*' || dp[cd][ny][nx] <= cw)) // 여기서 continue를 쓰면 안됨
		{
			dp[cd][ny][nx] = cw;
			Q.push({ cd, cw, ny, nx });
		}

		if (board[cy][cx] == '!')
		{
			if(cd <= 1) // to x
			{
				for(int dir = 2; dir<=3;++dir)
				{
					ny = cy + dy[dir];
					nx = cx + dx[dir];
					if (OOB(ny, nx) || board[ny][nx] == '*' || dp[dir][ny][nx] <= cw) continue;
					dp[dir][ny][nx] = cw + 1;
					Q.push({ dir, cw + 1, ny, nx });
				}
			}
			else
			{
				for (int dir = 0; dir <= 1; ++dir)
				{
					ny = cy + dy[dir];
					nx = cx + dx[dir];
					if (OOB(ny, nx) || board[ny][nx] == '*' || dp[dir][ny][nx] <= cw) continue;
					dp[dir][ny][nx] = cw + 1;
					Q.push({ dir, cw + 1, ny, nx });
				}
			}
		}
	}

	int ans = INF;
	for(int i = 0; i < 4; ++i)
	{
		ans = min(ans, dp[i][gate[1].first][gate[1].second]);
	}

	cout << ans;

	return 0;
}


// S : 625
// U : 626
// T : 630
// C : 703
// Total : 38min with alba
