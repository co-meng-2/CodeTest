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

// 1. 떨어인 블록들 고유한 숫자로 마킹
// 2. 테두
int n;
int board[51][51]{};
int dist[51][51]{};

bool OOB(int y, int x)
{
	return y < 1 || x < 1 || y > n || x > n;
}


int main()
{
	fastio;

	fill(&dist[0][0], &dist[50][51], INF);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}

	priority_queue<tiii, vector<tiii>, greater<>> PQ;
	dist[1][1] = 0;
	PQ.push({0,1,1 });

	while(!PQ.empty())
	{
		auto [cw, cy, cx] = PQ.top();
		PQ.pop();

		if (dist[cy][cx] != cw) continue;

		for(int dir = 0; dir < 4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if(OOB(ny, nx)) continue;

			int nw = cw;
			if (board[ny][nx] == 0)
				++nw;
			
			if (nw >= dist[ny][nx]) continue;
			dist[ny][nx] = nw;
			PQ.push({ nw, ny, nx });
		}
	}

	cout << dist[n][n];

	return 0;
}


// S : 12 57
// U : 13 00
// T : 13 10
// C : 13 35
// Total : 38min
