#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n;
int board[100][100]{};
bool visited[100][100]{};

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

int main()
{
	fastio;

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	int mark = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j] || board[i][j] == 0) continue;
			mark++;
			queue<pii> Q;
			Q.push({i,j});
			board[i][j] = mark;
			visited[i][j] = true;

			while(!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				for(int dir = 0; dir < 4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];
					if (OOB(ny, nx) || visited[ny][nx] || board[ny][nx] == 0) continue;
					visited[ny][nx] = true;
					board[ny][nx] = mark;
					Q.push({ ny, nx });
				}
			}
		}

	int ans = INF;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <n; ++j)
		{
			int curMark = 0;
			bool check = true;
			if (board[i][j] > 0) continue;
			for(int dir = 0; dir < 4; ++dir)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (!OOB(ny, nx) && board[ny][nx] > 0)
				{
					curMark = board[ny][nx];
					check = true;
					break;
				}
			}

			if (!check) continue;

			queue<pii> Q;
			Q.push({ i,j });
			memset(visited, 0, sizeof(visited));
			int step = 1;
			while (!Q.empty())
			{
				int qsz = Q.size();
				while (!Q.empty() && qsz--)
				{
					auto [cy, cx] = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];
						if (OOB(ny, nx) || visited[ny][nx] || board[ny][nx] == curMark) continue;
						visited[ny][nx] = true;
						if(board[ny][nx])
						{
							ans = min(ans, step);
							Q = {};
							break;
						}
						Q.push({ ny,nx });
					}
				}
				step++;
			}
		}

	cout << ans;

	return 0;
}


// S : 6 44
// U : 6 45
// T : 7 00
// C : 7 01
// Total : 
