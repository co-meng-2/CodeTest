#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>

#include <queue>
using std::queue;

int board[1001][1001]{};

// LCS 길이와 경로를 출력하라

// 같지 않을 경우 -> 위 좌 에서 더 큰 것
// 같은 경우 -> 좌상 + 1

// 경로 -> LCS 마지막에서부터 좌상이 현재 - 1 인 경우를 계속 찾아감.

struct tPos
{
	int y;
	int x;
};

int main()
{
	fastio;

	string s1, s2;
	cin >> s1 >> s2;

	// LCS length
	for (int i = 1; i <= s1.length(); ++i)
	{
		for (int j = 1; j <= s2.length(); ++j)
		{
			if (s1[i-1] == s2[j-1])
				board[i][j] = board[i - 1][j - 1] + 1;
			else
				board[i][j] = std::max(board[i - 1][j], board[i][j - 1]);
		}
	}

	// LCS Path
	int s1l = (int)s1.length();
	int s2l = (int)s2.length();
	tPos cur = { s1l, s2l };
	string LCSPath;
	while (true)
	{
		while (board[cur.y][cur.x - 1] == board[cur.y][cur.x])
			cur.x--;
		while (board[cur.y - 1][cur.x] == board[cur.y][cur.x])
			cur.y--;

		LCSPath.push_back(s1[cur.y - 1]);
		cur.x--;
		cur.y--;
		if (board[cur.y][cur.x] == 0) break;
	}

	string LCSRPath;
	for (int i = 0; i < LCSPath.length(); ++i)
		LCSRPath.push_back(LCSPath[LCSPath.length() - 1 - i]);

	cout << board[s1l][s2l];
	if(board[s1l][s2l])
		cout <<"\n" << LCSRPath;

	return 0;
}

// T : 9 min
// C : 38 min
// Total : 47 min
