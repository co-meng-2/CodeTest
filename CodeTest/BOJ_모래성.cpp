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

int h, w;
int board[1000][1000]{};
int cached[1000][1000]{};
int visited[1000][1000]{};

int main()
{
	fastio;
	cin >> h >> w;
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
		{
			char c;
			cin >> c;
			if (c == '.')
				board[i][j] = INF;
			else
				board[i][j] = c - '0';
		}

	queue<pii> Q;
	for (int i = 1; i < h-1; ++i)
		for (int j = 1; j < w-1; ++j)
		{
			int outer = 0;
			for(int k = -1; k <= 1; ++k)
				for(int l = -1; l <= 1; ++l)
				{
					if (k == 0 && l == 0) continue;
					if (board[i + k][j + l] == INF)
						++outer;
				}

			cached[i][j] = outer;
			if (board[i][j] <= outer)
			{
				visited[i][j] = true;
				Q.push({ i, j });
			}
		}

	int cnt = 0;
	while(!Q.empty())
	{
		int qsz = Q.size();
		++cnt;
		while (qsz--)
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for (int k = -1; k <= 1; ++k)
				for (int l = -1; l <= 1; ++l)
				{
					if (k == 0 && l == 0) continue;
					int ny = cy + k;
					int nx = cx + l;
					++cached[ny][nx];
					if(board[ny][nx] <= cached[ny][nx] && !visited[ny][nx])
					{
						visited[ny][nx] = true;
						Q.push({ ny, nx });
					}
				}
		}
	}

	cout << cnt;

	return 0;
}


// S : 341
// U : 343
// T : 345
// C : 409
// Total : 28min
