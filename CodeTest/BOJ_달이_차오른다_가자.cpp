#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// bfs
// 되돌아가는 경우 -> 열쇠를 짚었을 경우.(한 번 vistied를 초기화)

struct tPos
{
	int y;
	int x;
};

struct tInfo
{
	int y;
	int x;
	int moveCnt;
	bool keys[6];
};


int selectVisited(bool* keys)
{
	int ret = 0;
	for (int i = 0; i < 6; ++i)
	{
		if(keys[i])
			ret += 1 << i;
	}
	return ret;
}

const tPos dir[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int bfs(tPos startPos, vector<vector<char>>& board, vector<vector<vector<bool>>>& visited)
{
	std::queue<tInfo> q;
	q.push({ startPos.y, startPos.x });
	visited[startPos.y][startPos.x][0] = true;

	while (!q.empty())
	{
		auto curPos = q.front();
		q.pop();

		if (board[curPos.y][curPos.x] == '1')
		{
			return curPos.moveCnt;
		}

		
		for (int i = 0; i < 4; ++i)
		{
			auto tmpPos = curPos;
			tmpPos = curPos;
			tmpPos.y += dir[i].y;
			tmpPos.x += dir[i].x;

			char curBoard = board[tmpPos.y][tmpPos.x];
			if (tmpPos.x <= 0 || tmpPos.x > board[0].size() || tmpPos.y <= 0 || tmpPos.y > board.size()) continue;
			if (curBoard == '#') continue;
			if (curBoard >= 'A' && curBoard <= 'F' && !tmpPos.keys[curBoard - 'A']) continue;
			
			// 키 획득
			if (curBoard >= 'a' && curBoard <= 'f')
			{
				tmpPos.keys[curBoard - 'a'] = true;
			}
			
			if (!visited[tmpPos.y][tmpPos.x][selectVisited(tmpPos.keys)])
			{
				visited[tmpPos.y][tmpPos.x][selectVisited(tmpPos.keys)] = true;
				tmpPos.moveCnt += 1;
				q.push(tmpPos);
			}
		}
	}

	return -1;
}

int main()
{
	fastio;

	// 세로 가로
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N + 2, vector<char>(M + 2, '#'));
	vector<vector<vector<bool>>> visited(N + 2, vector<vector<bool>>(M + 2, vector<bool>(1 << 6, false)));
	tPos startPos;
	for (int i = 1; i <= N; ++i)
	{
		std::string str;
		cin >> str;
		int j = 1;
		for (auto c : str)
		{
			board[i][j] = c;
			if (board[i][j] == '0')
				startPos = { i, j };
			j++;
		}
	}

	cout << bfs(startPos, board, visited);

	return 0;
}


// S : 2:45
// U : 2:45
// T : 2:48
// C : 3:46
// Total :1h 1min