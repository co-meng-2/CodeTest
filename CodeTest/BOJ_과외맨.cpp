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

// ���̳� Ÿ�� 2���� ���ڷ� ����
// N : ���� �� 1 - 500
// Ȧ�� �ٿ��� N���� Ÿ��
// ¦�� �ٿ��� N-1���� Ÿ��
// ���� ������ Ÿ�Ϸ� �̵��Ϸ� ��
// ���� ª�� ��θ� ���
// ������ Ÿ�Ϸ� �� �� ���� ��� ��ȣ�� ���� ū Ÿ�Ϸ� �̵��ϸ� �ȴ�.

// Ÿ�� ����ü ����, L, R, Idx
// ���� Info ����ü ���� ����, Idx
// ���� 1���� �����Ͽ� bfs �����¿�� �̵�, �����ϰų� ���� Ÿ�����϶� 

// ���带 �� �����.
// ���� ������ ���� �� �� �ִ��� BFS�� �Ǵ��ϸ� ���� �����Ѵ�.
// �ٽ� �� �� BFS�� ��θ� �����Ѵ�.

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


		// �����¿�� �����.
		// ���� �ε��� �� ���� ����
		// ���� ������ ��� Q�� Push
		// visited false�� ��쿡��

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