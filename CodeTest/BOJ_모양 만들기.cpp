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

int n, m;
int board[1000][1000]{};
int visited[1000][1000]{};
int cnts[1000010];

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= m;
}

void bfs(int y, int x, int mark)
{
	queue<pii> Q;
	Q.push({ y, x });
	visited[y][x] = true;
	board[y][x] = mark;
	int cnt = 1;
	while(!Q.empty())
	{
		auto [cy, cx] = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (OOB(ny, nx) || board[ny][nx] != 1) continue;

			visited[ny][nx] = true;
			board[ny][nx] = mark;
			Q.push({ ny, nx });
			++cnt;
		}
	}
	cnts[mark] = cnt;
}



int main()
{
	fastio;

	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}

	int mark = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if(board[i][j] == 1)
			{
				bfs(i, j, ++mark);
			}
		}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if(board[i][j] == 0)
			{
				int sum = 1;
				set<int> selected;
				for(int dir = 0; dir < 4; ++dir)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (OOB(ny, nx)) continue;

					int markNum = board[ny][nx];
					if (selected.count(markNum)) continue;
					selected.insert(markNum);
					sum += cnts[markNum];
				}
				ans = max(ans, sum);
			}
		}

	cout << ans;

	return 0;
}


// S : 426
// U : 429
// T : 431
// C : 444
// Total :18min
