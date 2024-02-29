#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// dp[y][x] = dp[y+-1][x+-1]들 중 자신 보다 작은 것들의 경로의 합

struct tPos
{
	int y;
	int x;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(tPos cur, vector<vector<int>>& board, vector<vector<int>>& dp, int ysize, int xsize)
{
	if (dp[cur.y][cur.x] > 0)
		return dp[cur.y][cur.x];
	else if (dp[cur.y][cur.x] == -1)
		return 0;

	int cv = board[cur.y][cur.x];

	bool hasPath = false;
	for(int i = 0; i < 4; ++i)
	{
		tPos nxt = cur;
		nxt.x += dx[i];
		nxt.y += dy[i];
		int nv = board[nxt.y][nxt.x];
		
		if(cv > nv)
		{
			hasPath = true;
			if (nxt.y == ysize && nxt.x == xsize)
				dp[cur.y][cur.x]++;
			else
				dp[cur.y][cur.x] += dfs(nxt, board, dp, ysize, xsize);
		}
	}

	if(hasPath == false)
	{
		dp[cur.y][cur.x] = -1;
		return 0;
	}

	return dp[cur.y][cur.x];
}

int main()
{
	fastio;

	int y, x;
	cin >> y >> x;
	const int INF = 1'000'000'000;
	vector<vector<int>> board(y + 2, vector<int>(x + 2, INF));

	for (int i = 1; i <= y; ++i)
		for (int j = 1; j <= x; ++j)
			cin >> board[i][j];

	vector<vector<int>> dp(y + 2, vector<int>(x + 2, 0));
	tPos cur{ 1,1 };
	cout << dfs(cur, board, dp, y, x);

	return 0;
}


// S : 6:00
// U : 6:02
// T : 6:31
// C :
// Total :