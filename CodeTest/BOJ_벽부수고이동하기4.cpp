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


int n, m;
int board[1001][1001]{};
int cnts[1000005]{};

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= m;
}

int main()
{
	fastio;

	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}

	int mark = 2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j]) continue;
			queue<pii> Q;
			Q.push({ i,j });
			int cnt = 1;
			board[i][j] = mark;

			while(!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				for(int dir = 0; dir<4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (OOB(ny, nx) || board[ny][nx]) continue;
					Q.push({ ny,nx });
					++cnt;
					board[ny][nx] = mark;
				}
			}

			cnts[mark] = cnt;
			++mark;
		}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1)
			{
				set<int> s;
				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (OOB(ny, nx) || board[ny][nx] == 1) continue;
					s.insert(board[ny][nx]);
				}

				int sum = 0;
				for (auto it = s.begin(); it != s.end(); ++it)
				{
					sum += cnts[*it];
				}
				cout << (sum + 1) % 10;
			}
			else
			{
				cout << 0;
			}
		}
		cout << "\n";
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
