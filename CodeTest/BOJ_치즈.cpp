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
using tiiii = tuple<int, int, int,int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int board[100][100]{};
bool visited[100][100]{};
int r, c;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}

int main()
{
	fastio;

	cin >> r >> c;

	int cnt = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
			if (board[i][j])
				cnt++;
		}


	vector<pii> nxts;
	for (auto [sy, ey, sx, ex] : { tiiii{0,0,0,c - 1}, tiiii{r, r, 0, c-1}, tiiii{0, r-1, 0, 0}, tiiii{0, r-1, c-1, c-1} })
	{
		for(int y = sy; y <= ey; ++y)
			for (int x = sx; x <= ex; ++x)
			{
				if (visited[y][x]) continue;
				visited[y][x] = true;

				queue<pii> Q;
				Q.push({ y,x });

				while (!Q.empty())
				{
					auto [cy, cx] = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];

						if (OOB(ny, nx) || visited[ny][nx]) continue;
						if (board[ny][nx] == 1)
						{
							board[ny][nx] = 2;
							nxts.push_back({ ny,nx });
						}
						else if (board[ny][nx] == 0)
						{
							visited[ny][nx] = true;
							Q.push({ ny, nx });
						}
					}
				}
			}
	}

	int prv = cnt;
	int time = 0;
	while (!nxts.empty())
	{
		queue<pii> Q;
		prv = cnt;
		for (auto [y, x] : nxts)
		{
			board[y][x] = 0;
			Q.push({y,x});
			cnt--;
		}
		nxts.clear();
		time++;

		while (!Q.empty())
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (OOB(ny, nx) || visited[ny][nx]) continue;
				if (board[ny][nx] == 1)
				{
					board[ny][nx] = 2;
					nxts.push_back({ ny,nx });
				}
				else if (board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					Q.push({ ny, nx });
				}
			}
		}
	}

	cout << time << "\n" << prv;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
