#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 1-5 type의 cctv
// cctv의 감시는 벽을 통과하지 못함
// cctv의 감시는 cctv를 통과할 수 있음
// cctv는 90도 회전 가능
// cctv의 갯수는 8개 이하
// 사각 지대의 최소 크기를 구하라

// dfs로 완전 탐색 -> 4^8 = 2^16 얼마 안되네?
// CCTV 방향 정보 기억

int col, row; // 1-8
int board[10][10]{};

enum TYPE
{
	NONE = 0,
	C1 = 1, // 한 방향
	C2 = 5, // 양 방향
	C3 = 3, // ㄴ자 방향
	C4 = 7, // 세 방향
	C5 = 15, // 네 방향
	WALL = 16,
	DETECT = 17,
};
int arr[7] = { NONE, C1, C2, C3, C4, C5, WALL };

enum DIR
{
	X = 0,
	UP = 1,
	RIGHT = 2,
	DOWN = 4,
	LEFT = 8
};

struct CCTV
{
	int CCcol;
	int CCrow;
	int dir;

	void Rotate()
	{
		int out = 0;
		if (dir & UP)
			out += RIGHT;
		if (dir & RIGHT)
			out += DOWN;
		if (dir & DOWN)
			out += LEFT;
		if (dir & LEFT)
			out += UP;
		dir = out;
	}

	void Detect(int _board[][10])
	{
		if (dir & LEFT)
		{
			int tmpCol = CCcol, tmpRow = CCrow;

			while (tmpRow <= row && _board[tmpCol][tmpRow] != WALL)
			{
				_board[tmpCol][tmpRow] = DETECT;
				tmpRow++;
			}
		}

		if (dir & RIGHT)
		{
			int tmpCol = CCcol, tmpRow = CCrow;

			while (tmpRow >= 1 && _board[tmpCol][tmpRow] != WALL)
			{
				_board[tmpCol][tmpRow] = DETECT;
				tmpRow--;
			}
		}

		if (dir & UP)
		{
			int tmpCol = CCcol, tmpRow = CCrow;

			while (tmpCol >= 1 && _board[tmpCol][tmpRow] != WALL)
			{
				_board[tmpCol][tmpRow] = DETECT;
				tmpCol--;
			}
		}

		if (dir & DOWN)
		{
			int tmpCol = CCcol, tmpRow = CCrow;

			while (tmpCol <= col && _board[tmpCol][tmpRow] != WALL)
			{
				_board[tmpCol][tmpRow] = DETECT;
				tmpCol++;
			}
		}
	}
};
vector<CCTV> vecCCTV;

int ans = 1000000;
void dfs(int _depth)
{
	if(_depth == vecCCTV.size())
	{
		// 8x8
		int tmpBoard[10][10]{};
		for (int i = 1; i <= col; i++)
			for (int j = 1; j <= row; j++)
				tmpBoard[i][j] = board[i][j];

		for (auto& it : vecCCTV)
			it.Detect(tmpBoard);

		int ret = 0;
		for (int i = 1; i <= col; i++)
			for (int j = 1; j <= row; j++)
				if (tmpBoard[i][j] == NONE)
					ret++;

		ans = std::min(ans, ret);
		return;
	}

	for(int i = 0; i < 4; ++i)
	{
		vecCCTV[_depth].Rotate();
		dfs(_depth + 1);
	}
}

int main()
{
	fastio;

	cin >> col >> row;
	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++)
		{
			int tmp;
			cin >> tmp;
			board[i][j] = arr[tmp];
			if (board[i][j] != NONE && board[i][j] != WALL)
				vecCCTV.push_back({ i,j, board[i][j] });
		}
			
	dfs(0);

	cout << ans;
}