#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// ���带 2���� ���ͷ� ����
// CCTV�� �ִ� 8���� �ִ� 4�� ȸ�� -> 4^8�� -> 2^16�� 65536�� Ž���� ����
// Ž���� ���� ũ��� �ִ�� �����غ��� 14���� ���� �ʴ´� -> ���� 100���̶�� ����
// ��ȣ�� ���� ������ (1, 0) (0, 1) (-1, 0) (0, -1)�� �����ϰ� �̿� ���� ���� ȸ�� �Լ��� ������༭ Ǯ�� �ɵ�.

struct point
{
	int col;
	int row;
};

// �־��� CCTV��ġ�� ������ ���� ���� ����
void progress(point cur, point dir, vector<vector<int>>& board)
{
	cur.col += dir.col;
	cur.row += dir.row;
	while (board[cur.col][cur.row] != 6)
	{
		int& curBoard = board[cur.col][cur.row];
		if (curBoard == 0)
			board[cur.col][cur.row] = 7;
		cur.col += dir.col;
		cur.row += dir.row;
	}
}

// ���� ������
void rotate(point& dir)
{
	if (dir.col == 1) { dir.row = -1; dir.col = 0; }
	else if (dir.row == -1) { dir.col = -1; dir.row = 0; }
	else if (dir.col == -1) { dir.row = 1; dir.col = 0; }
	else if (dir.row == 1) { dir.col = 1; dir.row = 0; }
}

#define UP point{ -1, 0 }
#define RIGHT point{ 0,1 }
#define DOWN point{ 1,0 }
#define LEFT point{ 0,-1 }

// dfs�� ������ CCTV ��� ���⿡ ���� �ּ��� �簢���� ã��.
void solve(int cur, int& min, vector<point>& cctvs, vector<vector<int>>& board)
{
	if (cur >= cctvs.size())
	{
		int cnt = 0;
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == 0)
					cnt++;
			}
		}
		min = std::min(min, cnt);
		return;
	}

	int curBoard = board[cctvs[cur].col][cctvs[cur].row];
	vector<point> dirs;
	if (curBoard == 1)
	{
		dirs.push_back(UP);
	}
	else if (curBoard == 2)
	{
		dirs.push_back(UP);
		dirs.push_back(DOWN);
	}
	else if (curBoard == 3)
	{
		dirs.push_back(UP);
		dirs.push_back(RIGHT);
	}
	else if (curBoard == 4)
	{
		dirs.push_back(UP);
		dirs.push_back(RIGHT);
		dirs.push_back(DOWN);
	}
	else if (curBoard == 5)
	{
		dirs.push_back(UP);
		dirs.push_back(RIGHT);
		dirs.push_back(DOWN);
		dirs.push_back(LEFT);
	}


	for (int i = 0; i < 4; ++i)
	{
		auto tmpBoard = board;
		for (auto& dir : dirs)
		{
			rotate(dir);
			// ���� �ٲ���
			progress(cctvs[cur], dir, board);
		}
		
		solve(cur + 1, min, cctvs, board);
		board = tmpBoard;
	}
}

int main()
{
	fastio;
	
	int col, row;
	cin >> col >> row;
	col += 2;
	row += 2;

	vector<vector<int>> board(col, vector<int>(row, 6));
	vector<point> cctvs;
	for (int i = 1; i < col - 1; ++i)
	{
		for (int j = 1; j < row - 1; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6)
				cctvs.push_back({i, j});
		}
	}
	
	int min = 10000000;
	solve(0, min, cctvs, board);
	cout << min;

	return 0;
}


// S : 1:29
// U : 1:30
// T : 1:34
// C : 2:39
// Total : 1h 10min