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


int r, c;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}

int board[1000][1000]{};
int main()
{
	fastio;
	memset(board, INF, sizeof(board));

	cin >> r >> c;

	pii s;
	queue<pii> Q;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			char  c;
			cin >> c;
			if (c == '#')
				board[i][j] = 0;
			else if (c == 'J')
				s = { i,j };
			else if (c == 'F')
			{
				Q.push({ i,j });
				board[i][j] = 0;
			}
		}


	int step = 1;
	while (!Q.empty())
	{
		int qsz = Q.size();
		while (qsz--)
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (OOB(ny, nx) || board[ny][nx] != INF) continue;
				board[ny][nx] = step;
				Q.push({ ny,nx });
			}
		}
		step++;
	}

	step = 1;
	Q.push(s);

	while (!Q.empty())
	{
		int qsz = Q.size();
		while (qsz--)
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (OOB(ny, nx))
				{
					cout << step;
					return 0;
				}

				if (board[ny][nx] <= step) continue;
				board[ny][nx] = 0;
				Q.push({ ny,nx });
			}
		}
		step++;
	}

	cout << "IMPOSSIBLE";
	return 0;
}


// S : 12:44
// U : 12:46
// T : 12:50
// C : 1:18
// Total : 34min
