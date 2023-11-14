#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

enum ePoint
{
	CENTER = 24,
	START = 0,
	END = 21,
};

struct tElem
{
	int wayRed = -1;
	int wayBlue = -1;
	int score = -1;
};

int max = -1;
void dfs(int depth, int score, vector<int>& nums, vector<int> curPos, vector<tElem>& board)
{
	if (depth == 10)
	{
		max = std::max(max, score);
		return;
	}

	// 1 ~ 4 번말 움직이기
	for (int i = 0; i < 4; ++i)
	{
		int savePos = curPos[i];
		bool bValid = true;
		for (int j = 0; j < nums[depth]; ++j)
		{
			tElem curElem = board[curPos[i]];
			if (curPos[i] == END)
			{
				if (j == 0) bValid = false;
				break;
			}
				
			if (j == 0 && curElem.wayBlue != -1)
			{
				curPos[i] = curElem.wayBlue;
			}
			else
			{
				curPos[i] = curElem.wayRed;
			}
		}

		for (int j = 0; j < 4; ++j)
		{
			if (i == j) continue;
			if (curPos[i] == curPos[j] && curPos[i] != END)
				bValid = false;
		}

		if (bValid)
		{
			score += board[curPos[i]].score;
			dfs(depth + 1, score, nums, curPos, board);
			score -= board[curPos[i]].score;
		}
		curPos[i] = savePos;
	}
}

int main()
{
	fastio;

	vector<int> nums(10);
	for (auto& num : nums)
	{
		cin >> num;
	}

	vector<tElem> board(33);

	for (int i = 0; i <= 20; ++i)
	{
		board[i].wayRed = i+1;
		board[i].wayBlue = -1;
		board[i].score = i*2;
	}

	// end
	board[21].score = 0;

	// 세로줄
	board[22].wayRed = 23;
	board[22].score = 22;
	board[23].wayRed = 24;
	board[23].score = 24;
	board[24].wayRed = 25;
	board[24].score = 25;
	board[25].wayRed = 26;
	board[25].score = 30;
	board[26].wayRed = 20;
	board[26].score = 35;

	// 가로줄 왼
	board[27].wayRed = 28;
	board[27].score = 13;
	board[28].wayRed = 29;
	board[28].score = 16;
	board[29].wayRed = 24;
	board[29].score = 19;
	
	// 가로줄 우
	board[30].wayRed = 31;
	board[30].score = 28;
	board[31].wayRed = 32;
	board[31].score = 27;
	board[32].wayRed = 24;
	board[32].score = 26;

	// 파란선
	board[5].wayBlue = 27;
	board[10].wayBlue = 22;
	board[15].wayBlue = 30;

	vector<int> curPos(4, 0);

	dfs(0, 0, nums, curPos, board);
	cout << max;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :