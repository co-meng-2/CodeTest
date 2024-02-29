#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// ó�� ũ�� 2
// ���� �ֵ� ���� �� ����
// ���� �ִ� ���� �� ����
// ���� �� ������ ���� ����
// �Ÿ��� ���� ����� -> ���� �� -> ���� �� �켱����
// �ڽ��� ũ��� ���� ���� ����⸦ ���������� ũ�� 1 ����
// ������� �θ������� �������� 
// BFS �������� Ǯ��

struct tPos
{
	int y;
	int x;
	int dist;
};

enum DIR
{
	DOWN,
	UP,
	RIGHT,
	LEFT
};
tPos dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int main()
{
	fastio;

	int N;
	cin >> N;
	const int INF = 10000000;
	tPos start;
	int scale = 2;
	vector<vector<int>> board(N + 2, vector<int>(N + 2, INF));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				board[i][j] = 0;
				start = { i,j,0 };
			}
		}
	
	int time = 0;
	int eatcnt = 0;
	while (true)
	{
		vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
		std::queue<tPos> q;
		q.push(start);
		visited[start.y][start.x] = true;
		vector<tPos> eats;
		int maxDist = INF;
		
		
		while (!q.empty())
		{
			auto [cury,curx, curd] = q.front();
			q.pop();


			for (int i = 0; i < 4; ++i)
			{
				int nxtx = curx + dir[i].x;
				int nxty = cury + dir[i].y;
				int nxtd = curd + 1;
				//int dist = std::abs(start.x - nxtx) + std::abs(start.y - nxty);
				
				if (visited[nxty][nxtx])
					continue;
				visited[nxty][nxtx] = true;

				if (board[nxty][nxtx] <= scale && nxtd <= maxDist)
				{
					if (board[nxty][nxtx] < scale && board[nxty][nxtx] != 0)
					{
						maxDist = nxtd;
						eats.push_back({nxty, nxtx, nxtd });
					}
					else
					{
						q.push({ nxty,nxtx,nxtd });
					}
				}
			}
		}
		if (eats.empty())
			break;
		vector<tPos> up;
		int minY = INF;
		for (auto it : eats)
		{
			if (minY > it.y)
			{
				up.clear();
				up.push_back(it);
				minY = it.y;
			}
			else if (minY == it.y)
			{
				up.push_back(it);
			}
		}
		tPos eat;
		if (up.size() == 1)
			eat = up[0];
		else
		{
			if (up[0].x < up[1].x)
				eat = up[0];
			else
				eat = up[1];
		}
		board[eat.y][eat.x] = 0;
		start = eat;
		start.dist = 0;
		time += maxDist;
		eatcnt++;
		if (eatcnt == scale)
		{
			eatcnt = 0;
			scale++;
		}
	}

	cout << time;

	return 0;
}


// S : 1148
// U : 1151
// T : 1151
// C :  103
// Total : 75