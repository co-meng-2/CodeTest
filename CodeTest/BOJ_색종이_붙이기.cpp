#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// dfs backtracking
// 

struct tPos
{
	int y;
	int x;
};

// board
bool check(tPos cur, int n, vector<vector<int>>& board)
{
	for(int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!board[cur.y + i][cur.x + j])
			{
				return false;
			}
		}
	}

	return true;
}


void FillBoard(tPos cur, int n, int num, vector<vector<int>>& board)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[cur.y + i][cur.x + j] = num;
		}
	}
}

void dfs(tPos cur, vector<int>& papercnt, int& ans, int papersum, vector<vector<int>>& board)
{
	// RB로 진행하며 현재 색종이 붙일 수 있는 곳 찾음
	tPos nxt = cur;
	while (board[nxt.y][nxt.x] == 0)
	{
		nxt.x++;
		if (nxt.x > 10)
		{
			nxt.y++;
			nxt.x = 1;
		}
		if (nxt.y > 10)
		{
			ans = std::min(ans, papersum);
			return;
		}
	}

	// 5->1 색종이 붙일 수 있는지 체크하고 붙일 수 있다면 5부터 붙여보면서 dfs진행
	for(int i = 5; i >= 1; i--)
	{
		if(check(nxt, i, board) && papercnt[i] >= 1 && papersum < ans)
		{
			FillBoard(nxt, i, 0, board);
			papercnt[i]--;
			dfs(nxt, papercnt, ans, papersum + 1, board);
			FillBoard(nxt, i, 1, board);
			papercnt[i]++;
		}
	}
}

int main()
{
	fastio;
	const int width = 10;
	vector<vector<int>> board(width + 2, vector<int>(width + 2, 0));
	for(int i = 1; i <= 10; ++i )
		for (int j = 1; j <= 10; ++j)
			cin >> board[i][j];

	tPos cur = { 1,1 };
	vector<int> papercnt(6, 5);

	const int INF = 10000000;
	int ans = INF;
	dfs(cur, papercnt, ans, 0, board);

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}


// S : 5:55
// U : 5:55
// T : 6:05
// C :
// Total :