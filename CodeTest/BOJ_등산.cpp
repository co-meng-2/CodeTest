
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

// 625개의 노드가 있다고 생각하면 플로이드는 안된다. -> 상하좌우 제한이 있었네.. ㅎㅎ
// 다익스트라로 0,0 에서의 다른 지점까지 가는 최소 시간, 다른 지점에서 0,0 까지의 최소 시간을 구한다.
// 그 합이 D를 넘지 않는 부분 중 가장 높은 곳을 구한다.

int board[25][25]{};
int table1[25][25]{};
int table2[25][25]{};
int r, c, t, d;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}

int main()
{
	fastio;

	
	cin >> r >> c >> t >> d;

	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			char c;
			cin >> c;
			if(isupper(c))
				board[i][j] = c - 'A';
			else
				board[i][j] = 26 + c - 'a';
		}

	memset(table1, INF, sizeof(table1));
	memset(table2, INF, sizeof(table2));



	priority_queue<tiii, vector<tiii>, greater<>> PQ;
	PQ.push({ 0,0,0 });
	table1[0][0] = 0;

	while(!PQ.empty())
	{
		auto [ctime, cy, cx] = PQ.top();
		PQ.pop();

		if (table1[cy][cx] != ctime) continue;


		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (OOB(ny, nx) || abs(board[ny][nx] - board[cy][cx]) > t) continue;

			int ntime = ctime;
			if (board[ny][nx] > board[cy][cx])
				ntime += (board[ny][nx] - board[cy][cx]) * (board[ny][nx] - board[cy][cx]);
			else
				ntime++;

			if (ntime < table1[ny][nx])
			{
				table1[ny][nx] = ntime;
				PQ.push({ ntime, ny, nx });
			}
		}
	}

	PQ.push({0, 0, 0});
	table2[0][0] = 0;
	while (!PQ.empty())
	{
		auto [ctime, cy, cx] = PQ.top();
		PQ.pop();

		if (table2[cy][cx] != ctime) continue;

		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (OOB(ny, nx) || abs(board[ny][nx] - board[cy][cx]) > t) continue;

			int ntime = ctime;
			if (board[ny][nx] < board[cy][cx])
				ntime += (board[ny][nx] - board[cy][cx]) * (board[ny][nx] - board[cy][cx]);
			else
				ntime++;

			if (ntime < table2[ny][nx])
			{
				table2[ny][nx] = ntime;
				PQ.push({ ntime, ny, nx });
			}
		}
	}

	int ans = -1;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j <c; ++j)
		{
			if(table1[i][j] + table2[i][j] <= d)
			{
				ans = max(ans, board[i][j]);
			}
		}

	cout << ans;
	

	return 0;
}

// S : 9 40
// U : 9 41
// T : 9 43
// C : 10 14
// Total :