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

int n, q, len;
int board[64][64]{};
bool visited[64][64]{};
int magic[1000];

// 돌리는 함수

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= len || x >= len;
}

void Rotate(int level)
{
	int NewBoard[64][64]{};
	int curlen = pow(2, level);
	int sy = 0; int ey = curlen;
	int sx = 0; int ex = curlen;

	while(true)
	{ 
		for (int i = sy; i < ey; ++i)
		{
			for (int j = sx; j < ex; ++j)
			{
				NewBoard[sy + j - sx][sx + ey - i - 1] = board[i][j];
			}
		}

		sx += curlen;
		ex += curlen;
		if (ex > len)
		{	
			sx = 0;
			ex = curlen;
			sy += curlen;
			ey += curlen;
			if (ey > len)
				break;
		}
	}

	swap(board, NewBoard);

	vector<pii> dec;
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
		{
			if (board[i][j] == 0) continue;
			int sum = 0;
			for(int dir = 0; dir < 4; ++dir)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (OOB(ny, nx) || board[ny][nx] == 0) continue;
				++sum;
			}
			if (sum < 3)
				dec.push_back({ i,j });
		}

	for(auto [y,x] : dec)
	{
		--board[y][x];
	}
}

int main()
{
	fastio;

	cin >> n >> q;
	len = pow(2, n);
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < len; ++j)
		{
			cin >> board[i][j];
		}
	}

	for(int i = 0; i < q;++i)
	{
		cin >> magic[i];
	}

	for(int i = 0; i < q; ++i)
	{
		Rotate(magic[i]);
	}

	int sum = 0;
	int mungtang = 0;
	queue<pii> Q;
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len ;++j)
		{
			if (visited[i][j] || board[i][j] == 0) continue;
			visited[i][j] = true;
			sum += board[i][j];
			int localmungtang = 1;
			Q.push({ i,j });

			while(!Q.empty())
			{
				auto [cy, cx] = Q.front();
				Q.pop();

				for(int dir = 0; dir<4;++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (OOB(ny, nx) || board[ny][nx] == 0 || visited[ny][nx]) continue;

					visited[ny][nx] = true;
					sum += board[ny][nx];
					++localmungtang;
					Q.push({ ny, nx });
				}
			}
			mungtang = max(localmungtang, mungtang);
		}

	cout << sum << "\n" << mungtang;

	return 0;
}


// S : 905
// U : 910
// T : 915
// C : 1017
// Total : 1h 12min
