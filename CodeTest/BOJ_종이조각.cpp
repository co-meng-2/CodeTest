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

// 7 6 5 4 6 5 4 3 5 4 3 2	4 3 2 1
// 840 * 360 * 120 * 24
// BT? 2초면 충분할듯


int r, c;
int board[4][4]{};
int visited[4][4]{};

bool OOB(int y, int x)
{
	return x < 0 || y < 0 || x >= c || y >= r;
}

int mx = 0;
void dfs(int cy, int cx, int sum)
{
	if(cy == r)
	{
		mx = max(mx, sum);
		return;
	}

	int ny = cy;
	int nx = cx + 1;
	if(nx == c)
	{
		nx = 0;
		++ny;
	}
		
	if (visited[cy][cx])
		dfs( ny, nx, sum );
	else
	{
		visited[cy][cx] = true;
		dfs(ny, nx, sum + board[cy][cx]);
		visited[cy][cx] = false;

		int tmpy = cy + 1;
		while(!OOB(tmpy, cx) && !visited[tmpy][cx])
		{
			int tmpsum = sum;
			for(int i = tmpy, idx = 0; i >= cy; --i, ++idx)
			{
				visited[i][cx] = true;
				tmpsum += board[i][cx] * pow(10, idx);
			}
			dfs(ny, nx, tmpsum);
			for (int i = cy; i <= tmpy; ++i)
			{
				visited[i][cx] = false;
			}
			++tmpy;
		}

		int tmpx = cx + 1;
		while (!OOB(cy, tmpx) && !visited[cy][tmpx])
		{
			int tmpsum = sum;
			for (int i = tmpx, idx = 0; i >= cx; --i, ++idx)
			{
				visited[cy][i] = true;
				tmpsum += board[cy][i] * pow(10, idx);
			}
			dfs(ny, nx, tmpsum);
			for (int i = cx; i <= tmpx; ++i)
			{
				visited[cy][i] = false;
			}
			++tmpx;
		}

	}
}

int main()
{
	fastio;
	cin >> r >> c;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}

	dfs(0, 0, 0);
	cout << mx;

	return 0;
}


// S : 2 44
// U : 2 45
// T : 2 49
// C : 3 30
// Total : 46min
