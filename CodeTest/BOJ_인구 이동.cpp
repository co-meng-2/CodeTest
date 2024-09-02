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
int L, R;

int board[50][50]{};
bool visited[50][50]{};

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

int main()
{
	fastio;
	cin >> n >> L >> R ;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}

	int day = 0;
	while (true)
	{
		memset(visited, 0, sizeof(visited));
		bool moved = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j]) continue;
				visited[i][j] = true;
				queue<pii> Q;
				Q.push({ i,j });
				vector<pii> united{{i, j}};

				int sum = board[i][j];
				while (!Q.empty())
				{
					auto [cy, cx] = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];
						if (OOB(ny, nx) || visited[ny][nx] || L > abs(board[ny][nx] - board[cy][cx]) || R < abs(board[ny][nx] - board[cy][cx])) continue;
						visited[ny][nx] = true;
						sum += board[ny][nx];
						united.push_back({ ny, nx });
						Q.push({ ny,nx });
					}
				}
				if (united.size() >= 2)
					moved = true;
				int num = sum / united.size();
				for (auto [y, x] : united)
					board[y][x] = num;
			}

		if (!moved) break;
		day++;
	}

	cout << day;

	return 0;
}


// S : 2:06
// U : 
// T : 
// C :
// Total : 18min
