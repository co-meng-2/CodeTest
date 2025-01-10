#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { 1,0, -1,0};
int dy[4] = { 0,1,0,-1 };

const int INF = 0x3f3f3f3f;

// 상하좌우

int n,m, k;
int board[20][20];
bool visited[20][20];

enum direction { ERight, EDown, ELeft, EUp };

struct tDice
{
	int Top =1;
	int Bottom = 6;
	int Left = 4;
	int Right = 3;
	int Up = 2;
	int Down = 5;

	void Roll(direction dir)
	{
		switch (dir)
		{
		case EUp:
			{
				int Tmp = Bottom;
				Bottom = Up;
				Up = Top;
				Top = Down;
				Down = Tmp;
				break;
			}
		case EDown:
			{
				int Tmp = Bottom;
				Bottom = Down;
				Down = Top;
				Top = Up;
				Up = Tmp;
				break;
			}
		case ELeft:
			{
				int Tmp = Bottom;
				Bottom = Left;
				Left = Top;
				Top = Right;
				Right = Tmp;
				break;
			}
		case ERight:
			{
				int Tmp = Bottom;
				Bottom = Right;
				Right = Top;
				Top = Left;
				Left = Tmp;
				break;
			}
		}
	}
};

bool OOB(int y, int x)
{
	return y <0 || x < 0 || y >=n || x >= m;
};


int main()
{
	fastio;

	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	tDice dice;
	int ans = 0;
	pii cur = {0,0};
	int dir = ERight;
	while(k--)
	{
		// Roll
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if(OOB(ny, nx))
			{
				dir += 2;
				dir %= 4;
				ny += 2 * dy[dir];
				nx += 2 * dx[dir];
			}

			cur = {ny, nx};
			
			dice.Roll(direction(dir));	
		}
		
		

		// Calc
		queue<pii> q;
		memset(visited, false, sizeof(visited));
		int cnt = 1;
		q.push(cur);
		visited[cur.first][cur.second] = true;
		int val = board[cur.first][cur.second];
		while(!q.empty())
		{
			auto [cy, cx] = q.front();
			q.pop();

			for(int i = 0; i < 4; ++i)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				
				if(OOB(ny, nx) || visited[ny][nx] || val != board[ny][nx])
				{
					continue;
				}

				q.push({ny, nx});
				visited[ny][nx] = true;
				++cnt;
			}
		}
		ans += cnt * board[cur.first][cur.second];

		// Dir
		if(dice.Bottom > board[cur.first][cur.second])
		{
			dir += 1;
			dir %= 4;
		}
		else if(dice.Bottom < board[cur.first][cur.second])
		{
			dir -= 1;
			if(dir < 0)
				dir += 4;
		}
	}

	cout << ans;


	return 0;
}


// S : 9 30
// U : 9 32
// T : 9 34
// C : 10 38
// Total : 1h 8min
