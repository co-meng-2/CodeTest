#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;



const int INF = 0x3f3f3f3f;

// 서북동남
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int bits[4] = { 1,2,4,8 };

int board[50][50];
int nboard[50][50];
int r, c;
int mark = -1;

struct tInfo
{
	int space;
	vector<pii> adj;
};

bool OOB(int y, int x)
{
	return x < 0 || y < 0 || x >= c || y >= r;
}

int main()
{
	fastio;
	memset(nboard, -1, sizeof(nboard));
	cin >> c >> r;

	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
		}
	}

	vector<tInfo> roomspaces;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (nboard[i][j] >= 0) continue;
			++mark;
			nboard[i][j] = mark;
			tInfo info;
			info.space = 1;

			queue<pii> Q;
			Q.push({ i, j });

			while(!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				for(int dir = 0; dir < 4; ++dir)
				{
					if (board[cy][cx] & bits[dir])
					{
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];
						if (OOB(ny, nx)) continue;
						info.adj.push_back({ ny, nx });
						continue;
					}
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];
					if (nboard[ny][nx] >= 0) continue;
					Q.push({ ny, nx });
					nboard[ny][nx] = mark;
					++info.space;
				}
			}
			roomspaces.push_back(info);
		}
	}

	int maxadd = 0;
	int mx = 0;
	for(int i = 0; i < roomspaces.size(); ++i)
	{
		auto& [space, adj] = roomspaces[i];
		mx = max(mx, space);
		for(auto [y, x] : adj)
		{
			int idx = nboard[y][x];
			if (i == idx) continue;
			maxadd = max(maxadd, roomspaces[idx].space + space);
		}
	}

	cout << roomspaces.size() << "\n" << mx << "\n" << maxadd;

	return 0;
}


// S : 406
// U : 406
// T : 410
// C : 433
// Total : 27min
