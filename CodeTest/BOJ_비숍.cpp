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
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

int dy[2] = {1,-1};
int dx[2] = { 1, -1 };

int n;
bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}
int mx = -1;
void dfs(int cy, int cx, int cnt, vector<vector<int>>& board)
{
	if (cy == n)
	{
		mx = max(cnt, mx);
		return;
	}

	int nx = cx + 2;
	int ny = cy;
	if (nx >= n)
	{
		nx = (nx + 1) % 2;
		ny++;
	}

	if (board[cy][cx] == 0) 
		dfs(ny, nx, cnt, board);
	else
	{
		vector<pii> changes;
		board[cy][cx] = 0;
		changes.push_back({ cy, cx });
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
			{
				int tmpx = cx;
				int tmpy = cy;
				while(!OOB(tmpy + dy[i], tmpx + dx[j]))
				{
					tmpy += dy[i];
					tmpx += dx[j];
					if (board[tmpy][tmpx] == 1)
					{
						changes.push_back({ tmpy, tmpx });
						board[tmpy][tmpx] = 0;
					}
				}
			}
		// 검증을 (비숍위치 - 비숍위치) / 백터 크기 = 4방향 중에 하나로 했어도 좋았을듯?

		dfs(ny, nx, cnt + 1, board);
		for(auto [chy, chx] : changes)
			board[chy][chx] = 1;

		dfs(ny, nx, cnt, board);
	}
}

int main()
{
	fastio;

	cin >> n;
	vector<vector<int>> board(n, vector(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	int ans = 0;
	dfs(0, 0, 0, board);
	ans += mx;
	mx = -1;
	dfs(0, 1, 0, board);
	ans += mx;

	cout << ans;

	return 0;
}


// S : 923
// U : 
// T : 
// C :
// Total :