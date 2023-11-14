#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

#include <functional>

// 도미노 타일 2개의 숫자로 구성
// N : 행의 수 1 - 500
// 홀수 줄에는 N개의 타일
// 짝수 줄에는 N-1개의 타일
// 가장 마지막 타일로 이동하려 함
// 가장 짧은 경로를 출력
// 마지막 타일로 갈 수 없는 경우 번호가 가장 큰 타일로 이동하면 된다.

// 타일 구조체 정의, L, R, Idx
// 보드 Info 구조체 정의 숫자, Idx
// 보드 1부터 시작하여 bfs 상하좌우로 이동, 인접하거나 같은 타일위일때 

// 보드를 잘 만든다.
// 먼저 끝까지 도달 할 수 있는지 BFS로 판단하며 길을 갱신한다.
// 다시 한 번 BFS로 경로를 갱신한다.

struct tPos
{
	int y;
	int x;
};

struct tTile
{
	int L;
	int R;
	int idx;
};

struct tInfo
{
	int num = 0;
	int idx = 0;
};

struct tVisited
{
	bool visited = false;
	int prevIdx = -1;
};

tInfo board[502][1002];

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<tTile> vecTile;
	for(int i = 1; i <= N*N-N/2; ++i)
	{
		int L, R;
		cin >> L >> R;
		vecTile.push_back({L, R, i});
	}

	vector<vector<tPos>> vecPos(N*N-N/2 + 1);
	int tileIdx = 0;
	for(int i = 1; i <= N; ++i)
	{
		int cnt = N;
		int start = 1;
		if (i % 2 == 0)
		{
			start++;
			cnt--;
		}

		for(int j = 1; j <= cnt; ++j )
		{
			board[i][start].num = vecTile[tileIdx].L;
			board[i][start].idx = vecTile[tileIdx].idx;
			board[i][start+1].num = vecTile[tileIdx].R;
			board[i][start+1].idx = vecTile[tileIdx].idx;
			vecPos[tileIdx+1].push_back({ i, start });
			vecPos[tileIdx+1].push_back({ i, start + 1 });
			start += 2;
			tileIdx++;
		}
	}
	

	std::queue<int> Q;
	vector<tVisited> visited(N * N - N / 2 + 1);

	Q.push(1);
	visited[1] = { true, -1 };

	int maxIdx = 1;
	while(!Q.empty())
	{
		auto front = Q.front();
		Q.pop();


		// 상하좌우로 뻗어간다.
		// 같은 인덱스 일 경우는 무시
		// 같은 숫자일 경우 Q에 Push
		// visited false일 경우에만

		const static tPos dir[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
		for(int i = 0; i <=1; ++i)
		{
			tPos curPos = vecPos[front][i];
			for(int j = 0; j <4; ++j)
			{
				tPos nextPos = curPos;
				nextPos.x += dir[j].x;
				nextPos.y += dir[j].y;

				auto curBoard = board[curPos.y][curPos.x];
				auto nextBoard = board[nextPos.y][nextPos.x];

				if(visited[nextBoard.idx].visited == false && curBoard.idx != nextBoard.idx && curBoard.num == nextBoard.num)
				{
					visited[nextBoard.idx].visited = true;
					visited[nextBoard.idx].prevIdx = curBoard.idx;
					Q.push(nextBoard.idx);
					maxIdx = std::max(maxIdx, nextBoard.idx);
				}
			}
		}
	}

	int curIdx = maxIdx;
	vector<int> path;
	path.push_back(curIdx);
	while(visited[curIdx].prevIdx != -1)
	{
		path.push_back(visited[curIdx].prevIdx);
		curIdx = visited[curIdx].prevIdx;
	}

	cout << path.size() << "\n";
	for(auto it = path.rbegin(); it != path.rend(); ++it)
	{
		cout << *it << " ";
	}

	return 0;
}

// S : 3:45
// U : 3:48
// T : 4:02